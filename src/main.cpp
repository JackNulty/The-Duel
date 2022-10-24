#include <iostream>

using namespace std;

class GameObject {
public:
    void flip() { cout << "I know how to flip and I will flipping do it" << endl; }
    virtual void walk() { cout << "just in case they are too young to walk yet" << endl; }
    virtual void fly() = 0; //pure virtual function
};

class Player : public GameObject {
public:
    void barrelRoll() { cout << "rooooooolllllllllllinggggggg" << endl; }
    void walk() { cout << "Doopers have a really cool walk!" << endl; }
    void fly() { cout << "Dooper is flapping and flying" << endl; }
};

class Boss : public GameObject{
public:
    void fly() { cout << "Average Dooper is flapping and flying" << endl; }
};

int main(void)
{
  cout << "Let go virtual" << endl;
  //GameObject gameObject;
  //gameObject.flip();
  //gameObject.walk();

  cout << "Let go create an Orc" << endl;
  Player player;
  player.walk();
  player.fly();
  player.flip();

  cout << "Let go create an Troll" << endl;
  Boss boss;
  boss.walk();
  boss.fly();
  troll.flip();

  GameObject* npc = &player;
  npc->flip();
  npc->fly();
  npc->walk();

  npc = &boss;
  npc->flip();
  npc->fly();
  npc->walk();

  cin.get();
}