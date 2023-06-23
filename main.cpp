#include <iostream>
#include "Verwaltung.h"
int main()
{
    Verwaltung device = Verwaltung(1, 1);
    device.getGui().spielfeldDrucken();
    device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
    device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
    device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
    device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
    device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
    device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
    device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
    device.spielsteinEinfuegen(device.getSpieler1()->zug_zeile(), 1);
    device.getGui().spielfeldDrucken();
    return 0;
}
