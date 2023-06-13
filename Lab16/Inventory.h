#ifndef LAB16_INVERNTORY_H
#define LAB16_INVERNTORY_H
#include <iostream>
using namespace std;
struct invlist
{
    string itemlist;
    int keys;
    struct invlist *next;
    struct invlist *prev;
} *start;

class inv_list
{
private:
    int c = 1;

public:
    inv_list()
    {
        start = NULL;
    }
    void create_list(string value);
    void add_item(string value);
    void display_items();
    bool find_item(string x);
    void delete_element(string value);
    void add_after(string value, int pos);
    int get_postion();
};

void inv_list::create_list(string value)
{
    struct invlist *s, *temp;
    temp = new (struct invlist);
    temp->itemlist = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
void inv_list::add_item(string value)
{
    if (start == NULL)
    {
        cout << "First Create the list." << endl;
        return;
    }
    struct invlist *temp;
    temp = new (struct invlist);
    temp->next = NULL;
    temp->itemlist = value;
    temp->prev = start;
    start->next = temp;
    start = temp;
}
void inv_list::display_items()
{
    struct invlist *q;
    int cnt = 1;
    if (start == NULL)
    {
        cout << "List empty,nothing to display" << endl;
        return;
    }
    q = start;
    cout << "Your inventory is:" << endl;
    while (q != NULL)
    {
        cout << " - " << q->itemlist << endl;
        q = q->next;
        cnt++;
    }
}
void inv_list::delete_element(string value)
{
    struct invlist *tmp, *q;
    /*first element deletion*/
    if (start->itemlist == value)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {
        /*Element deleted in between*/
        if (q->next->itemlist == value)
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            free(tmp);
            return;
        }
        q = q->next;
    }
    /*last element deleted*/
    if (q->next->itemlist == value)
    {
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        return;
    }
}
void inv_list::add_after(string value, int pos)
{
    if (start == NULL)
    {
        cout << "First Create the list." << endl;
        return;
    }
    struct invlist *tmp, *q;
    int i;
    q = start;

    tmp = new (struct invlist);
    tmp->itemlist = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
}
bool inv_list::find_item(string x)
{
    struct invlist *q = start;

    while (q != NULL)
    {
        if (x == q->itemlist)
        {
            return true;
        }
        c++;
        q = q->next;
    }
    return false;
}
int inv_list::get_postion()
{
    return c;
}
#endif // LAB16_INVERNTORY_H