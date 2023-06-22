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

    int vorlaeufigemaxhoehe = 0;
    int wert = 0;
    int maxhoehe = 0;
    for (int i = 0; i < 6; i++)
    {
        // i: spaltennummer

        do
        {
            wert = *(m_feld + i + vorlaeufigemaxhoehe++ * 7);
        } while (wert != 0 || vorlaeufigemaxhoehe >= 5);

        if (vorlaeufigemaxhoehe >= 5)
        {
            vorlaeufigemaxhoehe = maxhoehe;
        }
        else
        {
            maxhoehe = vorlaeufigemaxhoehe;
        }
    }
    cout << maxhoehe << endl;
    return maxhoehe;
}
