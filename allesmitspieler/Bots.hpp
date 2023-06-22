#pragma once

#include "Spieler.hpp"

class Bots : public Spieler
{
public:
    Bots(int *feld);

private:
    int *m_feld;
};
