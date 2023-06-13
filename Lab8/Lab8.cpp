#include <iostream>
#include <fstream>
#include <string>
#include "Ctype.h"
using namespace std;

int x = 1;
int clas;
string c;
int main()
{
    Character charac;
    int choice;
    while (x != 0)
    {
        cout << "\n<<<<<< This is a fun game >>>>>\n";
        cout << "0. Exit game " << endl;
        cout << "1. Create new character " << endl;
        cout << "2. Load character " << endl;
        cin >> choice;
        while (1)
        {
            if (choice == 1)
            {
                charac.make_character();
                clas = charac.get_type();
                if (clas == 1)
                {
                    mage m;
                    m.stats(charac);
                }
                else if (clas == 2)
                {
                    warrior w;
                    w.stats(charac);
                }
                else if (clas == 3)
                {
                    berserker b;
                    b.stats(charac);
                }
                else 
                {
                    theif t;
                    t.stats(charac);
                }
                break;
            }
            else if (choice == 2)
            {
                charac.get_character();
                break;
            }
            else if (choice == 0)
            {
                cout << "Thank you for playing!" << endl
                     << "Goodbye";
                x = choice;
                break;
            }
            else
            {
                cout << "No such option..Please enter proper number or 0 to exit the game" << endl;
                cin >> choice;
            }
        }
    }
    return 0;
}