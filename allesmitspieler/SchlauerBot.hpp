#pragma once

#include "Bots.hpp"

class SchlauerBot : public Bots
{
public:
    SchlauerBot(int *feld, int spielernummer);
    int zug_zeile() override;

private:
    const int m_spielnummer;
};