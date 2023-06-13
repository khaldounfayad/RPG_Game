#ifndef LAB16_BATTLEHISTORY_H
#define LAB16_BATTLEHISTORY_H
#include <iostream>
using namespace std;

struct BattleH
{
    string winners;
    int key;
    BattleH *next;
};

class Battle_list {
private:
    BattleH *head, *tail;
    int cnt;
public:
    Battle_list(){
        head = nullptr;
        tail = nullptr;
        cnt =0;
    }
    ~Battle_list()
    {
        BattleH * el;
        while(head)
        {
            el = head->next;
            delete head;
            head = el;
        }
    }
    BattleH *push_tail(BattleH *el){
        if(tail) tail->next = el;
        el->next = nullptr;
        tail = el;
        if(!head) head = tail;
        cnt++;
        return tail;
    }
    void showNames()
    {
        BattleH * el =head;
        if(!head) cout << "List is empty." << endl;
        else
        {
            while(el != nullptr)
            {
                cout << el->key <<"."<<el->winners << "\n";
                el = el->next;
            }
            cout << endl;

        }
    }
    bool keys(int d){
        BattleH * el =head;
        while(el != nullptr)
        {
            if(d == el->key){
                return true;
            } el = el->next;
        }
    }
};
#endif //LAB16_BATTLEHISTORY_H