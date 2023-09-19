#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "Knight.h"

using namespace std;



Knight::Knight(string n)
{
    name = n;
    damage = 200;
    hp = 1200;
    stamina = 5;
    level = 1;
    xp = 0;
    claymore = 300;
    type = "knight";
}

void Knight::setClaymore(int c)
{
    claymore = c;
}
int Knight::getClaymore()
{
    return claymore;
}

void Knight::print()
{
cout << "             .--." << endl;
        cout << "            /.--.\\" << endl;
        cout << "            |====|" << endl;
        cout << "            |`::`|" << endl;
        cout << "        .-;`\\..../`;_.-^-." << endl;
        cout << " /\\\\   /  |...::..|`   :   `|" << endl;
        cout << " |:'\\ |   /'''::''|   .:.   |" << endl;
        cout << "@|\\ /\\:-,/\\   ::  |..:::::.." << endl;
        cout << "`||\\ <` >  >._::_.| ':::::' |" << endl;
        cout << " || `"
                "`  /   ^^  |   ':'   |"
             << endl;
        cout << " ||       |       \\    :    /" << endl;
        cout << " ||       |        \\   :   / " << endl;
        cout << " ||       |___/\\___|`-.:.-`" << endl;
        cout << " ||        \\_ || _/    `" << endl;
        cout << " ||        \\_ || _/" << endl;
        cout << " ||        <_ >< _>" << endl;
        cout << " ||        |  ||  |" << endl;
        cout << " ||        |  ||  |" << endl;
        cout << " ||       _\\.:||:./_" << endl;
        cout << " \\/      /____/\\____\\" << endl
             << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Statistics for " << name << endl;
        cout << "Class type: Knight" << endl;
        cout << "Hp: " << hp << endl;
        cout << "Primary Attack - Short Sword: " << damage << " Dmg - Stamina Cost: 1" << endl;
        cout << "Ultimate Ability - Large Claymore: " << claymore << " Dmg - Stamina Cost: 3" << endl;
        cout << "Stamina per turn: " << stamina << endl;
        cout << "Level: " << level << endl;
        cout << "Xp: " << xp << endl;
        cout << "Xp needed for next level: " << 1000 - (xp % 1000) << endl
             << endl;
}