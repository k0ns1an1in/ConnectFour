#pragma once
#include "GUI.h"
#include <iostream>
#include "allesmitspieler/Spieler.hpp"
#include "allesmitspieler/VertikalerBot.hpp"   //1
#include "allesmitspieler/HorizontalerBot.hpp" //2
#include "allesmitspieler/Mensch.hpp"          //3
#include "allesmitspieler/ZufallsBot.hpp"      //4
#include "allesmitspieler/SchlauerBot.hpp"     //5

class Verwaltung
{
public:
    Verwaltung();
    Verwaltung(int spielerCode1, int spielerCode2);
    int spielsteinEinfuegen(int spalte, int spielerNummer);
    int spielen();
    void spielenTest(int anzahlSpiele);
    int vollUeberpruefen() const;
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
