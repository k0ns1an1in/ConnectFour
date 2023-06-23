#pragma once

#include "Bots.hpp"
#include <random>

class ZufallsBot : public Bots
{
public:
    ZufallsBot(int *feld);
    int zug_zeile() override;
};