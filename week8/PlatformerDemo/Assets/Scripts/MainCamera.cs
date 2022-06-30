using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MainCamera : MonoBehaviour
{
    public float speed;
    public float aheadDist;
    public float minX;
    public float maxX;
    public Transform player;
    float lookAhead;
    float camX;
    Vector3 velocity = Vector3.zero;

    void Update()
    {
        lookAhead = Mathf.Lerp(lookAhead, (aheadDist * player.localScale.x), Time.deltaTime * speed);
        camX = player.position.x + lookAhead;
        if (camX < minX)
            camX = minX;
        if (camX > maxX)
            camX = maxX;
        transform.position = new Vector3(camX, transform.position.y, transform.position.z);
    }
}
