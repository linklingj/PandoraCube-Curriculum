using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerMovement : MonoBehaviour
{
    public float moveSpeed;
    public float acceration;
    public float decceleration;
    public float jumpForce;
    public Transform groundCheck;
    public Text coinUI;
    public LayerMask groundLayer;
    public Transform coins;
    static Vector2 groundCheckSize = new Vector2(0.3f,0.15f);
    bool jumpKey = false;
    float moveInput;
    bool grounded;
    bool isJumping;
    bool facingRight = true;
    int coin = 0;
    Vector3 startingPos = new Vector3(0,-1.5f,0);
    private Rigidbody2D rb;
    public Animator animator;
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        transform.position = startingPos;
        coin = 0;
    }
    void Update()
    {
        if(Input.GetKeyDown("space")) {
            jumpKey = true;
        }
        moveInput = Input.GetAxisRaw("Horizontal");
        if ((moveInput > 0 && !facingRight) || (moveInput < 0 && facingRight))
            Flip();
        animator.SetFloat("speed",Mathf.Abs(moveInput));
        animator.SetBool("isJumping",isJumping);
    }
    void FixedUpdate() {
        if (Physics2D.OverlapBox(groundCheck.position, groundCheckSize, 0 , groundLayer)) {
            grounded = true;
            isJumping = false;
        }
        else
            grounded = false;
        if(grounded && jumpKey) {
            jumpKey = false;
            isJumping = true;
            Jump();
        }
        MoveSide();
        if (transform.position.y < -5.5f) {
            ResetGame();
        }
    }
    void MoveSide() {
        float targetSpeed = moveInput * moveSpeed;
        float speedDif = targetSpeed - rb.velocity.x;
        float accelRate = (Mathf.Abs(targetSpeed) > 0.01f)? acceration : decceleration;
        float movement = Mathf.Pow(Mathf.Abs(speedDif) * accelRate, 2) * Mathf.Sign(speedDif);
        rb.AddForce(movement * Vector2.right);
    }
    void Jump() {
        rb.AddForce(Vector2.up * jumpForce, ForceMode2D.Impulse);
    }
    void Flip() {
        facingRight = !facingRight;
        Vector3 newScale = transform.localScale;
        newScale.x *= -1;
        transform.localScale = newScale;
    }
    void ResetGame() {
        transform.position = startingPos;
        coin = 0;
        foreach (Transform coin in coins)
        {
            coin.gameObject.SetActive(true);
        }
        coinUI.text = "0";
    }
    private void OnTriggerEnter2D(Collider2D col) {
        if (col.gameObject.CompareTag("flag")) {
            ResetGame();
        }
        if (col.gameObject.CompareTag("gem")) {
            coin++;
            col.gameObject.SetActive(false);
            coinUI.text = coin.ToString();
        }
    }
}
