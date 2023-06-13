#include <iostream>
#include <fstream>
#include <string>
#include "Ctype.h"
#include "monsters.h"
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
        cout << "3. Generate monsters " << endl;
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
            else if (choice == 3){
                monster M1,M2,M3,M4,M5;
                M1.get_stats("Monster1");M1.create_mons();
                M2.get_stats("Monster2");M2.create_mons();
                M3.get_stats("Monster3");M3.create_mons();
                M4.get_stats("Monster4");M4.create_mons();
                M5.get_stats("Monster5");M5.create_mons();
                cout << "\nTotal Monsters created : 5\n";
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