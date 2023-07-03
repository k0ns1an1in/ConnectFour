#pragma once
#include <iostream>
#include "ConsoleColor.h"
class GUI
{
public:
    explicit GUI(int* neuesFeld);
    void spielfeldDrucken() const;
private:
    int* m_spielfeld;
};