#include "HorizontalerBot.hpp"

HorizontalerBot::HorizontalerBot(int *feld)
    : Bots{feld}
{
}

int HorizontalerBot::zug_zeile()
{
    // zeile evaluieren

    // todo feste grenzen des Felds
    int wert = 0;
    for (int i = 0; i < 42; i++)
    {
        if (*(m_feld + i) == 0)
        {
            return i % 7;
        }
    }

    return -1;
}
