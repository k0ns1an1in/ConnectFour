#include "VertikalerBot.hpp"

using std::cout;
using std::endl;

VertikalerBot::VertikalerBot(int *feld)
    : Bots{feld}
{
}

int VertikalerBot::zug_zeile()
{
    // algorithmus
    // todo feste grenzen
    int zugzeile = -1;
    int vorlaeufigemaxhoehe;
    int wert = 0;
    int maxhoehe = 0;
    for (int i = 0; i < 7; i++)
    {
        // i: spaltennummer
        vorlaeufigemaxhoehe = 0;
        do
        {
            wert = *(m_feld + i + vorlaeufigemaxhoehe++ * 7);
        } while (wert != 0 && vorlaeufigemaxhoehe <= 6);
        vorlaeufigemaxhoehe--;

        if (maxhoehe < vorlaeufigemaxhoehe && vorlaeufigemaxhoehe < 6)
        {
            zugzeile = i;
            maxhoehe = vorlaeufigemaxhoehe;
        }
    }
    return zugzeile;
}
