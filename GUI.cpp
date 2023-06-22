#include "GUI.h"
using namespace std;
GUI::GUI(int *neuesFeld)
{
    m_spielfeld = neuesFeld;
}

void GUI::spielfeldDrucken() const
{
    for(int y=0;y<6;y++)
    {
        for(int x=0;x<7;x++)
        {
            cout << *(x+m_spielfeld + 7*y) << "\t";
        }
        cout << endl;
    }
}