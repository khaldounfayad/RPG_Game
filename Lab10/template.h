
#ifndef LAB10_TEMPLATE_H
#define LAB10_TEMPLATE_H
#include <iostream>
using namespace std;

class atrributes {
    string name;
    string cls;
    int type;
    int s;
    int d;
    int e;
    int i;
    int c;
public :
    // virtual void assign_attr(string n, int s, int d, int e, int i, int c,string cls) = 0;
    virtual void make_character() = 0;
    virtual void save_character() = 0;
    virtual void get_character() = 0;
    friend class Character;
    friend class monster;
    friend class mage;
    friend class warrior;
    friend class berserker;
    friend class theif;
};





#endif //LAB10_TEMPLATE_H
