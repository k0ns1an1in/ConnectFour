#include "Mensch.hpp"

using std::cin;
using std::cout;
using std::endl;

int Mensch::zug_zeile()
{
    // durch user input
    int zeile = -1;
    while (true)
    {
        cout << "Bitte geben Sie eine Zeile ein: ";
        cin >> zeile;
        // todo hardcode zeilen
        if (zeile >= 0 && zeile <= 6)
        {
            return zeile;
        }
        else
        {
            cout << "Ungueltige Eingabe" << endl;
        }
    }
}
