#include "Verwaltung.h"
#include "allesmitspieler/VertikalerBot.hpp"
Verwaltung::Verwaltung(int spielerCode1, int spielerCode2):m_gui(GUI(&m_spielfeld[0][0]))
{
    m_spieler1 = new VertikalerBot(&m_spielfeld[0][0]);
}

GUI Verwaltung::getGui()
{
    return m_gui;
}

void Verwaltung::spielsteinEinfuegen(int spalte, int spielerNummer)
{
    for(int i=5;i>=0;i--)
    {
        if(m_spielfeld[spalte][i] == 0)
        {
            m_spielfeld[spalte][i] = spielerNummer;
        }
    }
}