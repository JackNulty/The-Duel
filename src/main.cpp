#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <string>

using namespace std;

class GameObject {
public:
    int health = 100;
    bool alive = true;
    int potentialDmg;
    int critChance;
    virtual void introMsg(){
        cout << "Welcome" << "\n";
    }
    bool calcCrit(int t_critChance){
        int crit;
        bool critBool = false;
        crit = rand() % 100 + 1;
        if (crit > 0 && crit < t_critChance)
            critBool = true;
        return critBool;
    }
};

class Player : public GameObject {
public:
    void introMsg(){
        cout <<"The Player has entered the arena and is ready to fight the boss" << "\n";
    }
    string pickWeapon(int t_choice)
    {
        string answer;
        if (t_choice == 1)
        {
            answer = "Fist";
        }
        else if (t_choice == 2)
        {
            answer = "Shank";
        }
        else if (t_choice == 3)
        {
            answer = "Blunt";
        }
        else {
            answer = "No valid input given";
        }
        return answer;
    };
    bool armed;
    void isArmed()
    {
        if(armed){
            armed = false;
            //cout << "test false";
        }
        else{
            armed = true;
            //cout << "test true";
        }
        
    }
};

class Enemy : public GameObject{
public:
    void introMsg(){
        cout << "The Boss has challenged the player to a DUEL get ready to fight" << "\n";
    }
    string randomAttack(){
        int random;
        string attack;
        random = rand() % 3 + 1;
        if (random == 1)
        attack = "Fist";
        else if (random == 2)
        attack = "Shank";
        else if (random == 3)
        attack = "Blunt";
        return attack;
    }
};

int main(void)
{
    cout <<"\n";
    cout << "--------------------------------------------------------------" << "\n";
    cout << "                          THE DUEL " << "\n";
    cout << "                       by Jack Nulty" << "\n";
    cout << "             Pick an attack and beat the bossman" << "\n";
    cout << "--------------------------------------------------------------" << "\n";
    cout << "\n";

    Player player1;
    Enemy bossMan; 
    int choice;
    int* healthCounterPlayer = &player1.health;
    int* healthCounterEnemy = &bossMan.health;

    while (player1.alive == true && bossMan.alive == true)
    {
        cout << "------------Do you want to being / continue the fight to the death------------" << "\n";
        cout << "--------------------------- 1 for YES and 2 for NO----------------------------" << "\n";
        cin >> choice;
        if(choice == 1)
        {
            int weaponChoice;
            string EnemyAttack;
            player1.isArmed();
            player1.introMsg();
            bossMan.introMsg();
            cout << "--------Time to choose weapon of choice--------" << "\n";
            cout << "======= 1 for Fists --Does low dmg but has a high crit chance-- =======" << "\n";
            cout << "======= 2 for Shank --Does high dmg but has a low crit chance-- =======" << "\n";
            cout << "======= 3 for Blunt --Does very low dmg but has the highest crit chance-- =======" << "\n";
            cin >> weaponChoice;
            if(player1.pickWeapon(weaponChoice) == "Fist")
            {
                player1.potentialDmg = 15;
                player1.critChance = 35;
                cout << "fist test" << "\n";
            }
            else if(player1.pickWeapon(weaponChoice) == "Shank")
            {
                player1.potentialDmg = 30;
                player1.critChance = 5;
                cout << "shank test" << "\n";
            }
            else if(player1.pickWeapon(weaponChoice) == "Blunt")
            {
                player1.potentialDmg = 5;
                player1.critChance = 75;
                cout << "blunt test" << "\n";
            }
        	
            if (bossMan.randomAttack() == "Fist")
            {
                bossMan.potentialDmg = 15;
                bossMan.critChance = 35;
                EnemyAttack = "Fist";
                cout << "boss fist" << "\n";
            }
            else if(bossMan.randomAttack() == "Shank")
            {
                bossMan.potentialDmg = 30;
                bossMan.critChance = 5;
                EnemyAttack = "Shank";
                cout << "boss shank" << "\n";
            }
            else if(bossMan.randomAttack() == "Blunt")
            {
                bossMan.potentialDmg = 5;
                bossMan.critChance = 75;
                EnemyAttack = "Blunt";
                cout << "boss Blunt" << "\n";
            }

            cout << "============The Enemy is using the attack: " + EnemyAttack + "============"<< "\n";

            if (player1.calcCrit(player1.critChance) == true)
            {
                bossMan.health = bossMan.health - (player1.potentialDmg * 3);
            }
            else
            bossMan.health = bossMan.health - player1.potentialDmg;

            if (bossMan.calcCrit(bossMan.critChance) == true)
            {
                player1.health = player1.health - (bossMan.potentialDmg * 3);
            }
            player1.health = player1.health - bossMan.potentialDmg;
          
            cout << "========== Your current health is: " + to_string(*healthCounterPlayer) + "==========" << "\n";
            cout << "========== Boss current health is: " + to_string(*healthCounterEnemy) + "==========" << "\n";

            if(player1.health <= 0)
            {
                player1.alive = false;
            }
            if(bossMan.health <= 0)
            {
                bossMan.alive = false;
            }
        }
        else{
            break;
        }

    }
    if(player1.alive == false)
    {
        cout << "-----------------------------------------------------------------------------------" << "\n";
        cout << "=========You have lost the biggest fight of your life you have now decesed=========" << "\n";
        cout << "-----------------------------------------------------------------------------------" << "\n";
    }
    else if (bossMan.alive == false)
    {
        cout << "-----------------------------------------------------------------------------------------------------" << "\n";
        cout << "=========You have defeated the enemy you have become the Master grand champion of Boggers HQ=========" << "\n";
        cout << "-----------------------------------------------------------------------------------------------------" << "\n";
    }
}