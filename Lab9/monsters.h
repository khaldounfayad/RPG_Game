#include "Character.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#ifndef RPG_CPP_MONSTERS_H
#define RPG_CPP_MONSTERS_H
class monster : public Character{
public :
    void get_stats(string n){
        name =n;
        s = rand() % 10+1;
        d = rand() % 10+1;
        e = rand() % 10+1;
        i = rand() % 10+1;
        c= rand() % 10+1;
    }
    void create_mons();
};
void monster:: create_mons(){
    fstream file;
    file.open("Monsters.txt", ios::in | ios::out | ios::app);
    file << "========" << name << "========" << endl;
    file << "Strength:          " << s << endl;
    file << "Dexterity:         " << d  << endl;
    file << "Endurance:         " << e << endl;
    file << "Intelligence:      " << i << endl;
    file << "Charisma:          " << c << "\n"<<endl;
}

#endif //RPG_CPP_MONSTERS_H
