#ifndef WIZARD_H
#define WIZARD_H




#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "Character.h"

using namespace std;

class Wizard : public Character
{
public:
    Wizard(string n);
    void setSpell(int s);
    int getSpell();
    void print();

private:
    int spell;
};

#endif