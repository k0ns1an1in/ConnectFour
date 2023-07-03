#include <unistd.h>
#include "Verwaltung.h"
using namespace std;

//constructor for normal game
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
    cout << flush;

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
    cout << "Welche Art von Spieler ist Spieler2?" << endl
         << "(1): ..."
         << "(2): ..."
         << "(3): ..."
         << "(4): ..."
         << "(5): ..." << endl;

    cin >> spielerCode;
    cout << flush;

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

//constructor for testing
Verwaltung::Verwaltung(int spielerCode1, int spielerCode2): m_gui(GUI(&m_spielfeld[0]))
{
    switch (spielerCode1)
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

    switch (spielerCode2)
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

//check if field is full --> returns 1 if full
int Verwaltung::vollUeberpruefen() const
{
    int check = 1;
    for(int i = 0;i < 42;i++)
    {
        if(m_spielfeld[i] == 0)
        {
            check = 0;
        }
    }
    return check;
}

//executes given amount of games and prints the percentage of wins without any GUI
void Verwaltung::spielenTest(int anzahlSpiele)
{
    int zugSpieler2 = 0;
    int spielZaehler = 0;
    double spieler1counter = 0;
    double spieler2counter = 0;
    while(spielZaehler < anzahlSpiele)
    {
        for(int i = 0;i < 42;i++)
        {
            m_spielfeld[i] = 0;
        }
        while (this->siegUeberpruefen() == 0)
        {
            if (!zugSpieler2)
            {
                int spalte = this->getSpieler1()->zug_spalte();
                while (m_spielfeld[spalte + 35] != 0)
                {
                    spalte = this->getSpieler1()->zug_spalte();
                }
                this->spielsteinEinfuegen(spalte, 1);
                if (vollUeberpruefen())
                {
                    for (int i = 0; i < 42; i++)
                    {
                        m_spielfeld[i] = 0;
                    }
                }
                zugSpieler2 = !zugSpieler2;
            } else if (zugSpieler2)
            {
                int spalte = this->getSpieler2()->zug_spalte();
                while (m_spielfeld[spalte + 35] != 0)
                {
                    spalte = this->getSpieler2()->zug_spalte();
                }
                this->spielsteinEinfuegen(spalte, 2);
                if (vollUeberpruefen())
                {
                    for (int i = 0; i < 42; i++)
                    {
                        m_spielfeld[i] = 0;
                    }
                }
                zugSpieler2 = !zugSpieler2;
            }
        }
        if(siegUeberpruefen() == 1)
        {
            spieler1counter++;
        }else
        {
            spieler2counter++;
        }
        spielZaehler++;
    }
    if(spieler1counter > spieler2counter)
    {
        cout << "Spieler1 ist Gesamtsieger mit " << (spieler1counter/anzahlSpiele) * 100 << "% Siegesquote" << endl;
    }else
    {
        cout << "Spieler2 ist Gesamtsieger mit " << (spieler2counter/anzahlSpiele) * 100 << "% Siegesquote" << endl;
    }
}

//returns GUI instance
GUI Verwaltung::getGui() const
{
    return m_gui;
}

//executes one game with GUI
int Verwaltung::spielen()
{
    int zugSpieler2 = 0;
    cout << "-------SPIEL BEGINNT------" << endl;
    this->getGui().spielfeldDrucken();
    while (this->siegUeberpruefen() == 0)
    {
        if (!zugSpieler2)
        {
            cout << "Spieler 1 am Zug" << endl;
            int spalte = this->getSpieler1()->zug_spalte();
            while(m_spielfeld[spalte+35] != 0)
            {
                cout << "Fehler, Spalte voll!" << endl;
                spalte = this->getSpieler1()->zug_spalte();
            }
            this->spielsteinEinfuegen(spalte, 1);
            if(vollUeberpruefen())
            {
                for(int i = 0;i < 42;i++)
                {
                    m_spielfeld[i] = 0;
                }
            }
            zugSpieler2 = !zugSpieler2;
            sleep(1);
        }
        else if (zugSpieler2)
        {
            cout << "Spieler 2 am Zug" << endl;
            int spalte = this->getSpieler2()->zug_spalte();
            while(m_spielfeld[spalte+35] != 0)
            {
                cout << "Fehler, Spalte voll!" << endl;
                spalte = this->getSpieler2()->zug_spalte();
            }
            this->spielsteinEinfuegen(spalte, 2);
            if(vollUeberpruefen())
            {
                for(int i = 0;i < 42;i++)
                {
                    m_spielfeld[i] = 0;
                }
            }
            zugSpieler2 = !zugSpieler2;
            sleep(1);
        }
        this->getGui().spielfeldDrucken();
    }
    cout << "Spieler " << !zugSpieler2 + 1 << " hat gewonnen!" << endl;
    return siegUeberpruefen();
}

//adds a token to the board
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

//checks entire board for horizontal win --> returns 1 if player 1 has won, 2 if player 2 has won, 0 if no winners
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

//checks entire board for vertical win --> returns 1 if player 1 has won, 2 if player 2 has won, 0 if no winners
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

//checks entire board for diagonal win --> returns 1 if player 1 has won, 2 if player 2 has won, 0 if no winners
int Verwaltung::diagonalerSiegUeberpruefen() const
{
    int spieler1counter = 0;
    int spieler2counter = 0;

    //nicht hinterfragen, enorm schwer zu verstehen
    for(int i = 3;i <= 5;i++)
    {
        for(int k = i;k <= i * 7;k += 6)
        {
            if (m_spielfeld[k] == 1)
            {
                spieler1counter++;
                spieler2counter = 0;
                if (spieler1counter == 4)
                {
                    return 1;
                }
            }
            if (m_spielfeld[k] == 2)
            {
                spieler2counter++;
                spieler1counter = 0;
                if (spieler2counter == 4)
                {
                    return 2;
                }
            }
            if (m_spielfeld[k] == 0)
            {
                spieler1counter = 0;
                spieler2counter = 0;
            }
        }
        spieler1counter = 0;
        spieler2counter = 0;
    }
    for(int i = 6;i <= 20;i += 7)
    {
        for(int k = i;k <= 38;k += 6)
        {
            if (m_spielfeld[k] == 1)
            {
                spieler1counter++;
                spieler2counter = 0;
                if (spieler1counter == 4)
                {
                    return 1;
                }
            }
            if (m_spielfeld[k] == 2)
            {
                spieler2counter++;
                spieler1counter = 0;
                if (spieler2counter == 4)
                {
                    return 2;
                }
            }
            if (m_spielfeld[k] == 0)
            {
                spieler1counter = 0;
                spieler2counter = 0;
            }
        }
        spieler1counter = 0;
        spieler2counter = 0;
    }

    for(int i = 1;i <= 3;i++)
    {
        for(int k = i;k <= 41 - (7 * (i - 1));k += 8)
        {
            if (m_spielfeld[k] == 1)
            {
                spieler1counter++;
                spieler2counter = 0;
                if (spieler1counter == 4)
                {
                    return 1;
                }
            }
            if (m_spielfeld[k] == 2)
            {
                spieler2counter++;
                spieler1counter = 0;
                if (spieler2counter == 4)
                {
                    return 2;
                }
            }
            if (m_spielfeld[k] == 0)
            {
                spieler1counter = 0;
                spieler2counter = 0;
            }
        }
        spieler1counter = 0;
        spieler2counter = 0;
    }
    for(int i = 14;i >= 0;i -= 7)
    {
        for(int k = i;k <= 40;k += 8)
        {
            if (m_spielfeld[k] == 1)
            {
                spieler1counter++;
                spieler2counter = 0;
                if (spieler1counter == 4)
                {
                    return 1;
                }
            }
            if (m_spielfeld[k] == 2)
            {
                spieler2counter++;
                spieler1counter = 0;
                if (spieler2counter == 4)
                {
                    return 2;
                }
            }
            if (m_spielfeld[k] == 0)
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

//executes all win-checks --> returns 1 if player 1 has won, 2 if player 2 has won, 0 if no winners
int Verwaltung::siegUeberpruefen() const
{
    int horizontaleBedingung = 0;
    int vertikaleBedingung = 0;
    int diagonaleBedingung = 0;

    horizontaleBedingung = horizontalerSiegUeberpruefen();
    vertikaleBedingung = vertikalerSiegUeberpruefen();
    diagonaleBedingung = diagonalerSiegUeberpruefen();

    if (horizontaleBedingung != 0)
    {
        return horizontaleBedingung;
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

//returns player 1 instance
Spieler *Verwaltung::getSpieler1() const
{
    return m_spieler1;
}

//returns player 2 instance
Spieler *Verwaltung::getSpieler2() const
{
    return m_spieler2;
}