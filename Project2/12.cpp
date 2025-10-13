#include <iostream>

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

int main()
{
    srand(time(NULL));
    //test();
    //suefa();
    game();
}
