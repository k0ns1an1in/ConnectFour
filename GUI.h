#pragma once
class GUI
{
public:
    GUI(int* neuesFeld);
    ~GUI();
    void spielfeldDrucken() const;
private:
    int* m_feld;
};