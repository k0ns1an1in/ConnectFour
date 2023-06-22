#include <iostream>
#include "Verwaltung.h"
int main()
{
    Verwaltung device = Verwaltung();
    device.getGui().spielfeldDrucken();
    return 0;
}
