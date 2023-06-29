#pragma once

#include "Spieler.hpp"
#include <iostream>

class Mensch : public Spieler
{
public:
    Mensch(){};
    int zug_spalte() override;
};