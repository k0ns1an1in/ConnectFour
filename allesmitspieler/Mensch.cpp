#include "Mensch.hpp"

using std::cin;
using std::cout;
using std::endl;

int Mensch::zug_zeile()
{
    // durch user input
    // todo man muss abfangen, wenn die spalte schon voll ist
    int zeile = -1;
    while (true)
    {
        cout << "Bitte geben Sie eine Spalte ein: ";
        cin >> zeile;
        cout << endl;
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
