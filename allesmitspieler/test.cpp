#include "VertikalerBot.hpp"
#include "HorizontalerBot.hpp"
#include "ZufallsBot.hpp"
#include "SchlauerBot.hpp"
#include "Spieler.hpp"
#include <iostream>

int feld[42] = {0};

int main()
{

    for (int j = 0; j < 20; j = j + 7)
    {
        feld[j] = 1;
    }
    /*    for (int i = 1; i < 23; i = i + 2)
    {
        feld[i] = 2;
    }
    feld[22] = 1;
    feld[29] = 2;
    feld[25] = 1;
    feld[32] = 2;
    feld[39] = 1;
    feld[13] = 0;
    feld[6] = 0;
    feld[20] = 0;
    feld[5] = 1;
    feld[3] = 1;
*/
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
    a = bot3.zug_zeile();
    std::cout << a << std::endl;
    SchlauerBot bot4 = SchlauerBot(feld, 1);
    a = bot4.zug_zeile();
    std::cout << "Schaluer auswahl: " << a << std::endl;
    return 0;
}