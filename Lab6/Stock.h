#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

class Stock {
    public:
    int quantity, product;
    int stock[5];
    string item[5] = {"Cookies", "Snickers", "Energy Drink", "Water", "Chips"};

    void getstock()
{
    fstream file;
    file.open("stock.txt", ios::in | ios::out);
    file.seekg(+23, std::ios_base::beg);
    file >> stock[0];
    file.seekg(+48, std::ios_base::beg);
    file >> stock[1];
    file.seekg(+74, std::ios_base::beg);
    file >> stock[2];
    file.seekg(+100, std::ios_base::beg);
    file >> stock[3];
    file.seekg(+126, std::ios_base::beg);
    file >> stock[4];
}

void writing()
{
    fstream file;
    file.open("stock.txt", ios::in | ios::out | ios::trunc);
    file << "1.Cookies       Stock: " << stock[0] << endl;
    file << "2.Sneakers      Stock: " << stock[1] << endl;
    file << "3.Energy Drink  Stock: " << stock[2] << endl;
    file << "4.Water         Stock: " << stock[3] << endl;
    file << "5.Chips         Stock: " << stock[4] << endl;
    for (int i = 0; i < 5; i++)
    {
        if (stock[i] == 0)
            file << item[i] << " will be restocked by 9" << endl;
    }
}

void restocking()
{
    fstream file;
    file.open("stock.txt", ios::in | ios::out);
    file.seekg(+127, std::ios_base::beg);
    string an[6];

    for (int i = 0; i < 6; i++)
    {
        getline(file, an[i]);
        if (an[i] == "Cookies will be restocked by 9")
        {
            stock[0] = stock[0] + 9;
            writing();
        }
        if (an[i] == "Snickers will be restocked by 9")
        {
            stock[1] = stock[1] + 9;
            writing();
        }
        if (an[i] == "Energy Drink will be restocked by 9")
        {
            stock[2] = stock[2] + 9;
            writing();
        }
        if (an[i] == "Water will be restocked by 9")
        {
            stock[3] = stock[3] + 9;
            writing();
        }
        if (an[i] == "Chips will be restocked by 9")
        {
            stock[4] = stock[4] + 9;
            writing();
        }
    }
}

void menu()
{
    cout << "=========|| Please choose an item ||=========\n"
         << "1. " << item[0] << "\tStock: " << stock[0] << "\tPrice : 2$"
         << "\n2. " << item[1] << "\tStock: " << stock[1] << "\tPrice : 3$"
         << "\n3. " << item[2] << "\tStock: " << stock[2] << "\tPrice : 5$"
         << "\n4. " << item[3] << "\tStock: " << stock[3] << "\tPrice : 2$"
         << "\n5. " << item[4] << "\tStock: " << stock[4] << "\tPrice : 4$"
         << "\n6.Finish purchase " << endl;
}

};