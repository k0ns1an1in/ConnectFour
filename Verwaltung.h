#pragma once
#include "GUI.h"
#include <iostream>
#include "allesmitspieler/Spieler.hpp"

class Verwaltung
{
public:
    Verwaltung();
    int spielsteinEinfuegen(int spalte, int spielerNummer);
    void spielen();
    GUI getGui() const;
    Spieler *getSpieler1() const;
    Spieler *getSpieler2() const;
    int siegUeberpruefen() const;
    int horizontalerSiegUeberpruefen() const;
    int vertikalerSiegUeberpruefen() const;
    int diagonalerSiegUeberpruefen() const;

private:
    int m_spielfeld[42] = {0};
    const GUI m_gui;
    Spieler *m_spieler1;
    Spieler *m_spieler2;
};
