#pragma once

class Spieler
{

public:
    Spieler(){};
    virtual int zug_spalte() = 0;
    virtual ~Spieler() {}
};