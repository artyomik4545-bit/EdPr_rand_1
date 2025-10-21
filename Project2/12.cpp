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

void game()
{
    for (int i = 0; i < 3; i++)
    {
        int bot = rand() % 3;
        std::string words[3]{ "rock", "scissors", "paper" };
        std::cout << words[bot] << std::endl;
        std::string uword;
        std::cin >> uword;

        if (uword == "rock" && words[bot] == "scissors" ||
            uword == "scissors" && words[bot] == "paper" ||
            uword == "paper" && words[bot] == "rock")
        {
            std::cout << "WIN" << std::endl;
        }
        else if (uword == words[bot])
        {
            std::cout << "DRAW" << std::endl;
        }
        else
        {
            std::cout << "LOSE" << std::endl;
        }
    }
}




void suefa()
{

    int bot = rand() % 3 + 1;
    int a = 0;
    std::cout << bot << std::endl;
    std::cin >> a;

    if (a == 1 && bot == 2 ||
        a == 2 && bot == 3 ||
        a == 3 && bot == 1)
    {
        std::cout << "WIN" << std::endl;
    }
    else if (a == bot)
    {
        std::cout << "DRAW" << std::endl;
    }
    else
    {
        std::cout << "LOSE" << std::endl;
    }
}

int numbers[5]{ 7,5,-1,3,-7 };
int sisi = size(numbers);

void otr()
{


    for (int i = 0; i < std::size(numbers); i++)
    {
        if (numbers[i] < 0)
        {
            std::cout << numbers[i] << std::endl;
        }

    }
}


void inv()
{
    //int numbers[5]{ 7,5,-1,3,-7 };
    for (int i = 0; i < std::size(numbers); i++)
    {
        numbers[i] = -numbers[i];
        std::cout << numbers[i] << std::endl;
    }
}


void repl1()
{
    //int numbers[5]{ 7,5,-1,3,-7 };
    for (int i = 0; i < std::size(numbers); i++)
    {
        numbers[i] = 1;
        std::cout << numbers[i] << std::endl;
    }
}


void repl()
{
    //int numbers[5]{ 7,5,-1,3,-7 };
    for (int i = 0; i < std::size(numbers); i++)
    {
        numbers[i] = i;
        std::cout << numbers[i] << std::endl;
    }
}


void bsort()
{
    

    for (int i = 0; i < sisi - 1; i++)
    {
        for (int j = 0; j < sisi - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                //int t = numbers[j];
                std::swap(numbers[j], numbers[j + 1]);
                //numbers[j] = numbers[j + 1];
                //numbers[j + 1] = t;

            }
        }
    }

    for (int k = 0; k < sisi; k++)
    {
        std::cout << numbers[k] << std::endl;
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

int main()
{
    
    shop.push_back({ "banana", 2, 110 });
    shop.push_back({ "apple", 20, 150 });
    shop.push_back({ "tomato", 15, 200 });
    shop.push_back({ "chees", 0, 300 });
    


    string chname;
    int chcount;
    int chmoney = 3000;
    int hn = 0;
    int id = 0;
    double change = 0;
    

    while (true) {

        for (int i = 0; i < shop.size(); i++) {


            cout << shop[i].name << "\t" << shop[i].count << "\t" << shop[i].price << endl;


        }
        cout << "your money: " << chmoney << std::endl;
        cout << "\nchoose name\n";
        cin >> chname;

        item(chname);

        
       


        for (int i = 0; i < shop.size(); i++)
        {
            if (chname == shop[i].name) {

                id = i;

                    cout << "\nchoose number of products\n";
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
    

    //srand(time(NULL));
    //l.test();
    //l.name = "banana";
    //cout << l.name;
}
