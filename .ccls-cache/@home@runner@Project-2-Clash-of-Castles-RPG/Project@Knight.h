#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "Character.h"

using namespace std;



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