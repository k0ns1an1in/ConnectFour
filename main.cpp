#include <iostream>
#include "Verwaltung.h"
int main123()
{
    Verwaltung device = Verwaltung(1, 5);
    device.getGui().spielfeldDrucken();
    device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
    device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
    device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
    device.spielsteinEinfuegen(device.getSpieler2()->zug_zeile(), 1);
    // device.spielsteinEinfuegen(device.getSpieler2()->zug_zeile(), 1);
    device.getGui().spielfeldDrucken();
    return 0;
}
