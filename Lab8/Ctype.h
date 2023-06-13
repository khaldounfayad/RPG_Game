#include <iostream>
using namespace std;
#include "Character.h"

class mage{
public :
    void stats(Character & profile){
        profile.i = 9;
        profile.save_character();
    }
};
class warrior {
public :
    void stats(Character & profile) {
        profile.e = 9;
        profile.save_character();
    }
};
class berserker {
public :
    void stats(Character & profile) {
        profile.s = 9;
        profile.save_character();
    }
};
class theif {
public :
    void stats(Character & profile){
        profile.d = 9;
        profile.save_character();
    }
};