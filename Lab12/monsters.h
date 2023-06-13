#include "Character.h"
#include "template.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef RPG_CPP_MONSTERS_H
#define RPG_CPP_MONSTERS_H
class monster : public atrributes
{
public:
    void get_stats(string n)
    {
        name = n;
        s = rand() % 9 + 1;
        d = rand() % 9 + 1;
        e = rand() % 9 + 1;
        i = rand() % 9 + 1;
        c = rand() % 9 + 1;
    }
    void make_character();
    void save_character() {}
};
void monster::make_character()
{
    fstream file;
    file.open("Monsters.txt", ios::in | ios::out | ios::app);
    file << "========" << name << "========" << endl;
    file << "Strength:          " << s << endl;
    file << "Dexterity:         " << d << endl;
    file << "Endurance:         " << e << endl;
    file << "Intelligence:      " << i << endl;
    file << "Charisma:          " << c << "\n"
         << endl;
}
#endif // RPG_CPP_MONSTERS_H