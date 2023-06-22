#pragma once

#include "Bots.hpp"

class VertikalerBot : public Bots
{

public:
    VertikalerBot(int *feld);
    int zug_zeile() override;
};