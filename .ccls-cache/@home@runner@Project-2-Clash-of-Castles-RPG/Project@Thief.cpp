#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "Thief.h"

using namespace std;



Thief::Thief(string n)
{
    name = n;
    damage = 180;
    hp = 1000;
    stamina = 5;
    level = 1;
    xp = 0;
    lootBag = 100;
    type = "thief";
}
void Thief::setLootbag(int l)
{
    lootBag = l;
}
int Thief::getLootBag()
{
    return lootBag;
}

void Thief::print()
{
        cout << "             ,      ," << endl;
        cout << "            /(.-\"\"-.)" << endl;
        cout << "        |\\  \\/      \\/  /|" << endl;
        cout << "        \\( \\   o\\/o   / )/" << endl;
        cout << "         \\_, '-/  \\-' ,_/" << endl;
        cout << "           /   \\__/   \\" << endl;
        cout << "           \\ \\__/\\__/ /" << endl;
        cout << "         ___\\ \\|--|/ /___" << endl;
        cout << "       /`    \\      /    `\\" << endl;
        cout << "      /       '----'       \\" << endl
             << endl;

        cout << "--------------------------------------------------" << endl;
        cout << "Statistics for " << name << endl;
        cout << "Class type: Thief" << endl;
        cout << "Hp: " << hp << endl;
        cout << "Primary Attack - Knife: " << damage << " Dmg - Stamina Cost: 1" << endl;
        cout << "Ultimate Ability - Loot Bag: " << ((100 * pow(1 + 0.1, getLevel() - 1))) << " Damage and Regeneration - Stamina Cost: 3" << endl;
        cout << "Stamina per turn: " << stamina << endl;
        cout << "Level: " << level << endl;
        cout << "Xp: " << xp << endl;
        cout << "Xp needed for next level: " << 1000 - (xp % 1000) << endl
             << endl;
}