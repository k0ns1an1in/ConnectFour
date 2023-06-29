#include "VertikalerBot.hpp"

using std::cout;
using std::endl;

VertikalerBot::VertikalerBot(int *feld)
    : Bots{feld}
{
}

int VertikalerBot::zug_spalte()
{
    // algorithmus
    int zugzeile = 0;
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
        if (vorlaeufigemaxhoehe >= 6)
        {
            zugzeile++;
            continue;
        }
        if (maxhoehe < vorlaeufigemaxhoehe)
        {
            zugzeile = i;
            maxhoehe = vorlaeufigemaxhoehe;
        }
    }
    return zugzeile;
}
