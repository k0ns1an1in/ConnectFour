#pragma once

#include "Bots.hpp"
#include <iostream>

class VertikalerBot : public Bots
{
public:
    VertikalerBot(int *feld);
    int zug_spalte() override;
};