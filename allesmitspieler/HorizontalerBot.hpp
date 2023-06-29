#pragma once

#include "Bots.hpp"

class HorizontalerBot : public Bots
{
public:
    HorizontalerBot(int *feld);
    int zug_spalte() override;
};