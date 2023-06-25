#include <iostream>
#include "Verwaltung.h"
using namespace std;

int main()
{
    Verwaltung device = Verwaltung(5, 5);
    device.spielen();
    return 0;
}
