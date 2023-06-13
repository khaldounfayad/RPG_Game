#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int quantity, product;
int stock[5];
double price[5] = {2, 3, 5, 2, 4};
int cashpool[6] = {4, 5, 10, 10, 20, 10};
string item[5] = {"Cookies", "Snickers", "Energy Drink", "Water", "Chips"};
double p = 0;
double total = 0;
double change = 0;

void cashpoolbase(int *m){
    fstream file;
    file.open("cash_p.txt", ios::in | ios::out | ios::trunc);
    file <<  " ====== Coins: ===========  Amount left:======"  <<endl;
    file <<  "          5$         x      \t  "  <<  *m << endl;
    m++;
    file <<  "          2$         x      \t  "   << *m << endl;
    m++;
    file <<  "          1$         x      \t  "   << *m << endl;
    m++;
    file <<  "          0.5$       x      \t  "   << *m << endl;
    m++;
    file <<  "          0.2$       x      \t  "   << *m << endl;
    m++;
    file <<  "          0.1$       x      \t  "   << *m << endl;
    file << '\n';
}

void get_change(int cashpool[], int num, double total)
{
    change = total - p;
    double coin_values[] = {5, 2, 1, 0.5, 0.2, 0.1};
    int remaining_change = (int)(change * 10);
    int coins_to_return[6] = {0};

    for (int i = 0; i < num; i++)
    {
        int num_coins_of_value = remaining_change / (int)(coin_values[i] * 10);
        int num_coins_to_use = min(num_coins_of_value, cashpool[i]);
        coins_to_return[i] = num_coins_to_use;
        remaining_change -= num_coins_to_use * (int)(coin_values[i] * 10);
    }
    if (remaining_change > 0)
    {
        cout << "Error: insufficient change in cashpool." << endl;
        return;
    }
    cout << "Coins to return:" << endl;
    for (int i = 0; i < 6; i++)
    {
        if (coins_to_return[i] > 0)
        {
            cout << coins_to_return[i] << " coins of value " << coin_values[i] << endl;
            cashpool[i]--;
        }
    }
}

void cashpooladd(int coin, int num)
{
    int *cashpool_p;
    cashpool_p = cashpool;
    switch (coin)
    {
    case 1:
        cashpool_p[0] += num;
        break;
    case 2:
        cashpool_p[1] += num;
        break;
    case 3:
        cashpool_p[2] += num;
        break;
    case 4:
        cashpool_p[3] += num;
        break;
    case 5:
        cashpool_p[4] += num;
        break;
    case 6:
        cashpool_p[5] += num;
        break;
    }
}

void calculatemoney(int product)
{
    int *cashpool_p;
    cashpool_p = cashpool;
    int coin = 0;
    int num = 0;
    double coin_values[] = {5, 2, 1, 0.5, 0.2, 0.1};

    while (coin != 7)
    {
        cout << "\nPlease choose which coin you will be paying with: \n1. 5 PLN\n2. 2 PLN\n3. 1 PLN\n4. 0.5 PLN\n5. 0.2 PLN\n6. 0.1 PLN\n7. Finish\n";
        cin >> coin;
        if (coin == 1 | coin == 2 | coin == 3 | coin == 4 | coin == 5 | coin == 6)
        {
            cout << "Enter the number of coins specified: ";
            cin >> num;
            total += num * coin_values[coin - 1];
            cout << coin_values[coin - 1] << endl;
            cout << total << endl;
            cashpooladd(coin, num);
            if (total < p)
            {
                cout << "Insuficient amount please pay by card" << endl;
                break;
            }
            else if (total == p)
            {
                cout << "Thank you for your purchase" << endl;
                break;
            }
            else
            {
                get_change(cashpool, num, total);
                break;
            }
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

void calculate(int product)
{
    switch (product)
    {
    case 1:
    {
        while (1)
        {
            if (stock[0] == 0)
            {
                cout << "Out of Stock" << endl;
            }
            else if (quantity > stock[0])
            {
                cout << "Enter a valid number" << endl;
                cin >> quantity;
            }
            else
            {
                stock[0] = stock[0] - quantity;
                p = price[0] * quantity;
                cout << "Thank you! your total is " << p << endl;
            }
            break;
        }
        break;
    }

    case 2:
        while (2)
        {
            if (stock[1] == 0)
            {
                cout << "Out of Stock" << endl;
            }
            else if (quantity > stock[1])
            {
                cout << "Enter a valid number" << endl;
                cin >> quantity;
            }
            else
            {
                stock[1] = stock[1] - quantity;
                p = price[1] * quantity;
                cout << "Thank you! your total is " << p << endl;
            }
            break;
        }
        break;

    case 3:
        while (3)
        {
            if (stock[2] == 0)
            {
                cout << "Out of Stock" << endl;
            }
            else if (quantity > stock[2])
            {
                cout << "Enter a valid number" << endl;
                cin >> quantity;
            }
            else
            {
                stock[2] = stock[2] - quantity;
                p = price[2] * quantity;
                cout << "Thank you! your total is " << p << endl;
            }
            break;
        }
        break;

    case 4:
        while (4)
        {
            if (stock[3] == 0)
            {
                cout << "Out of Stock" << endl;
            }
            else if (quantity > stock[3])
            {
                cout << "Enter a valid number" << endl;
                cin >> quantity;
            }
            else
            {
                stock[3] = stock[3] - quantity;
                p = price[3] * quantity;
                cout << "Thank you! your total is " << p << endl;
            }
            break;
        }
        break;

    case 5:
        while (5)
        {
            if (stock[4] == 0)
            {
                cout << "Out of Stock" << endl;
            }
            else if (quantity > stock[4])
            {
                cout << "Enter a valid number" << endl;
                cin >> quantity;
            }
            else
            {
                stock[4] = stock[4] - quantity;
                p = price[4] * quantity;
                cout << "Thank you! your total is " << p << endl;
            }
            break;
        }
        break;
    default:
        cout << "Enter a valid product number or finish purchase" << endl;
    }
}

void showpool(int *amount){
    cout <<  "   Coins:           Amount left:"  <<endl;
    cout <<  "    5$         x      "   << *amount << endl;
    amount++;
    cout <<  "    2$         x      "   << *amount << endl;
    amount++;
    cout <<  "    1$         x      "   << *amount << endl;
    amount++;
    cout <<  "    0.5$       x      "   << *amount << endl;
    amount++;
    cout <<  "    0.2$       x      "   << *amount << endl;
    amount++;
    cout <<  "    0.1$       x      "   << *amount << endl;
}

void editpool(int *amount){
    int inc[6];
    int c;
    cout << "-------------||You have entered the cash pool edit menu||------------- \n"
         << "\n1.Increase Money  "
         << "\n2.Collect Money "
         << endl;
    cin>>c;
    switch(c) {
        case 1: {
            for (int i = 0; i < 6; i++) {
                cout << "How much would you like to increase ";
                if (i == 0) cout << "coin 5:";
                if (i == 1) cout << "coin 2: ";
                if (i == 2) cout << "coin 1: ";
                if (i == 3) cout << "coin 0.5: ";
                if (i == 4) cout << "coin 0.2: ";
                if (i == 5) cout << "coin 0.1: ";
                cin >> inc[i];
                cout << endl;
            }
            for (int j = 0; j < 6; j++) {
                amount[j] += inc[j];
            }
            showpool(amount);
            break;
        }
        case 2: {
            cout << "***Type Negative before the quantity*** " <<endl;
            for (int i = 0; i < 6; i++) {
                cout << "How much would you like to collect of  ";
                if (i == 0) cout << "coin 5:";
                if (i == 1) cout << "coin 2: ";
                if (i == 2) cout << "coin 1: ";
                if (i == 3) cout << "coin 0.5: ";
                if (i == 4) cout << "coin 0.2: ";
                if (i == 5) cout << "coin 0.1: ";
                cin >> inc[i];
                cout << endl;
            }
            for (int j = 0; j < 6; j++) {
                amount[j] += inc[j];
            }
            showpool(amount);
            break;
        }
    }
}

int main()
{
    int *cashpool_p=cashpool;
    getstock();
    restocking();
    cashpoolbase(cashpool_p);
    while (stock[0] > 0 | stock[1] > 0 | stock[2] > 0 | stock[3] > 0 | stock[4] > 0)
    {
        menu();
        getstock();
        cin >> product;
        if (product == 6)
        {
            cout << "Thanks for purchasing\n\n"
                 << endl;
        }
        else if (product == 123)
        {
            exit(0);
        }
        else if (product == 321){
            editpool(cashpool_p);
            cashpoolbase(cashpool_p);
        }
        else if (product > 6)
        {
            cout << "Enter a valid product number\n\n"
                 << endl;
        }
        else
        {
            cout << "Enter the quantity\n";
            cin >> quantity;
            calculate(product);
            writing();
            calculatemoney(product);
            cashpoolbase(cashpool_p);
        }
    }
    return 0;
}