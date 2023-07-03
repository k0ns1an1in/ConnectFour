#pragma once

#include "Spieler.hpp"

class Bots : public Spieler
{
public:
    Bots(int *feld);

protected:
    int *m_feld;
};
