#include <iostream>
#include "Verwaltung.h"
using namespace std;
int main()
{
    int oscillator=0;
    Verwaltung device = Verwaltung(3, 3);
    device.getGui().spielfeldDrucken();
    while(device.siegUeberpruefen()==0)
    {
        if(!oscillator)
        {
            device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
            oscillator=!oscillator;
        }else if(oscillator)
        {
            device.spielsteinEinfuegen(device.getSpieler2()->zug_zeile(), 2);
            oscillator=!oscillator;
        }
        device.getGui().spielfeldDrucken();
    }
    cout << "Spieler " << !oscillator +1 << " hat gewonnen!" << endl;
    return 0;
}
