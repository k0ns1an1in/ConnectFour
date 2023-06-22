#pragma once
#include "GUI.h"
class Verwaltung
{
public:
    Verwaltung();
    GUI getGui();
private:
    int m_spielfeld[7][7] = {0};
    GUI m_gui;
    //todo Spieler1
    //todo Spieler2
};
