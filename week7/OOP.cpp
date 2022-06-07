#include <iostream>

using namespace std;

class GameObject {
protected: 
    string Type;
    string Name;
    int Lvl;
    int HP;
    int MaxHP;
    int Power;
public:
    GameObject(string type, string name, int lvl, int hp, int maxHP, int power) {
        Type = type;
        Name = name;
        Lvl = lvl;
        HP = hp;
        MaxHP = maxHP;
        Power = power;
    }
    void HPSetter(int health) {
        HP = health;
    }
};

class Player: GameObject {
public:
    Player(string type, string name, int lvl, int hp, int maxHP, int power):GameObject(type,name,lvl,hp,maxHP,power) {
        if (hp > maxHP)
            HPSetter(maxHP);
    }
    void levelUp() {
        Lvl++;
        cout << "level up! LV. " << Lvl << endl;
    }
    void heal() {
        HP = MaxHP;
        cout << Name << " is now " << HP << "hp" << endl;
    }
    int powerGetter() {
        return Power;
    }
    void printInfo() {
        cout << "name : " << Name << endl;
        cout << "job : " << Type << endl;
        cout << "level : " << Lvl << endl;
        cout << "health : " << HP << " / " << MaxHP << endl;
        cout << "power : " << Power << endl;
    }
};

class Monster: GameObject {
public:
    Monster(string type, string name, int lvl, int hp, int maxHP, int power):GameObject(type,name,lvl,hp,maxHP,power) {
        if (hp > maxHP)
            HPSetter(maxHP);
    }
    string nameGetter() {
        return Name;
    }
    void damage(int dmg) {
        HP -= dmg;
        if (HP <= 0)
            cout << Name << " is dead!" << endl;
    }
};

int main() {
    string type,name;
    int lvl,hp,maxHP,power;
    cin >> name >> type >> lvl >> hp >> maxHP >> power;
    Player p = Player(type,name,lvl,hp,maxHP,power);
    cin >> name >> type >> lvl >> hp >> maxHP >> power;
    Monster m = Monster(type,name,lvl,hp,maxHP,power);
    while (1) {
        cout << "0: heal\n1: attack!\n2: level up\n3: print player info\n4: end\n";
        int n;
        cin >> n;
        if (n == 0) {
            p.heal();
        }
        if (n == 1) {
            cout << p.powerGetter() << " damage to " << m.nameGetter() << endl;
            m.damage(p.powerGetter());
        }
        if (n == 2) {
            p.levelUp();
        }
        if (n == 3) {
            p.printInfo();
        }
        if (n == 4) {
            cout << "ended" << endl;
            break;
        }
    }
}