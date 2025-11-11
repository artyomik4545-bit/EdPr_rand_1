#include <iostream>
#include <vector>
using namespace std;
#include <Windows.h>

struct location_
{
    string name;
    string inf;
};

struct hero_
{
    string name;
    int dmg;
    int hp;
    int current_loc;
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

    loc[0].name = "лес";
    loc[0].inf = "темный";

    loc[1].name = "подземелье";
    loc[1].inf = "душно";

    loc[2].name = "деревня";
    loc[2].inf = "разрушенная";

    Hero.name = "рыцарь";
    Hero.dmg = 2;
    Hero.hp = 16;
    Hero.current_loc = 0;
   
    Enemy.name = "гоблин";
    Enemy.dmg = 2;
    Enemy.hp = 5;
    Enemy.current_loc = 1;

    for (int i = 0; i < 3; i++)
    {
        cout << i << "\t" << loc[i].name<< "\n";
    }
    int choice;
    
    while (true)
    {

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
                    Enemy.hp -= Hero.dmg;
                    cout << "вы ударили противника мечом" << "\n";
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
                    cout << "противник повержен";
                }
                else if (Hero.hp < 1)
                {
                    cout << "вы погибли";
                }
            }
        }
    }


}
