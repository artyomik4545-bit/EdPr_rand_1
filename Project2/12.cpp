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

int main()
{
    srand(time(NULL));
    test();
}
