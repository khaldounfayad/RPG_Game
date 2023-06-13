#ifndef LAB15_MECHANICS_H
#define LAB15_MECHANICS_H
#include "template.h"
#include "BattleHistory.h"
#include <fstream>
#include <sstream>
template <class T>
class score{
    T pointH=0,pointM=0;
    T countH=0,countM=0;
    T R=0;
public:

    void comparison(atrributes & hero,monster & mons);
    void winner(atrributes & hero,monster & mons,int i, int count);
    void overall(Character & C,Battle_list & l,BattleH *p,int i);
    void save_battle(int i, int count);
    void show_battle(int d);


};
template<class T>
void score<T> :: show_battle(int d){
    fstream file;
    string name;
    stringstream s;
    string num;
    s<<d;
    s>>num;
    name = "Battle"+num;
    file.open(name+".txt",ios::in | ios::out );
    if (file.good() == true) {
        string inscr[30];
        for (int i = 0; i < 30; i++) {
            getline(file, inscr[i]);
            cout << inscr[i] << endl;
        }
    }
    else
        cout << "File not found!\n";
}
template<class T>
void score<T> ::save_battle(int i,int count){
    fstream battle;
    string name;
    stringstream ss;
    stringstream battlenum;
    string battlecount;
    string num;
    battlenum << count;
    
    battlenum >> battlecount;
    ss<<i;
    name = "Battle"+battlecount;
    battle.open(name+".txt", ios::in | ios::out | ios::app);
    battle << "=======Total score======\n"<<endl;
    battle << "\t"<<pointH<<" - "<<pointM<<"\n"<<endl;
    if (pointH >pointM){
        battle<< "winner is Hero"<<endl;
    }
    else {
        battle << "winner is monster"<<endl;
    }

}

template <class T>
void score<T> :: comparison(atrributes & hero,monster & mons){
    if (hero.s > mons.s) {
        pointH++;
    }
    else{
        pointM++;
    }
   if (hero.d > mons.d) {
       pointH++;
   }
   else {
        pointM++;
   }
    if (hero.e > mons.e) {
        pointH++;
    }else {
        pointM++;
    }
    if (hero.i> mons.i) {
        pointH++;
    }else {
        pointM++;
    }
    if (hero.c > mons.c) {
        pointH++;
    }else {
        pointM++;
    }
}

template <class T>
void score<T> :: winner(atrributes & hero,monster & mons,int i,int count){
    bool win;
    if (pointH > pointM ){
        cout << "=======Total score======\n";

        cout << "\t"<<pointH<<" - "<<pointM<<"\n";

        cout << "winner is Hero\n";

        cout << "-------------------------\n";

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

        save_battle(i,count);
        countM++;
        pointH=0,pointM=0;
        win = false;
    }
    if (win) {
        hero.experience += mons.experience;
    }
    else {

        hero.experience -= mons.experience;

    }
    if(hero.experience < 0){
        if (hero.level == 1){
            hero.experience = 0;
        }
        else {
            hero.level--;
            cout << "Ops, you have been leveled down due to experience running out\n";
            hero.experience = 0;
        }
    }
    else if (hero.experience == 10){
        hero.level++;
        hero.experience -= 10;
    }
}

template <class T>
void score<T> :: overall(Character & C,Battle_list & l,BattleH *p,int i){
    stringstream s1,s2;
    string HS,MS;

    if (countH >countM) {
        cout << "=======Overall score======\n";
        cout << "\t"<<countH << " - " << countM << "\n";
        cout <<"Final winner is Hero"<<endl;
        s1<<countH;
        s1>>HS;
        s2<<countM;
        s2>> MS;
        p = new BattleH;
        p->key = i;
        p->winners ="Winner Hero << "+HS+" - "+MS+" >>\n";
        l.push_tail(p);
        cout << "Congrats your hero level is : " << C.level << endl;
        cout << "your experience is : " << C.experience <<endl;
    }
    else {
        cout << "=======Overall score======\n";
        cout << "\t"<<countH << " - " << countM << "\n";
        cout << "Unfortunetely, you died Final winner is monster upgrade your stats and come back stronger :)\n"<< endl;
        s1<<countH;
        s1>>HS;
        s2<<countM;
        s2>> MS;
        p= new BattleH;
        p->key = i;
        p->winners ="Winner Monster << "+HS+" - "+MS+" >>\n";
        l.push_tail(p);
    }
}
#endif //LAB15_MECHANICS_H