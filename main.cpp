#include <iostream>
#include "Verwaltung.h"
using namespace std;
int main()
{
    int oscillator=0;
    Verwaltung device = Verwaltung(3, 3);
    device.spielen();
    return 0;
}
