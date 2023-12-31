#include "ZufallsBot.hpp"

ZufallsBot::ZufallsBot(int *feld)
    : Bots{feld}
{
}

int ZufallsBot::zug_spalte()
{
    std::random_device dev;
    std::mt19937 gen(dev());

    int spaltenzahl;

    while (true)
    {
        std::uniform_int_distribution<int> dist(0, 6);
        spaltenzahl = dist(gen);
        if (*(m_feld + 35 + spaltenzahl) == 0)
        {
            return spaltenzahl;
        }
    }
    return -1;
}
