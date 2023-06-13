#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int c=10, s=30, e=15, w=25, h=20;
int quantity, product;

void calculate(int product);

void menu(){
    cout << "=========|| Please choose an item ||=========\n"
        << "1.Cookies \t " << "Stock: " << c << "\tPrice : 2$"
         << "\n2.Chocolate \t " << "Stock: " << s << "\tPrice : 3$"
         << "\n3.Energy Drink \t " << "Stock: "<< e << "\tPrice : 5$"
         << "\n4.Water  \t " << "Stock: "<< w << "\tPrice : 2$"
         << "\n5.Chips  \t " << "Stock: "<< h << "\tPrice : 4$"
         << "\n6.Finish purchase "<< endl;
}

void stock(){
    fstream file;
    file.open("stock.txt", ios::in | ios::out);
    if (c == 0) {
        file << "Please replenish the cookies";
    }
    if (s == 0) {
        file << "Please replenish the chocolates";
    }
    if (e == 0) {
        file << "Please replenish the energy drinks";
    }
    if (w == 0) {
        file << "Please replenish the water";
    }
    if (h == 0) {
        file << "Please replenish the chips";
    }
    else {
    file << "1.Cookies  " << "Stock: " << c;
    file << "\n2.Chocolate \t " << "Stock: " << s;
    file << "\n3.Energy Drink \t " << "Stock: "<< e;
    file << "\n4.Water  \t " << "Stock: "<< w;
    file << "\n5.Chips  \t " << "Stock: "<< h;
    }
}

int main() {
    stock();
    while (c > 0 | s > 0 | e > 0 | w > 0 | h > 0){
        menu();
        cin >> product;
        if (product == 6){
            cout << "Thanks for purchasing\n\n" << endl;
        }
        else if (product == 1234){
            exit(0);
        }
        else if (product > 6) {
            cout << "Enter a valid product number\n\n" << endl;
        }
        else{
        cout << "Enter the quantity\n";
        cin >> quantity;
        calculate(product);
        }
    }
    return 0;
}

void calculate(int product) {

    switch (product) {

        case 1: {
            while (1) {
                if (c == 0) {
                    cout << "Out of Stock" << endl;
                } else if (quantity > c) {
                    cout << "Enter a valid number" << endl;
                    cin >> quantity;
                } else {
                    c = c - quantity;
                    cout << "Thank you! Please choose another item or finish purchase" << endl;
                }
                break;
            }
            break;
        }

        case 2:
            while (2) {
                if (s == 0) {
                    cout << "Out of Stock" << endl;
                } else if (quantity > s) {
                    cout << "Enter a valid number" << endl;
                    cin >> quantity;
                } else {
                    s = s - quantity;
                    cout << "Thank you! Please choose another item or finish purchase" << endl;
                }
                break;
            }
            break;

        case 3:
            while (3) {
                if (e == 0) {
                    cout << "Out of Stock" << endl;
                } else if (quantity > e) {
                    cout << "Enter a valid number" << endl;
                    cin >> quantity;
                } else {
                    e = e - quantity;
                    cout << "Thank you! Please choose another item or finish purchase" << endl;
                }
                break;
            }
            break;

        case 4:
            while (4) {
                if (w == 0) {
                    cout << "Out of Stock" << endl;
                } else if (quantity > w) {
                    cout << "Enter a valid number" << endl;
                    cin >> quantity;
                } else {
                    w = w - quantity;
                    cout << "Thank you! Please choose another item or finish purchase" << endl;
                }
                break;
            }
            break;

        case 5:
            while (5) {
                if (h == 0) {
                    cout << "Out of Stock" << endl;
                } else if (quantity > h) {
                    cout << "Enter a valid number" << endl;
                    cin >> quantity;
                } else {
                    h = h - quantity;
                    cout << "Thank you! Please choose another item or finish purchase" << endl;
                }
                break;
            }
            break;
        default:
            cout << "Enter a valid product number or finish purchase" << endl;
    }
}
