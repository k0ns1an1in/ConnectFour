#pragma once

#include "Bots.hpp"

class SchlauerBot : public Bots
{
public:
    SchlauerBot(int *feld);
    int zug_zeile() override;
};