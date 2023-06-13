#ifndef LAB16_MECHANICS_H
#define LAB16_MECHANICS_H
#include "template.h"
#include "BattleHistory.h"
#include "Inventory.h"
#include <fstream>
#include <sstream>
#include <time.h>
stringstream s1,s2;
string st,st2;
template <class T>
class score
{
    T pointH = 0, pointM = 0;
    T countH = 0, countM = 0;
    T R = 0;
    string item[7];

public:
    void comparison(atrributes &hero, monster &mons);
    void winner(atrributes &hero, monster &mons, int i, int count,inv_list &n,int stock[]);
    void overall(Character &C, Battle_list &l, BattleH *p, int i);
    void save_battle(int i, int count);
    void show_battle(int d);
    void items();
    string drop();
    int stocks(int stock[], string x);
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
void score<T>::items()
{
    fstream file;
    file.open("items.txt", ios::in | ios::out);
    if (file.good() == true)
    {
        for (int i = 0; i < 7; i++)
        {
            getline(file, item[i]);
        }
    }
}
template <class T>
void score<T>::save_battle(int i, int count)
{
    fstream battle;
    string name;
    stringstream ss;
    stringstream battlenum;
    string battlecount;
    string num;
    battlenum << count;

    battlenum >> battlecount;
    ss << i;
    name = "Battle" + battlecount;
    battle.open(name + ".txt", ios::in | ios::out | ios::app);
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
void score<T>::winner(atrributes &hero, monster &mons, int i, int count,inv_list &n,int stock[])
{
    bool win;
    string a;
    a=drop();
    cout << a << endl;
    if (pointH > pointM)
    {
        cout << "=======Total score======\n";

        cout << "\t" << pointH << " - " << pointM << "\n";

        cout << "winner is Hero\n";
             if(a=="") {
            cout << "No drop..kill another monster for a better chance"<<endl;
            cout << "-------------------------\n";
        }
        else{
            cout << "Good news!..you had a drop: " << a <<endl;
            if(n.find_item(a)){

                s1 << stocks(stock,a);
                s1 >> st;

                n.delete_element(a);
                n.add_after((a+" x "+st),n.get_postion());

            }
            else if (n.find_item(a+" x "+st)){
                n.delete_element(a+ " x "+st);
                s1 << stocks(stock,a);
                s1 >> st;
                n.add_after((a+" x "+st),n.get_postion());

            }
            else {
                n.create_list(a);
                cout << "-------------------------\n";
            }
        }


        save_battle(i,count);
        countH++;
        pointH=0,pointM=0;
        win =true;
    }
    else {
        cout << "=======Total score======\n";

        cout << "\t"<<pointH<<" - "<<pointM<<"\n";

        cout << "winner is Monster\n";

        cout << "-------------------------\n";


        save_battle(i, count);
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

template <class T>
void score<T>::overall(Character &C, Battle_list &l, BattleH *p, int i)
{
    stringstream s1, s2;
    string HS, MS;

    if (countH > countM)
    {
        cout << "=======Overall score======\n";
        cout << "\t" << countH << " - " << countM << "\n";
        cout << "Final winner is Hero" << endl;
        s1 << countH;
        s1 >> HS;
        s2 << countM;
        s2 >> MS;
        p = new BattleH;
        p->key = i;
        p->winners = "Winner Hero << " + HS + " - " + MS + " >>\n";
        l.push_tail(p);
        cout << "Congrats your hero level is : " << C.level << endl;
        cout << "your experience is : " << C.experience << endl;
    }
    else
    {
        cout << "=======Overall score======\n";
        cout << "\t" << countH << " - " << countM << "\n";
        cout << "Unfortunetely, you died Final winner is monster upgrade your stats and come back stronger :)\n"
             << endl;
        s1 << countH;
        s1 >> HS;
        s2 << countM;
        s2 >> MS;
        p = new BattleH;
        p->key = i;
        p->winners = "Winner Monster << " + HS + " - " + MS + " >>\n";
        l.push_tail(p);
    }
}
template <class T>
string score<T>::drop()
{
    items();
    cout << item[0] << endl;
    float perc;
    int luck;
    srand(time(0));
    perc = rand() % 100 + 0;
    if (perc <= 25)
    {
        luck = rand() % 3 + 1;

        if (luck == 1)
        {

            return item[0];
        }
        else if (luck == 2)
        {

            return item[4];
        }
        else if (luck == 3)
        {
            return "";
        }
    }
    else if (perc <= 25 | perc <= 70)
    {
        luck = rand() % 3 + 1;

        if (luck == 1)
        {

            return item[1];
        }
        else if (luck == 2)
        {

            return item[3];
        }
        else if (luck == 3)
        {
            return "";
        }
    }
    else if (perc >= 70)
    {
        luck = rand() % 3 + 1;

        if (luck == 1)
        {

            return item[2];
        }
        else if (luck == 2)
        {
            return item[5];
        }
        else if (luck == 3)
        {
            return "";
        }
    }
}
template <class T>
int score<T>::stocks(int stock[], string x)
{
    if (x == "Legendary Sword of Ice")
    {
        stock[0] += 1;

        return stock[0];
    }
    else if (x == "Rare Armor of Spikes")
    {
        stock[1] += 1;

        return stock[1];
    }
    else if (x == "Common Bronze Dagger")
    {
        stock[2] += 1;

        return stock[2];
    }
    else if (x == "Rare Steel Armor")
    {
        stock[3] += 1;

        return stock[3];
    }
    else if (x == "Legendary Godess Staff")
    {
        stock[4] += 1;

        return stock[4];
    }
    else if (x == "common Bronze Sword")
    {
        stock[5] += 1;
        return stock[5];
    }
    return 0;
}
#endif // LAB16_MECHANICS_H