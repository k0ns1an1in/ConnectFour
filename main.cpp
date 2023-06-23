#include <iostream>
#include "Verwaltung.h"
int mainpfusch()
{
    Verwaltung device = Verwaltung();
    device.getGui().spielfeldDrucken();
    return 0;
}
