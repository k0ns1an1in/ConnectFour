#include "GUI.h"
using namespace std;

GUI::GUI(int *neuesFeld)
{
    m_spielfeld = neuesFeld;
}

void GUI::spielfeldDrucken() const
{
    for(int y = 5;y >= 0;y--)
    {
        for(int x = 0;x < 7;x++)
        {
            cout << *(x + m_spielfeld + 7*y) << " ";
        }
        cout << endl;
    }
    cout << endl;
}