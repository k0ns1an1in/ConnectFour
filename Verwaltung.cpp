#include "Verwaltung.h"
#include "allesmitspieler/VertikalerBot.hpp"
#include "allesmitspieler/HorizontalerBot.hpp"
#include "allesmitspieler/Mensch.hpp"
#include "allesmitspieler/ZufallsBot.hpp"
#include "allesmitspieler/SchlauerBot.hpp"

Verwaltung::Verwaltung(int spielerCode1, int spielerCode2):m_gui(GUI(&m_spielfeld[0][0]))
{
    switch(spielerCode1)
    {
        case 1:
        {
            m_spieler1 = new VertikalerBot(&m_spielfeld[0][0]);
            break;
        }
        case 2:
        {
            m_spieler1 = new HorizontalerBot(&m_spielfeld[0][0]);
            break;
        }
        case 3:
        {
            m_spieler1 = new Mensch();
            break;
        }
        case 4:
        {
            m_spieler1 = new ZufallsBot(&m_spielfeld[0][0]);
            break;
        }
        case 5:
        {
            m_spieler1 = new SchlauerBot(&m_spielfeld[0][0]);
            break;
        }
    }

    switch(spielerCode2)
    {
        case 1:
        {
            m_spieler2 = new VertikalerBot(&m_spielfeld[0][0]);
            break;
        }
        case 2:
        {
            m_spieler2 = new HorizontalerBot(&m_spielfeld[0][0]);
            break;
        }
        case 3:
        {
            m_spieler2 = new Mensch();
            break;
        }
        case 4:
        {
            m_spieler2 = new ZufallsBot(&m_spielfeld[0][0]);
            break;
        }
        case 5:
        {
            m_spieler2 = new SchlauerBot(&m_spielfeld[0][0]);
            break;
        }
    }
}

GUI Verwaltung::getGui()
{
    return m_gui;
}

int Verwaltung::spielsteinEinfuegen(int spalte, int spielerNummer)
{
    for(int i=5;i>=0;i--)
    {
        if(m_spielfeld[spalte][i] == 0)
        {
            m_spielfeld[spalte][i] = spielerNummer;
            return 1;
        }
    }
    return 0;
}

int Verwaltung::siegUeberpruefen()
{
    int spieler1counter = 0;
    int spieler2counter = 0;
    for(int y=0;y<6;y++)      //check for horizontal win
    {
        for(int x=0;x<7;x++)
        {
            if(m_spielfeld[x][y] == 1)
            {
                spieler1counter++;
                spieler2counter=0;
                if(spieler1counter==4)
                {
                    return 1;
                }
            }
            if(m_spielfeld[x][y] == 2)
            {
                spieler2counter++;
                spieler1counter=0;
                if(spieler2counter==4)
                {
                    return 2;
                }
            }
            if(m_spielfeld[x][y] == 0)
            {
                spieler1counter=0;
                spieler2counter=0;
            }
        }
        spieler1counter=0;
        spieler2counter=0;
    }

    for(int x=0;x<7;x++)    //check for vertical win
    {
        for(int y=0;y<6;y++)
        {
            if(m_spielfeld[x][y]==1)
            {
                spieler1counter++;
                spieler2counter=0;
                if(spieler1counter==4)
                {
                    return 1;
                }
            }
            if(m_spielfeld[x][y]==2)
            {
                spieler2counter++;
                spieler1counter=0;
                if(spieler2counter==4)
                {
                    return 2;
                }
            }
            if(m_spielfeld[x][y]==0)
            {
                spieler1counter=0;
                spieler2counter=0;
            }
        }
        spieler1counter=0;
        spieler2counter=0;
    }
    //todo check for horizontal win
    return 0;
}