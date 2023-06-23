#include "VertikalerBot.hpp"
#include "HorizontalerBot.hpp"
#include "ZufallsBot.hpp"
#include <iostream>

int feld[42] = {0};

int main()
{
    for (int j = 0; j < 22; j++)
    {
        feld[j] = j + 1;
    }
    feld[22] = 22 + 1;
    feld[29] = 29 + 1;
    feld[25] = 25 + 1;
    feld[32] = 32 + 1;
    feld[39] = 39 + 1;

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
    HorizontalerBot bot2 = HorizontalerBot(feld);
    a = bot2.zug_zeile();
    std::cout << a << std::endl;
    ZufallsBot bot3 = ZufallsBot(feld);
    for (size_t i = 0; i < 100; i++)
    {
        a = bot3.zug_zeile();
        std::cout << a << std::endl;
    }
}
