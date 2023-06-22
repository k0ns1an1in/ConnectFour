#include "VertikalerBot.hpp"
#include <iostream>

int feld[42] = {0};

int main()
{
    for (int j = 0; j < 22; j++)
    {
        feld[j] = j + 1;
    }

    for (int k = 0; k < 6; k++)
    {
        for (int l = 0; l < 7; l++)
        {
            std::cout << *(feld + l + 7 * k) << " ";
        }
        std::cout << std::endl;
    }

    VertikalerBot bot = VertikalerBot(feld);
    int a = bot.zug_zeile();
    std::cout << a << std::endl;
}
