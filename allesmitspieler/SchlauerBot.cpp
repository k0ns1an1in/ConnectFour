#include "SchlauerBot.hpp"
#include <random>
#include <iostream>

SchlauerBot::SchlauerBot(int *feld, int spielernummer)
    : Bots{feld}, m_spielnummer{spielernummer}
{
}

int SchlauerBot::zug_zeile()
{
    // todo richtiger algorithmus erarbeiten
    // test
    // todo feste grenzen des Felds
    // muss wissen welche zahl er selbst ist

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
}
