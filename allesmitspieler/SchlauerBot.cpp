#include "SchlauerBot.hpp"
#include <random>
#include <iostream>

SchlauerBot::SchlauerBot(int *feld, int spielernummer)
    : Bots{feld}, m_spielnummer{spielernummer}
{
}

int SchlauerBot::zug_zeile()
{
    //alter algo: ~63% siegquote gegen random
    /* Algorithmus schaut nach einer Siegmöglichkeit: ~65% Siegquote gegen Random
    int zahl_gegner = 1;

    // drei einsen finden, die nebeneinanderliegen:

    // Zeilen abchecken:
    int cntr_sichselbst = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (*(m_feld + 7 * i + j) == m_spielnummer)
            {
                if (cntr_sichselbst < 2)
                {
                    cntr_sichselbst++;
                }
                else
                {
                    if (j > 2)
                    {
                        if (*(m_feld + 7 * i + j - 3) == 0)
                        {
                            return j - 3;
                        }
                    }
                    if (j < 6)
                    {
                        if (*(m_feld + 7 * i + j + 1) == 0)
                        {
                            return j + 1;
                        }
                    }
                }
            }
            else
            {
                cntr_sichselbst = 0;
            }
        }
        cntr_sichselbst = 0;
    }
    cntr_sichselbst = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (*(m_feld + 7 * j + i) == m_spielnummer)
            {
                if (cntr_sichselbst < 2)
                {
                    cntr_sichselbst++;
                }
                else
                {
                    if (j < 5)
                    {
                        if (*(m_feld + 7 * j + i + 7) == 0)
                        {
                            return i;
                        }
                    }
                }
            }
            else
            {
                cntr_sichselbst = 0;
            }
        }
        cntr_sichselbst = 0;
    }

    // sonst random:
    std::random_device dev;
    std::mt19937 gen(dev());

    int spaltenzahl;

    while (true)
    {
        std::uniform_int_distribution<int> dist(0, 6);
        spaltenzahl = dist(gen);
        if (*(m_feld + 35 + spaltenzahl) == 0)
        {
            std::cout << "random" << std::endl;
            return spaltenzahl;
        }
    }
     */

    //neuer algo: ~82.1% siegquote gegen random
    int counterEigeneSteine = 0;
    int counterGegnerSteine = 0;
    //offensive
    {
        counterEigeneSteine = 0;
        //check for straight horizontal win to the right: 1 1 1 0
        for (int i = 0; i < 41; i++) {
            if (m_feld[i] == m_spielnummer) {
                counterEigeneSteine++;
                if ((counterEigeneSteine == 3) && (i % 7 != 6) && (m_feld[i + 1] == 0)) {
                    return (i + 1) % 7;
                }
            }
            if ((m_feld[i] != m_spielnummer) || (i % 7 == 6)) {
                counterEigeneSteine = 0;
            }
        }

        counterEigeneSteine = 0;
        //check for spaced horizontal win to the right: 1 1 0 1

        counterEigeneSteine = 0;
        //check for straight horizontal win to the left: 0 1 1 1
        for (int i = 41; i > 0; i--) {
            if (m_feld[i] == m_spielnummer) {
                counterEigeneSteine++;
                if ((counterEigeneSteine == 3) && (i % 7 != 0) && m_feld[i - 1] == 0) {
                    return (i - 1) % 7;
                }
            }
            if ((m_feld[i] != m_spielnummer) || (i % 7 == 0)) {
                counterEigeneSteine = 0;
            }
        }

        counterEigeneSteine = 0;
        //check for spaced horizontal win to the left: 1 0 1 1
#
        counterEigeneSteine = 0;
        //check for vertical win
        for (int x = 0; x < 7; x++) {
            for (int y = 0; y < 5; y++) {
                if (m_feld[x + (y * 7)] == m_spielnummer) {
                    counterEigeneSteine++;
                    if (counterEigeneSteine == 3 && m_feld[x + (y * 7) + 7] == 0) {
                        return x;
                    }
                } else {
                    counterEigeneSteine = 0;
                }
            }
            counterEigeneSteine = 0;
        }

        counterEigeneSteine = 0;
        //check for straight diagonal win;
        for (int i = 3; i <= 5; i++) {
            for (int k = i; k <= (i * 7) - 6; k += 6) {
                if (m_feld[k] == m_spielnummer) {
                    counterEigeneSteine++;
                    if (counterEigeneSteine == 3 && m_feld[k + 6] == 0) {
                        return (k + 6) % 7;
                    }
                } else {
                    counterEigeneSteine = 0;
                }
            }
            counterEigeneSteine = 0;
        }
        for (int i = 6; i <= 20; i += 7) {
            for (int k = i; k <= 32; k += 6) {
                if (m_feld[k] == m_spielnummer) {
                    counterEigeneSteine++;
                    if (counterEigeneSteine == 3 && m_feld[k + 6] == 0) {
                        return (k + 6) % 7;
                    }
                } else {
                    counterEigeneSteine = 0;
                }
            }
            counterEigeneSteine = 0;
        }

        for (int i = 1; i <= 3; i++) {
            for (int k = i; k <= 33 - (7 * (i - 1)); k += 8) {
                if (m_feld[k] == m_spielnummer) {
                    counterEigeneSteine++;
                    if (counterEigeneSteine == 3 && m_feld[k + 8] == 0) {
                        return (k + 8) % 7;
                    }
                } else {
                    counterEigeneSteine = 0;
                }
            }
            counterEigeneSteine = 0;
        }
        for (int i = 14; i >= 0; i -= 7) {
            for (int k = i; k <= 32; k += 8) {
                if (m_feld[k] == m_spielnummer) {
                    counterEigeneSteine++;
                    if (counterEigeneSteine == 3 && m_feld[k + 8] == 0) {
                        return (k + 8) % 7;
                    }
                } else {
                    counterEigeneSteine = 0;
                }
            }
            counterEigeneSteine = 0;
        }
    }
    //defensive
    {
        counterGegnerSteine = 0;
        //check for horizontal loss to the right
        for (int i = 0; i < 41; i++) {
            if (m_feld[i] == (!(m_spielnummer - 1) + 1)) {
                counterGegnerSteine++;
                if ((counterGegnerSteine == 3) && (i % 7 != 6) && (m_feld[i + 1] == 0)) {
                    return (i + 1) % 7;
                }
            }
            if ((m_feld[i] != (!(m_spielnummer - 1) + 1)) || (i % 7 == 6)) {
                counterGegnerSteine = 0;
            }
        }

        counterGegnerSteine = 0;
        //check for horizontal loss to the left
        for (int i = 41; i > 0; i--) {
            if (m_feld[i] == (!(m_spielnummer - 1) + 1)) {
                counterGegnerSteine++;
                if ((counterGegnerSteine == 3) && (i % 7 != 0) && m_feld[i - 1] == 0) {
                    return (i - 1) % 7;
                }
            }
            if ((m_feld[i] != (!(m_spielnummer - 1) + 1)) || (i % 7 == 0)) {
                counterGegnerSteine = 0;
            }
        }

        counterGegnerSteine = 0;
        //check for vertical loss
        for (int x = 0; x < 7; x++) {
            for (int y = 0; y < 5; y++) {
                if (m_feld[x + (y * 7)] == (!(m_spielnummer - 1) + 1)) {
                    counterGegnerSteine++;
                    if (counterGegnerSteine == 3 && m_feld[x + (y * 7) + 7] == 0) {
                        return x;
                    }
                } else {
                    counterGegnerSteine = 0;
                }
            }
            counterGegnerSteine = 0;
        }

        counterGegnerSteine = 0;
        //check for diagonal loss
        for (int i = 3; i <= 5; i++) {
            for (int k = i; k <= (i * 7) - 6; k += 6) {
                if (m_feld[k] == (!(m_spielnummer - 1) + 1)) {
                    counterGegnerSteine++;
                    if (counterGegnerSteine == 3 && m_feld[k + 6] == 0) {
                        return (k + 6) % 7;
                    }
                } else {
                    counterGegnerSteine = 0;
                }
            }
            counterGegnerSteine = 0;
        }
        for (int i = 6; i <= 20; i += 7) {
            for (int k = i; k <= 32; k += 6) {
                if (m_feld[k] == (!(m_spielnummer - 1) + 1)) {
                    counterGegnerSteine++;
                    if (counterGegnerSteine == 3 && m_feld[k + 6] == 0) {
                        return (k + 6) % 7;
                    }
                } else {
                    counterGegnerSteine = 0;
                }
            }
            counterGegnerSteine = 0;
        }

        for (int i = 1; i <= 3; i++) {
            for (int k = i; k <= 33 - (7 * (i - 1)); k += 8) {
                if (m_feld[k] == (!(m_spielnummer - 1) + 1)) {
                    counterGegnerSteine++;
                    if (counterGegnerSteine == 3 && m_feld[k + 8] == 0) {
                        return (k + 8) % 7;
                    }
                } else {
                    counterGegnerSteine = 0;
                }
            }
            counterGegnerSteine = 0;
        }
        for (int i = 14; i >= 0; i -= 7) {
            for (int k = i; k <= 32; k += 8) {
                if (m_feld[k] == (!(m_spielnummer - 1) + 1)) {
                    counterGegnerSteine++;
                    if (counterGegnerSteine == 3 && m_feld[k + 8] == 0) {
                        return (k + 8) % 7;
                    }
                } else {
                    counterGegnerSteine = 0;
                }
            }
            counterGegnerSteine = 0;
        }
    }
    //sonst random:
    {
        std::random_device dev;
        std::mt19937 gen(dev());
        std::uniform_int_distribution<int> dist(0, 6);
        int spaltenzahl = dist(gen);
        while (m_feld[spaltenzahl + 35] != 0) {
            spaltenzahl = dist(gen);
        }
        //std::cout << "random" << std::endl;
        return spaltenzahl;
    }
}
