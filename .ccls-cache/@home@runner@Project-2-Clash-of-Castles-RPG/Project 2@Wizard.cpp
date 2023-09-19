#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "Wizard.h"

using namespace std;



Wizard::Wizard(string n)
{
    name = n;
    damage = 220;
    hp = 900;
    stamina = 5;
    level = 1;
    xp = 0;
    spell = 150;
    type = "wizard";
}
void Wizard::setSpell(int s)
{
    spell = s;
}
int Wizard::getSpell()
{
    return spell;
}
void Wizard::print()
{
    cout << "Statistics for " << name << endl;
    cout << "Class type: Wizard" << endl;
    cout << "Hp: " << hp << endl;
    cout << "Primary Attack - FireBall: " << damage << " Dmg - Stamina Cost: 1" << endl;
    cout << "Ultimate Ability - Heal Spell: " << spell << " regeneration - Stamina Cost: 3" << endl;
    cout << "Stamina per turn: " << stamina << endl;
    cout << "Level: " << level << endl;
    cout << "Xp: " << xp << endl;
    cout << "Xp needed for next level: " << 1000 - (xp % 1000) << endl
         << endl;
}
