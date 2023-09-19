#ifndef THIEF_H
#define THIEF_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

#include "Character.h"

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