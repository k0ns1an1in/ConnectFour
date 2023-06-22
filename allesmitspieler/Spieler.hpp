#pragma once

class Spieler
{

public:
    Spieler(){};
    virtual int zug_zeile() = 0;
    virtual ~Spieler() {}
};