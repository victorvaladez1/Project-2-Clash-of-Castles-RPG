#ifndef THIEF_H
#define THIEF_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "Character.h"

using namespace std;



class Thief : public Character
{
public:
    Thief(string n);
    void setLootbag(int l);
    int getLootBag();
    void print();

private:
    int lootBag;
};

#endif