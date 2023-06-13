#ifndef LAB16_TEMPLATE_H
#define LAB16_TEMPLATE_H
#include <iostream>
using namespace std;

class atrributes
{
public:
    string name;
    string cls;
    int type;
    int s;
    int d;
    int e;
    int i;
    int c;
    int experience;
    int level = 1;
    virtual void make_character() = 0;
    virtual void save_character() = 0;
    virtual void get_stats(string n) = 0;
    friend class Character;
    friend class monster;
    friend class mage;
    friend class warrior;
    friend class berserker;
    friend class theif;
    template <class comparison>
    friend class score;
};
#endif // LAB16_TEMPLATE_H