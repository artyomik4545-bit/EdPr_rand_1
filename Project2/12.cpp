#include <iostream>

int main()
{
    srand(time(NULL));
    int bot = rand() % 5 + 1;
    int a = 0;
    while (bot != a)
    {
        std::cin >> a;
        if (a == bot)
        {
            std::cout << "WIN" << std::endl;
            bot = rand() % 5 + 1;
            while (bot == a)
            {
                bot = rand() % 5 + 1;
            }
        }
        else
        {
            std::cout << "LOSE" << std::endl;
        }
    }
}
