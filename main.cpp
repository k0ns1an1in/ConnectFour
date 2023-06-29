#include <iostream>
#include "Verwaltung.h"
using namespace std;

int main()
{
    Verwaltung device = Verwaltung(5, 5);
    device.spielenTest(100000);

    //Verwaltung device = Verwaltung();
    //device.spielen();
    return 0;
}
