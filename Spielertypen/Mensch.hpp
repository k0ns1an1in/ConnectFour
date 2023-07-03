#pragma once

#include "Spieler.hpp"
#include <iostream>
#include <locale.h>

class Mensch : public Spieler
{
public:
    Mensch(){};
    int zug_spalte() override;
};