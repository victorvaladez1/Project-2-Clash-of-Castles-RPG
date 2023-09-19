#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

#include "Character.h"


void Character::setName(string n)
{
    name = n;
}
string Character::getName()
{
    return name;
}
void Character::setHp(int h)
{
    hp = h;
}
int Character::getHp()
{
    return hp;
}
void Character::setDamage(int d)
{
    damage = d;
}
int Character::getDamage()
{
    return damage;
}
void Character::setLevel(int l)
{
    level = l;
}
int Character::getLevel()
{
    return level;
}
void Character::setStamina(int s)
{
    stamina = s;
}
int Character::getStamina()
{
    return stamina;
}
void Character::setXp(int x)
{
    xp = x;
}
int Character::getXp()
{
    return xp;
}
string Character::getType()
{
    return type;
}