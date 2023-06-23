#pragma once
#include "GUI.h"
#include "allesmitspieler/Spieler.hpp"
class Verwaltung
{
public:
    Verwaltung();
    GUI getGui();
    void spielzug(Spieler spieler);
    void spielsteinEinfuegen(int spalte);
    int siegUeberpruefen();
private:
    int m_spielfeld[7][6] = {0};
    GUI m_gui;
    Spieler m_spieler1;
    Spieler m_spieler2;
};
