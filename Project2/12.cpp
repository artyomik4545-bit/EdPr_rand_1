#include <iostream>
#include <vector>
using namespace std;
#include <Windows.h>

struct item_
{
    string name;
};

struct weapon_ : item_
{
    int dmg;
};
struct shield_ : item_
{
    int def;
    int dmg;
};
struct food_ : item_
{
    int heal;
};


struct location_
{
    string name;
    string inf;
    vector<item_> item;
};



struct hero_
{
    string name;
    int dmg;
    int hp;
    int current_loc;
    vector<item_> inventory;
};

struct enemy_
{
    string name;
    int dmg;
    int hp;
    int current_loc;
};

location_ loc[3];
hero_ Hero;
enemy_ Enemy;


int main()
{

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    weapon_ sword1 = weapon_();
    sword1.name = "меч";
    sword1.dmg = 4;

    weapon_ sword2 = weapon_();
    sword2.name = "экскалибур";
    sword2.dmg = 1000;

    weapon_ sword3 = weapon_();
    sword3.name = "булава";
    sword3.dmg = 8;



    loc[0].name = "лес";
    loc[0].inf = "темный";
    loc[0].item.push_back(sword2);

    loc[1].name = "подземелье";
    loc[1].inf = "душно";
    

    loc[2].name = "деревня";
    loc[2].inf = "разрушенная";

    Hero.name = "рыцарь";
    Hero.dmg = 2;
    Hero.hp = 16;
    Hero.current_loc = 0;
    Hero.inventory.push_back(sword1);
    Hero.inventory.push_back(sword3);


        
    Enemy.name = "гоблин";
    Enemy.dmg = 2;
    Enemy.hp = 20;
    Enemy.current_loc = 1;

    
    int choice;
    
    while (true)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << i << "\t" << loc[i].name << "\n";
        }
        cin >> choice;

        for (int i = 0; i < 3; i++)
        {
            if (choice == i)
            {
                cout << loc[i].name << "\n";
                cout << loc[i].inf << "\n";
                Hero.current_loc = choice;
            }

        }

        if (Hero.current_loc == Enemy.current_loc)
        {
            cout << "вы встретили врага" << "\n";
            while (Hero.hp > 0 and Enemy.hp > 0)
            {

                int choice_attack;
                srand(time(0));
                cin >> choice_attack;

                if (choice_attack == 1)
                {
                    int choice_weapon;
                    cin >> choice_weapon;
                    
                    auto chosen_item = Hero.inventory[choice_weapon];
                    if (typeid(chosen_item) == typeid(weapon_()))
                    {
                        Enemy.hp -= Hero.dmg + chosen_item.dmg;
                        cout << "вы ударили противника оружием " << Hero.inventory[choice_weapon].name << "\t" << Hero.dmg + Hero.inventory[choice_weapon].dmg << "\n" << "HP противника: " << Enemy.hp << "\n";
                    }
                    
                }
                else if (choice_attack == 2)
                {
                    Enemy.hp -= Hero.dmg / 2;
                    cout << "вы ударили противника щитом" << "\n";
                }
                else
                {

                }
                int choice_enemy = rand() % 2;
                if (choice_enemy == 0)
                {
                    Hero.hp -= Enemy.dmg;
                    cout << "противник нанес удар" << "\n";
                }
                else if (choice_enemy == 1)
                {
                    Hero.hp -= Enemy.dmg / 2;
                    cout << "противник промахнулся" << "\n";
                }
                else
                {

                }

                if (Enemy.hp < 1)
                {
                    cout << "противник повержен\n";
                }
                else if (Hero.hp < 1)
                {
                    cout << "вы погибли\n";
                }
            }
        }
        if (loc[choice].item.size() > 0)
        {
            cout << "Предметы на локации: \n";
            for (int i = 0; i < loc[choice].item.size(); i++)
            {
                cout << loc[choice].item[i].name << "\n";
            }
            cout << "Подобрать предметы?\n";
            int choice_pickup;
            cin >> choice_pickup;
            if (choice_pickup == 1)
            {
                cout << "Что подобрать?\n";
                int choice_item;
                cin >> choice_item;
                for (int i = 0; i < loc[choice].item.size(); i++)
                {
                    if (i == choice_item)
                    {
                        Hero.inventory.push_back(loc[choice].item[i]);
                        cout << "Вы подобрали " << loc[choice].item[i].name << "\n";
                    }
                }
            }
        }
        else
        {
            cout << "Предметов на локации нет\n";
        }
    }


}
