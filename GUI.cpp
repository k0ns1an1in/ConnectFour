#include "GUI.h"
using namespace std;

//constructor for GUI
GUI::GUI(int *neuesFeld)
{
    m_spielfeld = neuesFeld;
}

//prints the board
void GUI::spielfeldDrucken() const
{
    for(int i = 0;i < 7;i++)
    {
        cout << blue << i << "   ";
    }
    cout << endl;
    for(int y = 5;y >= 0;y--)
    {
        for(int x = 0;x < 7;x++)
        {
            switch(*(x + m_spielfeld + 7*y))
            {
                case 0:
                {
                    cout << white << 0;
                    break;
                }
                case 1:
                {
                    cout << red << 1;
                    break;
                }
                case 2:
                {
                    cout << yellow << 2;
                    break;
                }
            }
            cout << white << " | ";
        }
        cout << endl;
    }
    cout << endl;
}