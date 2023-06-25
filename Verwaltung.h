#pragma once
#include "GUI.h"
#include "allesmitspieler/Spieler.hpp"

class Verwaltung
{
public:
    Verwaltung(int codeSpieler1, int codeSpieler2);
    int spielsteinEinfuegen(int spalte, int spielerNummer);
    GUI getGui() const;
    Spieler* getSpieler1() const;
    Spieler* getSpieler2() const;
    int siegUeberpruefen() const;
private:
    int m_spielfeld[42] = {0};
    const GUI m_gui;
    Spieler* m_spieler1;
    Spieler* m_spieler2;
};
