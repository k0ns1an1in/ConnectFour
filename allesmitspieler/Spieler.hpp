#pragma once

class Spieler
{

public:
    Spieler();
    virtual int zug_zeile();
    virtual ~Spieler() {}
};