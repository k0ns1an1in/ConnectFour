#pragma once
#include "GUI.h"
#include "allesmitspieler/Spieler.hpp"
class Verwaltung
{
public:
    Verwaltung(int codeSpieler1, int codeSpieler2);
    GUI getGui();
    int spielsteinEinfuegen(int spalte, int spielerNummer);
    int siegUeberpruefen();
private:
    int m_spielfeld[7][6] = {0};
    GUI m_gui;
    Spieler* m_spieler1;
    Spieler* m_spieler2;
};
