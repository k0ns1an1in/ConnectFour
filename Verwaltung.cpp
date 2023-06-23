#include "Verwaltung.h"

Verwaltung::Verwaltung():m_gui(GUI(&m_spielfeld[0][0]))
{
    m_spieler1 = Spieler();
    m_spieler2 = Spieler();
}

GUI Verwaltung::getGui()
{
    return m_gui;
}

void Verwaltung::spielzug(Spieler spieler)
{

}

void Verwaltung::spielsteinEinfuegen(int spalte, int spielerNummer)
{
    for(int i=5;i>=0;i--)
    {
        if(*(spalte + m_spielfeld + 7 * i) == 0)
        {
            *(spalte + m_spielfeld + 7 * i) = spielerNummer;
        }
    }
}