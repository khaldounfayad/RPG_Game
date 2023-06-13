#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Stock.h"
#include "Vending.h"
using namespace std;

int main()
{
    Stock s;
    Vending v;
    s.getstock();
    s.restocking();
    v.cashpoolbase(v.cashpool);
    while (s.stock[0] > 0 | s.stock[1] > 0 | s.stock[2] > 0 | s.stock[3] > 0 | s.stock[4] > 0)
    {
        s.menu();
        s.getstock();
        cin >> v.product;
        if (v.product == 6)
        {
            cout << "Thanks for purchasing\n\n"
                 << endl;
        }
        else if (v.product == 123)
        {
            exit(0);
        }
        else if (v.product == 321){
            v.editpool(v.cashpool);
            v.cashpoolbase(v.cashpool);
        }
        else if (v.product > 6)
        {
            cout << "Enter a valid product number\n\n"
                 << endl;
        }
        else
        {
            cout << "Enter the quantity\n";
            cin >> s.quantity;
            v.calculate(v.product,s.quantity,s.stock);
            s.writing();
            v.calculatemoney(v.product);
            v.cashpoolbase(v.cashpool);
        }
    }
    return 0;
}