#include <iostream>
#include "Verwaltung/Verwaltung.h"
using namespace std;

int main()
{
    Verwaltung device = Verwaltung(4, 5);
    device.spielenTest(1000);

    //Verwaltung device = Verwaltung();
    //device.spielen();
    return 0;
}
