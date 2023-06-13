#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Character
{
private:
    friend class mage;
    friend class warrior;
    friend class berserker;
    friend class theif;

public:
    int s, d, e, i, c, type;
    string name, cls;
    void make_character()
    {
        cout << "Enter Character name: ";
        cin >> name;
        cout << "Enter Character strength between 0 and 10: ";
        cin >> s;
        while (1)
        {
            if (s < 0 || s > 10)
            {
                cout << "Please input a proper number: ";
                cin >> s;
            }
            else
                break;
        }
        cout << "Enter Character dexterity between 0 and 10: ";
        cin >> d;
        while (1)
        {
            if (d < 0 || d > 10)
            {
                cout << "Please input a proper number: ";
                cin >> d;
            }
            else
                break;
        }
        cout << "Enter Character endurance between 0 and 10: ";
        cin >> e;
        while (1)
        {
            if (e < 0 || e > 10)
            {
                cout << "Please input a proper number: ";
                cin >> e;
            }
            else
                break;
        }
        cout << "Enter Character intelligence between 0 and 10: ";
        cin >> i;
        while (1)
        {
            if (i < 0 || i > 10)
            {
                cout << "Please input a proper number: ";
                cin >> i;
            }
            else
                break;
        }
        cout << "Enter Character charisma between 0 and 10: ";
        cin >> c;
        while (1)
        {
            if (c < 0 || c > 10)
            {
                cout << "Please input a proper number: ";
                cin >> c;
            }
            else
                break;
        }
        cout << "Choose character class: \n 1. Mage\n 2. Warrior\n 3. Berserker\n 4. Theif" << endl;
        cin >> type;
        while (1)
        {
            if (type != 1 && type != 2 && type != 3 && type != 4)
            {
                cout << "Enter a proper choice." << endl;
                cout << "Choose character class: \n 1. Mage\n 2. Warrior\n 3. Berserker\n 4. Theif" << endl;
                cin >> type;
                if (type == 1) {
                    cls = "Mage";
                }
                else if (type == 2) {
                    cls = "Warrior";
                }
                else if (type == 3) {
                    cls = "Berserker";
                }
                else {
                    cls = "Theif";
                }
            }
            else
                break;
        }
        cout << "A character with name " << name << " has been created" << endl;
    }

    void save_character(){
        cout << i << endl;
        fstream file;
        file.open(name + ".txt", ios::in | ios::out | ios::trunc);
        file << "The Character name is: " << name << endl;
        file << "The Character strength is: " << s << endl;
        file << "The Character dexterity is: " << d << endl;
        file << "The Character endurance is: " << e << endl;
        file << "The Character intelligence is: " << i << endl;
        file << "The Character charisma is: " << c << endl;
        file << "The Character class is: " << cls << endl;
    }

    void get_character()
    {
        cout << "Input character name: ";
        cin >> name;
        fstream file;
        file.open(name + ".txt", ios::in | ios::out);
        file.seekg(+57, std::ios_base::beg);
        file >> s;
        file.seekg(+88, std::ios_base::beg);
        file >> d;
        file.seekg(+119, std::ios_base::beg);
        file >> e;
        file.seekg(+153, std::ios_base::beg);
        file >> i;
        file.seekg(+183, std::ios_base::beg);
        file >> c;
        cout << name << " has been laoded successfuly!" << endl;
        cout << "Strength is: " << s << endl;
        cout << "Dexterity is: " << d << endl;
        cout << "Endurance is: " << e << endl;
        cout << "Intelligence is: " << i << endl;
        cout << "Charisma is: " << c << endl;
    }

    int get_type(){
        return type;
    }
};