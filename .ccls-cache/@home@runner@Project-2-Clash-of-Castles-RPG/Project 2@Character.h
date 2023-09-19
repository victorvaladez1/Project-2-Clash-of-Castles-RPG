#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

class Character
{
public:
    void setName(string n);
    string getName();
    void setHp(int h);
    int getHp();
    void setDamage(int d);
    int getDamage();
    void setLevel(int l);
    int getLevel();
    void setStamina(int s);
    int getStamina();
    void setXp(int x);
    int getXp();
    string getType();
    virtual void print() = 0;

protected:
    string name;
    int hp;
    int damage;
    int level;
    int stamina;
    int xp;
    string type;
};

#endif