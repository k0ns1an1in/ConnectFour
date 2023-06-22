#pragma once

#include "Bots.hpp"

class ZufallsBot : public Bots
{
public:
    ZufallsBot(int *feld);
    int zug_zeile() override;
};