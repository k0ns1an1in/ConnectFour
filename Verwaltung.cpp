#include "Verwaltung.h"

Verwaltung::Verwaltung():m_gui(GUI(&m_spielfeld[0][0]))
{
}

GUI Verwaltung::getGui()
{
    return m_gui;
}