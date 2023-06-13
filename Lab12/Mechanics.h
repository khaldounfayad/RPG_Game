#ifndef LAB12_MECHANICS_H
#define LAB12_MECHANICS_H
#include "template.h"
#include <fstream>
#include <sstream>
template <class T>
class score
{
    T pointH = 0, pointM = 0;
    T countH = 0, countM = 0;
    int R = 0;

public:
    void comparison(atrributes &hero, monster &mons);
    void winner(atrributes &hero, monster &mons, int i);
    void save_battle(int i);
    void show_battle(int d);
};
template <class T>
void score<T>::show_battle(int d)
{
    fstream file;
    string name;
    stringstream s;
    string num;
    s << d;
    s >> num;
    name = "Battle" + num;
    file.open(name + ".txt", ios::in | ios::out);
    if (file.good() == true)
    {
        string inscr[30];
        for (int i = 0; i < 30; i++)
        {
            getline(file, inscr[i]);
            cout << inscr[i] << endl;
        }
    }
    else
        cout << "File not found!\n";
}
template <class T>
void score<T>::save_battle(int i)
{
    fstream battle;
    string name;
    stringstream ss;
    string num;
    ss << i;
    ss >> num;
    name = "Battle" + num;
    battle.open(name + ".txt", ios::in | ios::out | ios::app);
    battle << "Round " << ++R << endl;
    battle << "=======Total score======\n"
           << endl;
    battle << "\t" << pointH << " - " << pointM << "\n"
           << endl;
    if (pointH > pointM)
    {
        battle << "winner is Hero" << endl;
    }
    else
    {
        battle << "winner is monster" << endl;
    }
}

template <class T>
void score<T>::comparison(atrributes &hero, monster &mons)
{
    cout << hero.s << "\t" << mons.s << endl;
    if (hero.s > mons.s)
    {
        pointH++;
    }
    else
    {
        pointM++;
    }
    if (hero.d > mons.d)
    {
        pointH++;
    }
    else
    {
        pointM++;
    }
    if (hero.e > mons.e)
    {
        pointH++;
    }
    else
    {
        pointM++;
    }
    if (hero.i > mons.i)
    {
        pointH++;
    }
    else
    {
        pointM++;
    }
    if (hero.c > mons.c)
    {
        pointH++;
    }
    else
    {
        pointM++;
    }
}

template <class T>
void score<T>::winner(atrributes &hero, monster &mons, int i)
{
    bool win;
    if (pointH > pointM)
    {
        cout << "=======Total score======\n";

        cout << "\t" << pointH << " - " << pointM << "\n";

        cout << "winner is Hero\n";

        cout << "-------------------------\n";

        save_battle(i);
        countH++;
        pointH = 0, pointM = 0;
        win = true;
    }
    else
    {
        cout << "=======Total score======\n";

        cout << "\t" << pointH << " - " << pointM << "\n";

        cout << "winner is Monster\n";

        cout << "-------------------------\n";

        save_battle(i);
        countM++;
        pointH = 0, pointM = 0;
        win = false;
    }
    if (win)
    {
        hero.experience += mons.experience;
    }
    else
    {

        hero.experience -= mons.experience;
    }
    if (hero.experience < 0)
    {
        if (hero.level == 1)
        {
            hero.experience = 0;
        }
        else
        {
            hero.level--;
            cout << "Ops, you have been leveled down due to experience running out\n";
            hero.experience = 0;
        }
    }
    else if (hero.experience == 10)
    {
        hero.level++;
        hero.experience -= 10;
    }
}
#endif // LAB12_MECHANICS_H