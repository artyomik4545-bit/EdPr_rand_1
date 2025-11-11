#include <iostream>
#include <vector>
using namespace std;

struct product_ {
    string name;
    int count;
    int price;

    void test() {

        int bot = 1 + rand() % 3;
        int a = 0;
        int i = 0;
        while (i < 5)
        {
            std::cout << bot << std::endl;
            std::cin >> a;
            if (a == bot)
            {
                std::cout << "WIN" << std::endl;
                bot = 1 + rand() % 3;
                /*while (bot == a)
                {
                    bot = rand() % 5 + 1;
                }*/
                i++;
            }
            else
            {
                std::cout << "LOSE" << std::endl;
            }

        }

    }


};

product_ l;
vector<product_> shop;
vector<product_> basket;

string chname;
int chcount;
int chmoney = 3000;
int hn = 0;
int id = 0;
double change = 0;

void assort()
{
    for (int i = 0; i < shop.size(); i++) {


        cout << shop[i].name << "\t" << shop[i].count << "\t" << shop[i].price << endl;


    }
}

void item(string choice) {
    if (choice == "b")
    {
        cout << endl;
        cout << "basket\n";
        for (int i = 0; i < size(basket); i++)
        {
            cout << basket[i].name << "\t" << basket[i].count << "\t" << basket[i].price << endl;
        }
        cout << endl;
    }
}

void choice()
{
    for (int i = 0; i < shop.size(); i++)
    {
        if (chname == shop[i].name)
        {

            id = i;

            cout << "\nchoose number of products or press b for open basket\n";
            cin >> chcount;
            change = chmoney - chcount * shop[id].price;

            if (shop[id].count < chcount)
            {
                cout << "\nnot enough products in the shop\n" << shop[id].count;
            }
            else if (change >= 0)
            {
                cout << "\nyour change: " << change << endl;
            }
            else if (change < 0)
            {
                cout << "\nnot enough: \n" << abs(change) << endl;
            }


            if (chmoney > 0 && shop[id].count >= chcount)
            {
                chmoney = change;
                shop[id].count = shop[id].count - chcount;
            }

            if (basket.empty())
            {
                basket.push_back({ shop[id].name, chcount, shop[id].price });
            }
            else
            {
                for (int p = 0; p < basket.size(); p++)
                {
                    if (shop[id].name == basket[p].name)
                    {
                        basket[p].count = basket[p].count + chcount;
                    }
                    else
                    {
                        basket.push_back({ shop[id].name, chcount, shop[id].price });
                    }
                }
            }


        }

    }
}

int main()
{

    shop.push_back({ "banana", 2, 110 });
    shop.push_back({ "apple", 20, 150 });
    shop.push_back({ "tomato", 15, 200 });
    shop.push_back({ "chees", 0, 300 });

    while (true) 
    {

        assort();
        cout << "your money: " << chmoney << std::endl;
        cout << "\nchoose name\n";
        cin >> chname;

        item(chname);

        choice();
    }
}
