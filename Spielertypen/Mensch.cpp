#include "Mensch.hpp"

using std::cin;
using std::cout;
using std::endl;

int Mensch::zug_spalte()
{
    int spalte = -1;
    while (true)
    {
        cout << "Bitte geben Sie eine Spalte ein: ";
        cin >> spalte;
        cout << endl;
        // todo hardcode zeilen
        if (spalte >= 0 && spalte <= 6)
        {
            return spalte;
        }
        else
        {
            cout << "Ungueltige Eingabe" << endl;
        }
    }
}
