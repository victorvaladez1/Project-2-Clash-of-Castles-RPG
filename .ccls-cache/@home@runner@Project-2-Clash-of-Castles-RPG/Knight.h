#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

#include "Character.h"

class Knight : public Character
{
public:
    Knight(string n);
    void setClaymore(int c);
    int getClaymore();
    void print();

private:
    int claymore;
};

#endif