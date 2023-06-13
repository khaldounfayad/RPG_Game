#include <iostream>
#include <fstream>
#include <string>
#include "Ctype.h"
#include "monsters.h"
#include "Mechanics.h"
#include "Character.h"
using namespace std;

int x = 1;
int clas, check, i = 1;
string c;
Character charac;
monster M1, M2, M3, M4, M5;

void battle_sim()
{
    cout << "The battle is startting ready your weapons" << endl;
    score<int> j;
    j.comparison(charac, M2);
    j.winner(charac, M2, i);
}

int main()
{
    int choice;
    while (x != 0)
    {
        cout << "\n<<<<<< This is a fun game >>>>>\n";
        cout << "0. Exit game " << endl;
        cout << "1. Create new character " << endl;
        cout << "2. Load character " << endl;
        cout << "3. Create monsters " << endl;
        cout << "4. Start Battle " << endl;
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
                charac.get_stats("");
                break;
            }
            else if (choice == 0)
            {
                cout << "Thank you for playing!" << endl
                     << "Goodbye";
                x = choice;
                break;
            }
            else if (choice == 3)
            {
                M1.get_stats("Monster1");
                M1.make_character();
                M2.get_stats("Monster2");
                M2.make_character();
                M3.get_stats("Monster3");
                M3.make_character();
                M4.get_stats("Monster4");
                M4.make_character();
                M5.get_stats("Monster5");
                M5.make_character();
                cout << "\nTotal Monsters created : 5\n";
                int check = 1;
                break;
            }
            if (choice == 4)
            {
                charac.get_stats("");
                battle_sim();
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