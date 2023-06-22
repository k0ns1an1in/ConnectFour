#pragma once
#include <iostream>
class GUI
{
public:
    explicit GUI(int* neuesFeld);
    void spielfeldDrucken() const;
private:
    int* m_spielfeld;
};