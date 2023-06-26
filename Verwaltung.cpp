#include "Verwaltung.h"
#include "allesmitspieler/VertikalerBot.hpp"   //1
#include "allesmitspieler/HorizontalerBot.hpp" //2
#include "allesmitspieler/Mensch.hpp"          //3
#include "allesmitspieler/ZufallsBot.hpp"      //4
#include "allesmitspieler/SchlauerBot.hpp"     //5
using namespace std;

Verwaltung::Verwaltung() : m_gui(GUI(&m_spielfeld[0]))
{
    int spielerCode;

    cout << "Welche Art von Spieler ist Spieler1?" << endl
         << "(1): Vertikaler Bot" << endl
         << "(2): Horizontaler Bot" << endl
         << "(3): Mensch" << endl
         << "(4): Zufalls Bot" << endl
         << "(5): Schlauer Bot" << endl;

    cin >> spielerCode;

    switch (spielerCode)
    {
    case 1:
    {
        m_spieler1 = new VertikalerBot(&m_spielfeld[0]);
        break;
    }
    case 2:
    {
        m_spieler1 = new HorizontalerBot(&m_spielfeld[0]);
        break;
    }
    case 3:
    {
        m_spieler1 = new Mensch();
        break;
    }
    case 4:
    {
        m_spieler1 = new ZufallsBot(&m_spielfeld[0]);
        break;
    }
    case 5:
    {
        m_spieler1 = new SchlauerBot(&m_spielfeld[0], 1);
        break;
    }
    }
    cout << "Welche Art von Spieler ist Spieler1?" << endl
         << "(1): ..."
         << "(2): ..."
         << "(3): ..."
         << "(4): ..."
         << "(5): ..." << endl;
    cin >> spielerCode;

    switch (spielerCode)
    {
    case 1:
    {
        m_spieler2 = new VertikalerBot(&m_spielfeld[0]);
        break;
    }
    case 2:
    {
        m_spieler2 = new HorizontalerBot(&m_spielfeld[0]);
        break;
    }
    case 3:
    {
        m_spieler2 = new Mensch();
        break;
    }
    case 4:
    {
        m_spieler2 = new ZufallsBot(&m_spielfeld[0]);
        break;
    }
    case 5:
    {
        m_spieler2 = new SchlauerBot(&m_spielfeld[0], 2);
        break;
    }
    }
}

GUI Verwaltung::getGui() const
{
    return m_gui;
}

void Verwaltung::spielen()
{
    int oscillator = 0;
    cout << "-----------SPIEL BEGINNT----------" << endl;
    this->getGui().spielfeldDrucken();
    while (this->siegUeberpruefen() == 0)
    {
        if (!oscillator)
        {
            cout << "Spieler 1 am Zug" << endl;
            this->spielsteinEinfuegen(this->getSpieler1()->zug_zeile(), 1);
            oscillator = !oscillator;
        }
        else if (oscillator)
        {
            cout << "Spieler 2 am Zug" << endl;
            this->spielsteinEinfuegen(this->getSpieler2()->zug_zeile(), 2);
            oscillator = !oscillator;
        }
        this->getGui().spielfeldDrucken();
    }
    cout << "Spieler " << !oscillator + 1 << " hat gewonnen!" << endl;
    return;
}

int Verwaltung::spielsteinEinfuegen(int spalte, int spielerNummer)
{
    for (int i = 0; i < 6; i++)
    {
        if (m_spielfeld[spalte + i * 7] == 0)
        {
            m_spielfeld[spalte + i * 7] = spielerNummer;
            return 1;
        }
    }
    return 0;
}

int Verwaltung::horizontalerSiegUeberpruefen() const
{
    int spieler1counter = 0;
    int spieler2counter = 0;

    for (int y = 0; y < 6; y++) // check for horizontal win
    {
        for (int x = 0; x < 7; x++)
        {
            if (m_spielfeld[x + y * 7] == 1)
            {
                spieler1counter++;
                spieler2counter = 0;
                if (spieler1counter == 4)
                {
                    return 1;
                }
            }
            if (m_spielfeld[x + y * 7] == 2)
            {
                spieler2counter++;
                spieler1counter = 0;
                if (spieler2counter == 4)
                {
                    return 2;
                }
            }
            if (m_spielfeld[x + y * 7] == 0)
            {
                spieler1counter = 0;
                spieler2counter = 0;
            }
        }
        spieler1counter = 0;
        spieler2counter = 0;
    }
    return 0;
}

int Verwaltung::vertikalerSiegUeberpruefen() const
{
    int spieler1counter = 0;
    int spieler2counter = 0;

    for (int x = 0; x < 7; x++) // check for vertical win
    {
        for (int y = 0; y < 6; y++)
        {
            if (m_spielfeld[x + y * 7] == 1)
            {
                spieler1counter++;
                spieler2counter = 0;
                if (spieler1counter == 4)
                {
                    return 1;
                }
            }
            if (m_spielfeld[x + y * 7] == 2)
            {
                spieler2counter++;
                spieler1counter = 0;
                if (spieler2counter == 4)
                {
                    return 2;
                }
            }
            if (m_spielfeld[x + y * 7] == 0)
            {
                spieler1counter = 0;
                spieler2counter = 0;
            }
        }
        spieler1counter = 0;
        spieler2counter = 0;
    }
    return 0;
}

int Verwaltung::diagonalerSiegUeberpruefen() const
{
    int spieler1counter = 0;
    int spieler2counter = 0;

    for (int start = 6; start >= 0; start--)
    {
        for (int i = start; i < 42; i += 6)
        {
            if (i % 7 == 6)
            {
                spieler1counter = 0;
                spieler2counter = 0;
            }
            if (m_spielfeld[i] == 1)
            {
                spieler1counter++;
                spieler2counter = 0;
                if (spieler1counter == 4)
                {
                    return 1;
                }
            }
            if (m_spielfeld[i] == 2)
            {
                spieler2counter++;
                spieler1counter = 0;
                if (spieler2counter == 4)
                {
                    return 2;
                }
            }
            if (m_spielfeld[0] == 0)
            {
                spieler1counter = 0;
                spieler2counter = 0;
            }
        }
        spieler1counter = 0;
        spieler2counter = 0;
    }

    for (int start = 0; start < 7; start++)
    {
        for (int i = start; i < 42; i += 8)
        {
            if (i % 7 == 0)
            {
                spieler1counter = 0;
                spieler2counter = 0;
            }
            if (m_spielfeld[i] == 1)
            {
                spieler1counter++;
                spieler2counter = 0;
                if (spieler1counter == 4)
                {
                    return 1;
                }
            }
            if (m_spielfeld[i] == 2)
            {
                spieler2counter++;
                spieler1counter = 0;
                if (spieler2counter == 4)
                {
                    return 2;
                }
            }
            if (m_spielfeld[0] == 0)
            {
                spieler1counter = 0;
                spieler2counter = 0;
            }
        }
        spieler1counter = 0;
        spieler2counter = 0;
    }
    return 0;
}

int Verwaltung::siegUeberpruefen() const
{
    int horizonteleBedingung = 0;
    int vertikaleBedingung = 0;
    int diagonaleBedingung = 0;

    horizonteleBedingung = horizontalerSiegUeberpruefen();
    vertikaleBedingung = vertikalerSiegUeberpruefen();
    diagonaleBedingung = diagonalerSiegUeberpruefen();

    if (horizonteleBedingung != 0)
    {
        return horizonteleBedingung;
    }
    if (vertikaleBedingung != 0)
    {
        return vertikaleBedingung;
    }
    if (diagonaleBedingung != 0)
    {
        return diagonaleBedingung;
    }
    return 0;
}

Spieler *Verwaltung::getSpieler1() const
{
    return m_spieler1;
}

Spieler *Verwaltung::getSpieler2() const
{
    return m_spieler2;
}