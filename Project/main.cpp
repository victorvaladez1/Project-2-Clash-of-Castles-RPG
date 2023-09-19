//Victor Valadez

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "Character.h"
#include "Knight.h"
#include "Wizard.h"
#include "Thief.h"

using namespace std;



void sortVector(vector<Character *> characters) // This function sorts the vector of characters from the highest to the lowest level
{
    for (int i = 0; i < characters.size() - 1; i++) // This is a bubble sort that compares each character's level
    {
        for (int j = i + 1; j < characters.size(); j++)
        {
            Character *temp;
            if (characters.at(i)->getLevel() > characters.at(j)->getLevel())
            {
                temp = characters.at(i);
                characters.at(i) = characters.at(j);
                characters.at(j) = temp;
            }
        }
    }
}

void printRoster(vector<Character *> characters) // This function loop through each character in the vector and calls it's virtual print() function
{
    for (int i = 0; i < characters.size(); i++)
    {
        cout << "--------------------------------------------------" << endl;
        characters.at(i)->print();
    }
}

void copyAttrib(string name, vector<Character *> &characters, vector<Character *> &battle, int num) // This function creates a deep copy of a character, this is use to keep the original stats of a character when it is used for a battle
{
    int count = num; // this integer keeps track of the player (player 1 or player 2)
    for (int k = 0; k < characters.size(); k++)
    {
        if (name == characters.at(k)->getName()) // searches for the character in characters that shares the name as the string name
        {
            if (characters.at(k)->getType() == "knight")
            {
                Knight *newKnight = new Knight(name);                // copy of knight character is created
                newKnight->setDamage(characters.at(k)->getDamage()); // all stats are copied from the original character
                newKnight->setHp(characters.at(k)->getHp());
                newKnight->setStamina(characters.at(k)->getStamina());
                newKnight->setLevel(characters.at(k)->getLevel());
                newKnight->setXp(characters.at(k)->getLevel());
                newKnight->setClaymore(300 * pow(1 + 0.1, characters.at(k)->getLevel() - 1)); // copies unique ability for knight characters
                battle.push_back(newKnight);
            }
            else if (characters.at(k)->getType() == "wizard")
            {
                Wizard *newWizard = new Wizard(name);                // copy of wizard character is created
                newWizard->setDamage(characters.at(k)->getDamage()); // all stats are copied from the original character
                newWizard->setHp(characters.at(k)->getHp());
                newWizard->setStamina(characters.at(k)->getStamina());
                newWizard->setLevel(characters.at(k)->getLevel());
                newWizard->setXp(characters.at(k)->getLevel());
                newWizard->setSpell(150 * pow(1 + 0.1, characters.at(k)->getLevel() - 1)); // copies unique ability for wizard characters
                battle.push_back(newWizard);
            }
            else if (characters.at(k)->getType() == "thief")
            {
                Thief *newThief = new Thief(name);                  // copy of thief character is created
                newThief->setDamage(characters.at(k)->getDamage()); // all stats are copied from the original character
                newThief->setHp(characters.at(k)->getHp());
                newThief->setStamina(characters.at(k)->getStamina());
                newThief->setLevel(characters.at(k)->getLevel());
                newThief->setXp(characters.at(k)->getLevel());
                newThief->setLootbag(100 * pow(1 + 0.1, characters.at(k)->getLevel() - 1)); // copies unique ability for thief characters
                battle.push_back(newThief);
            }
            cout << "Player " << count << " selected " << characters.at(k)->getType() << " named " << characters.at(k)->getName() << endl;
        }
    }
}

int main()
{

    vector<Character *> characters; // Vector of pointers to characters is created

    cout << "Clash of Castles PVP RPG " << endl
         << endl;

    cout << "_________ .__                .__              _____  _________                  __  .__                 " << endl;
    cout << "\\_   ___ \\|  | _____    _____|  |__     _____/ ____\\ \\_   ___ \\_____    _______/  |_|  |   ____   ______" << endl;
    cout << "/    \\  \\/|  | \\__  \\  /  ___/  |  \\   /  _ \\   __\\  /    \\  \\/\\__  \\  /  ___/\\   __\\  | _/ __ \\ /  ___/" << endl;
    cout << "\\     \\___|  |__/ __ \\_\\___ \\|   Y  \\ (  <_> )  |    \\     \\____/ __ \\_\\___ \\  |  | |  |_\\  ___/ \\___ \\" << endl;
    cout << " \\______  /____(____  /____  >___|  /  \\____/|__|     \\______  (____  /____  > |__| |____/\\___  >____  >" << endl;
    cout << "        \\/          \\/     \\/     \\/                         \\/     \\/     \\/                 \\/     \\/ " << endl
         << endl;

    // menu is printed for user to see

    cout << "Menu" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1 - create new character" << endl;
    cout << "2 - print character statistics" << endl;
    cout << "3 - save game" << endl;
    cout << "4 - load game" << endl;
    cout << "5 - start game" << endl;
    cout << "6 - print menu" << endl;
    cout << "0 - exit" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Enter a selection" << endl
         << endl;

    string input; // asks for user input
    cin >> input;

    while (input != "0") // loops if input is invalid
    {
        if (input == "1") // if user chooses 1, new character is created
        {
            cout << "Enter name for new character" << endl // asks user to input new character name
                 << endl;
            string name;
            cin >> name;

            cout << endl
                 << "Select character type:" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "1 - Knight" << endl;
            cout << "2 - Wizard" << endl;
            cout << "3 - Thief" << endl
                 << endl;
            int charType; // asks user to select character type for new character
            cin >> charType;

            while (charType != 1 && charType != 2 && charType != 3) // loops if character enters invalid character type
            {
                cout << "Invalid character type, please enter a valid type" << endl;
                cin >> charType;
            }

            if (charType == 1) // if user chooses 1, then new character is a knight
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

                characters.push_back(new Knight(name));
            }
            else if (charType == 2)
            {

                cout << "                     ____" << endl;
                cout << "                   .'* *.'" << endl;
                cout << "               __/_*_*(_" << endl;
                cout << "               / _______ \\" << endl;
                cout << "              _\\_)/___\\(_/_ " << endl;
                cout << "             / _((\\- -/))_ \\" << endl;
                cout << "             \\ \\())(-)(()/ /" << endl;
                cout << "              ' \\(((()))/ '" << endl;
                cout << "             / ' \\)).))/ ' \\" << endl;
                cout << "            / _ \\ - | - /_  \\" << endl;
                cout << "           (   ( .;''';. .'  )" << endl;
                cout << "           _\"__ /    )\\ __/_" << endl;
                cout << "             \\/  \\   ' /  \\/" << endl;
                cout << "              .'  '...' ' )" << endl;
                cout << "               / /  |  \\ \\" << endl;
                cout << "              / .   .   . \\" << endl;
                cout << "             /   .     .   \\" << endl;
                cout << "            /   /   |   \\   \\" << endl;
                cout << "          .'   /    b    '.  '." << endl;
                cout << "      _.-'    /     Bb     '-. '-._ " << endl;
                cout << "  _.-'       |      BBb       '-.  '-. " << endl;
                cout << " (________mrf\\____.dBBBb.________)____) " << endl
                     << endl;

                characters.push_back(new Wizard(name)); // if user chooses 2, then new character is a wizard
            }
            else if (charType == 3)
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

                characters.push_back(new Thief(name)); // if user chooses 3, then new character is a thief
            }
            cout << endl
                 << "Succesfully created new " << characters.at(characters.size() - 1)->getType() << " named " << characters.at(characters.size() - 1)->getName() << endl
                 << endl;
        }
        else if (input == "2") // if user chooses 2, all character statistics are printed
        {
            cout << endl
                 << "Printing all roster statistics" << endl
                 << endl;
            printRoster(characters); // calls printRoster() function
            cout << endl;
        }
        else if (input == "3") // if user chooses 3, current game progress is saved to a text file
        {
            ofstream fout;
            cout << "Enter file name to save" << endl
                 << endl;
            string saveFile; // asks user to input file
            cin >> saveFile;
            fout.open(saveFile); // program opens file if it already exists or creates a new one completely
            fout << characters.size() << endl;
            for (int i = 0; i < characters.size(); i++) // loops through all characters and pastes their stats into text file using fstreams
            {
                fout << characters.at(i)->getName() << endl;
                fout << characters.at(i)->getType() << endl;
                fout << characters.at(i)->getDamage() << endl;
                fout << characters.at(i)->getHp() << endl;
                fout << characters.at(i)->getStamina() << endl;
                fout << characters.at(i)->getLevel() << endl;
                fout << characters.at(i)->getXp() << endl;
                if (characters.at(i)->getType() == "knight") // pastes knight's unique ability to text file
                {
                    fout << 300 * pow(1 + 0.1, characters.at(i)->getLevel() - 1) << endl;
                }
                else if (characters.at(i)->getType() == "wizard") // pastes wizard's unique ability to text file
                {
                    fout << 150 * pow(1 + 0.1, characters.at(i)->getLevel() - 1) << endl;
                }
                else if (characters.at(i)->getType() == "thief") // pastes theif's unique ability to text file
                {
                    fout << 100 * pow(1 + 0.1, characters.at(i)->getLevel() - 1) << endl;
                }
            }

            cout << "Game file: " << input << " - saved successfully" << endl
                 << endl;

            fout.close(); // closes fstream
        }
        else if (input == "4") // if user chooses 4, user can load a previously saved game
        {
            ifstream fin;
            cout << "Enter save file name" << endl
                 << endl;
            string saveFile;
            cin >> saveFile; // asks user to input text file name
            fin.open(saveFile);

            if (!fin.is_open()) // if the text file is not found, the program exits the loop
            {
                cout << "File not found!" << endl
                     << endl;
                break;
            }

            for (auto Character : characters) // if file is found, the program clears current game roster
            {
                delete Character;
            }

            characters.clear();

            int newInst;
            fin >> newInst; // character loads character roster size from the previous game save

            for (int i = 0; i < newInst; i++) // character all loads character attributes from the previous game save
            {
                string nameN;
                string typeN;
                int damageN;
                int hpN;
                int staminaN;
                int levelN;
                int xpN;

                fin >> nameN;
                fin >> typeN;
                fin >> damageN;
                fin >> hpN;
                fin >> staminaN;
                fin >> levelN;
                fin >> xpN;

                if (typeN == "knight") // if program reads chracter type as "knight", the program loads the claymore ability
                {

                    Knight *newKnight = new Knight(nameN);
                    newKnight->setDamage(damageN);
                    newKnight->setHp(hpN);
                    newKnight->setStamina(staminaN);
                    newKnight->setLevel(levelN);
                    newKnight->setXp(xpN);

                    int claymoreN;
                    fin >> claymoreN;
                    newKnight->setClaymore(claymoreN);

                    characters.push_back(newKnight);
                }
                else if (typeN == "wizard") // if program reads chracter type as "wizard", the program loads the healing spell ability
                {

                    Wizard *newWizard = new Wizard(nameN);
                    newWizard->setDamage(damageN);
                    newWizard->setHp(hpN);
                    newWizard->setStamina(staminaN);
                    newWizard->setLevel(levelN);
                    newWizard->setXp(xpN);

                    int spellN;
                    fin >> spellN;
                    newWizard->setSpell(spellN);

                    characters.push_back(newWizard);
                }
                else if (typeN == "thief")
                {

                    Thief *newThief = new Thief(nameN); // if program reads chracter type as "wizard", the program loads the loot bag ability
                    newThief->setDamage(damageN);
                    newThief->setHp(hpN);
                    newThief->setStamina(staminaN);
                    newThief->setLevel(levelN);
                    newThief->setXp(xpN);

                    int lootBagN;
                    fin >> lootBagN;
                    newThief->setLootbag(lootBagN);
                    characters.push_back(newThief);
                }
            }
            cout << "File loaded successfully" << endl
                 << endl;
            fin.close(); // fstream is closed
        }
        else if (input == "5") // if user chooses 5, then a match is started
        {
            cout << "Starting new game" << endl
                 << endl;
            cout << "Character Roster" << endl
                 << endl;

            printRoster(characters); // character roster is printed for the players to see

            vector<Character *> battle; // new vector for characters is created, this will hold both characters that player 1 and player 2 will use

            cout << endl
                 << "Player 1: Enter character name" << endl;
            string nameB1;
            cin >> nameB1; // asks player 1 to select a character

            bool validNameB1 = false;

            for (int i = 0; i < characters.size(); i++) // searches player 1's character in the characters vector
            {
                if (characters.at(i)->getName() == nameB1)
                {
                    validNameB1 = true;
                }
            }
            while (validNameB1 == false) // if the character is not found, then the program loops until player 1 selects a valid character
            {
                cout << endl
                     << nameB1 << " does not exist!" << endl
                     << "Enter another character name:" << endl
                     << endl;
                cin >> nameB1;
                for (int i = 0; i < characters.size(); i++)
                {
                    if (characters.at(i)->getName() == nameB1)
                    {
                        validNameB1 = true;
                        break;
                    }
                }
            }

            copyAttrib(nameB1, characters, battle, 1); // once found the character is copied and added to the battle vector

            cout << endl
                 << "Player 2: Enter character name" << endl;
            string nameB2;
            cin >> nameB2; // asks player 2 to select a character

            bool validNameB2 = false;

            for (int i = 0; i < characters.size(); i++) // program loops through the characters vector to find player 2's character
            {
                if (characters.at(i)->getName() == nameB2)
                {
                    validNameB2 = true;
                }
            }
            while (validNameB2 == false) // if the character does not exists, the program will ask player 2 to enter a vaild character
            {
                cout << endl
                     << nameB2 << " does not exist!" << endl
                     << "Enter another character name:" << endl
                     << endl;
                cin >> nameB2;
                for (int i = 0; i < characters.size(); i++)
                {
                    if (characters.at(i)->getName() == nameB2)
                    {
                        validNameB2 = true;
                        break;
                    }
                }
            }

            copyAttrib(nameB2, characters, battle, 2); // once player 2's character is found, all its attributes are copied on to the battle vector

            Character *winner; // match winner variable is created
            Character *loser;  // match loser variable is created

            bool gameOver = false;

            while (gameOver == false) // while the game is not over, characters take turns attacking each other
            {

                cout << endl
                     << battle.at(0)->getName() << "'s Turn" << endl; // Player 1's turn begins

                if (battle.at(0)->getType() == "knight")
                {

                    int tempStamina = battle.at(0)->getStamina(); // Player 1's stamina is calculated
                    while (tempStamina > 0)
                    {
                        if (battle.at(1)->getHp() <= 0) // if player 2's health reaches zero, then the match is over
                        {
                            break;
                        }

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

                        cout << endl // the program prints all of the character's stats if player 1's character is a knight type
                             << battle.at(0)->getName() << "'s stamina remaining: " << tempStamina << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Select Move" << endl;
                        cout << "1 - Use short sword attack: " << battle.at(0)->getDamage() << " - Stamina cost: 1" << endl;
                        cout << "2 - Use large claymore attack " << 300 * pow(1 + 0.1, battle.at(0)->getLevel() - 1) << " - Stamina cost: 3" << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Match Statistics:" << endl;
                        cout << battle.at(0)->getName() << "'s Hp: " << battle.at(0)->getHp() << endl;
                        cout << battle.at(1)->getName() << "'s Hp: " << battle.at(1)->getHp() << endl
                             << endl;
                        int inputMove;
                        cin >> inputMove; // the program asks the user to enter a move

                        if ((inputMove == 2) && ((tempStamina - 3) >= 0)) // if the player chooses 2, and has enough stamina, then this ability is called
                        {
                            int inflictedDamage = battle.at(1)->getHp(); // recalculate's player 2 health
                            inflictedDamage -= 300 * pow(1 + 0.1, battle.at(0)->getLevel() - 1);
                            battle.at(1)->setHp(inflictedDamage);
                            tempStamina = tempStamina - 3;
                            cout << battle.at(0)->getName() << " used large claymore attack!" << endl
                                 << endl;
                        }
                        else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) // if the player chooses 1, and has enough stamina, then this ability is called
                        {
                            int inflictedDamage = battle.at(1)->getHp(); // player 2's health is recalculated
                            inflictedDamage = inflictedDamage - battle.at(0)->getDamage();
                            battle.at(1)->setHp(inflictedDamage);
                            tempStamina = tempStamina - 1;
                            cout << battle.at(0)->getName() << " used short sword attack!" << endl
                                 << endl;
                        }
                        else // if the either condition is not met, then the player is asks to select again
                        {
                            cout << "Not enough stamina remaining or not a valid move" << endl;
                            cout << "Please select another move" << endl
                                 << endl;
                        }

                        if (tempStamina <= 0) // if player 1's stamina reaches zero, then the player 1's turn is over
                        {
                            cout << battle.at(0)->getName() << "'s turn is over" << endl
                                 << endl;
                            break;
                        }
                    }

                    cout << battle.at(1)->getName() << "'s turn" << endl; // player 2's turn begins
                    cout << battle.at(1)->getName() << "'s stamina " << battle.at(1)->getStamina() << endl
                         << endl;
                }

                if (battle.at(0)->getType() == "wizard")
                {

                    int tempStamina = battle.at(0)->getStamina(); // player 1's staming is calcutlated
                    while (tempStamina > 0)
                    {
                        if (battle.at(1)->getHp() <= 0)
                        {
                            break;
                        }

                        cout << "                     ____" << endl;
                        cout << "                   .'* *.'" << endl;
                        cout << "               __/_*_*(_" << endl;
                        cout << "               / _______ \\" << endl;
                        cout << "              _\\_)/___\\(_/_ " << endl;
                        cout << "             / _((\\- -/))_ \\" << endl;
                        cout << "             \\ \\())(-)(()/ /" << endl;
                        cout << "              ' \\(((()))/ '" << endl;
                        cout << "             / ' \\)).))/ ' \\" << endl;
                        cout << "            / _ \\ - | - /_  \\" << endl;
                        cout << "           (   ( .;''';. .'  )" << endl;
                        cout << "           _\"__ /    )\\ __/_" << endl;
                        cout << "             \\/  \\   ' /  \\/" << endl;
                        cout << "              .'  '...' ' )" << endl;
                        cout << "               / /  |  \\ \\" << endl;
                        cout << "              / .   .   . \\" << endl;
                        cout << "             /   .     .   \\" << endl;
                        cout << "            /   /   |   \\   \\" << endl;
                        cout << "          .'   /    b    '.  '." << endl;
                        cout << "      _.-'    /     Bb     '-. '-._ " << endl;
                        cout << "  _.-'       |      BBb       '-.  '-. " << endl;
                        cout << " (________mrf\\____.dBBBb.________)____) " << endl
                             << endl;

                        cout << endl // player 1's abilities are printed if the character is a wizrad type
                             << battle.at(0)->getName() << "'s stamina remaining: " << tempStamina << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Select Move" << endl;
                        cout << "1 - Use fireball attack: " << battle.at(0)->getDamage() << " Dmg - Stamina cost: 1" << endl;
                        cout << "2 - Use self healing spell ability: +" << (150 * pow(1 + 0.1, battle.at(0)->getLevel() - 1)) << " Hp - Stamina cost: 3" << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Match Statistics:" << endl;
                        cout << battle.at(0)->getName() << "'s Hp: " << battle.at(0)->getHp() << endl;
                        cout << battle.at(1)->getName() << "'s Hp: " << battle.at(1)->getHp() << endl
                             << endl;
                        int inputMove;
                        cin >> inputMove; // asks player to input move

                        if ((inputMove == 2) && ((tempStamina - 3) >= 0)) // if character has enough stamina, this ability is called
                        {
                            int inflictedDamage = battle.at(0)->getHp();
                            inflictedDamage += 150 * pow(1 + 0.1, battle.at(0)->getLevel() - 1);
                            battle.at(0)->setHp(inflictedDamage);
                            tempStamina = tempStamina - 3;
                            cout << battle.at(0)->getName() << " used healing spell ability!" << endl
                                 << endl;
                        }
                        else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) // if character has enough stamina, this ability is called
                        {
                            int inflictedDamage = battle.at(1)->getHp();
                            inflictedDamage = inflictedDamage - battle.at(0)->getDamage();
                            battle.at(1)->setHp(inflictedDamage);
                            tempStamina = tempStamina - 1;
                            cout << battle.at(0)->getName() << " used fireball attack!" << endl
                                 << endl;
                        }
                        else // if the condition is not met, the user is asked to enter a different move
                        {
                            cout << "Not enough stamina remaining or not a valid move" << endl;
                            cout << "Please select another move" << endl
                                 << endl;
                        }

                        if (tempStamina <= 0) // if player 1's stamina reaches 0, player 1's turn is over
                        {
                            cout << battle.at(0)->getName() << "'s turn is over" << endl
                                 << endl;
                            break;
                        }
                    }

                    cout << battle.at(1)->getName() << "'s turn" << endl; // player 2's turn begins
                    cout << battle.at(1)->getName() << "'s stamina " << battle.at(1)->getStamina() << endl
                         << endl;
                }

                if (battle.at(0)->getType() == "thief") // if player 1's character is a thief type loop is called during it's round
                {

                    int tempStamina = battle.at(0)->getStamina(); // player 1's stamina is calculated
                    while (tempStamina > 0)
                    {
                        if (battle.at(1)->getHp() <= 0) // if player 2's health reaches zero, the game is over
                        {
                            break;
                        }

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

                        cout << endl // print's the character's abilities
                             << battle.at(0)->getName() << "'s stamina remaining: " << tempStamina << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Select Move" << endl;
                        cout << "1 - Use knife attack: " << battle.at(0)->getDamage() << " - Stamina cost: 1" << endl;
                        cout << "2 - Use loot bag ability +" << (100 * pow(1 + 0.1, battle.at(0)->getLevel() - 1)) << " Hp and Dmg - Stamina cost: 3" << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Match Statistics:" << endl;
                        cout << battle.at(0)->getName() << "'s Hp: " << battle.at(0)->getHp() << endl;
                        cout << battle.at(1)->getName() << "'s Hp: " << battle.at(1)->getHp() << endl
                             << endl;
                        int inputMove; // asks the player to enter an ability
                        cin >> inputMove;

                        if ((inputMove == 2) && ((tempStamina - 3) >= 0)) // if the character has enough stamina, this ability is called
                        {
                            int inflictedDamage = battle.at(1)->getHp();
                            inflictedDamage = inflictedDamage - (100 * pow(1 + 0.1, battle.at(0)->getLevel() - 1));
                            battle.at(1)->setHp(inflictedDamage);
                            battle.at(0)->setHp(battle.at(0)->getHp() + (100 * pow(1 + 0.1, battle.at(0)->getLevel() - 1)));
                            cout << battle.at(0)->getName() << " used loot bag ability!" << endl
                                 << endl;
                            tempStamina = tempStamina - 3;
                        }
                        else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) // if the character has enough stamina, this ability is called
                        {
                            int inflictedDamage = battle.at(1)->getHp();
                            inflictedDamage = inflictedDamage - battle.at(0)->getDamage();
                            battle.at(1)->setHp(inflictedDamage);
                            tempStamina = tempStamina - 1;
                            cout << battle.at(0)->getName() << " used knife attack!" << endl
                                 << endl;
                        }
                        else // if the character does meet the condition, then the player is asked to choose a different move
                        {
                            cout << "Not enough stamina remaining or not a valid move" << endl;
                            cout << "Please select another move" << endl
                                 << endl;
                        }

                        if (tempStamina <= 0) // if player 1's stamina reaches 0, player 1's turn is over
                        {
                            cout << battle.at(0)->getName() << "'s turn is over" << endl
                                 << endl;
                            break;
                        }
                    }
                }

                if ((battle.at(0)->getHp() <= 0) || (battle.at(1)->getHp() <= 0)) // if either player's health reaches zero, the game is over
                {
                    for (int i = 0; i < battle.size(); i++)
                    {
                        if ((battle.at(i)->getHp() > 0))
                        {
                            winner = battle.at(i); // player with positive health is deemed the winner
                        }
                        else if ((battle.at(i)->getHp() <= 0)) // player with negative health is deemed the loser
                        {
                            loser = battle.at(i);
                        }
                    }

                    gameOver = true;

                    break;
                }

                cout << battle.at(1)->getName() << "'s Turn" << endl; // player 2's turn begins

                if (battle.at(1)->getType() == "wizard") // if player 2's character type is a wizard, this loop is executed
                {

                    int tempStamina = battle.at(1)->getStamina(); // calculates player 2's stamina
                    while (tempStamina > 0)
                    {
                        if (battle.at(0)->getHp() <= 0)
                        {
                            break;
                        }

                        cout << "                     ____" << endl;
                        cout << "                   .'* *.'" << endl;
                        cout << "               __/_*_*(_" << endl;
                        cout << "               / _______ \\" << endl;
                        cout << "              _\\_)/___\\(_/_ " << endl;
                        cout << "             / _((\\- -/))_ \\" << endl;
                        cout << "             \\ \\())(-)(()/ /" << endl;
                        cout << "              ' \\(((()))/ '" << endl;
                        cout << "             / ' \\)).))/ ' \\" << endl;
                        cout << "            / _ \\ - | - /_  \\" << endl;
                        cout << "           (   ( .;''';. .'  )" << endl;
                        cout << "           _\"__ /    )\\ __/_" << endl;
                        cout << "             \\/  \\   ' /  \\/" << endl;
                        cout << "              .'  '...' ' )" << endl;
                        cout << "               / /  |  \\ \\" << endl;
                        cout << "              / .   .   . \\" << endl;
                        cout << "             /   .     .   \\" << endl;
                        cout << "            /   /   |   \\   \\" << endl;
                        cout << "          .'   /    b    '.  '." << endl;
                        cout << "      _.-'    /     Bb     '-. '-._ " << endl;
                        cout << "  _.-'       |      BBb       '-.  '-. " << endl;
                        cout << " (________mrf\\____.dBBBb.________)____) " << endl
                             << endl;

                        cout << endl // prints player 2's abilities
                             << battle.at(1)->getName() << "'s stamina remaining: " << tempStamina << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Select Move" << endl;
                        cout << "1 - Use fireball attack: " << battle.at(1)->getDamage() << " Dmg - Stamina cost: 1" << endl;
                        cout << "2 - Use self healing spell ability: +" << (150 * pow(1 + 0.1, battle.at(1)->getLevel() - 1)) << " Hp - Stamina cost: 3" << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Match Statistics:" << endl;
                        cout << battle.at(0)->getName() << "'s Hp: " << battle.at(0)->getHp() << endl;
                        cout << battle.at(1)->getName() << "'s Hp: " << battle.at(1)->getHp() << endl
                             << endl;

                        int inputMove; // asks player 2 to enter a move
                        cin >> inputMove;

                        if ((inputMove == 2) && ((tempStamina - 3) >= 0)) // if the character has enough stamina, this ability is called
                        {
                            int inflictedDamage = battle.at(1)->getHp();
                            inflictedDamage += 150 * pow(1 + 0.1, battle.at(1)->getLevel() - 1);
                            battle.at(1)->setHp(inflictedDamage);
                            tempStamina = tempStamina - 3;
                            cout << battle.at(1)->getName() << " used healing spell ability!" << endl
                                 << endl;
                        }
                        else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) // if the character has enough stamina, this ability is called
                        {
                            int inflictedDamage = battle.at(0)->getHp();
                            inflictedDamage = inflictedDamage - battle.at(1)->getDamage();
                            battle.at(0)->setHp(inflictedDamage);
                            tempStamina = tempStamina - 1;
                            cout << battle.at(1)->getName() << " used fireball attack!" << endl
                                 << endl;
                        }

                        if (tempStamina <= 0) // if player 2's stamina reaches 0, player 2's turn is over
                        {
                            cout << battle.at(1)->getName() << "'s turn is over" << endl
                                 << endl;
                            break;
                        }
                    }
                }

                if (battle.at(1)->getType() == "knight") // if player 2's character type is a knight, this loop is run
                {

                    int tempStamina = battle.at(1)->getStamina(); // player 2's stamina is called
                    while (tempStamina > 0)
                    {
                        if (battle.at(0)->getHp() <= 0)
                        {
                            break;
                            gameOver = true;
                        }

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

                        cout << endl // player 2's abilities are printed
                             << battle.at(1)->getName() << "'s stamina remaining: " << tempStamina << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Select Move" << endl;
                        cout << "1 - Use short sword attack: " << battle.at(1)->getDamage() << " - Stamina cost: 1" << endl;
                        cout << "2 - Use large claymore attack " << 300 * pow(1 + 0.1, battle.at(1)->getLevel() - 1) << " - Stamina cost: 3" << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Match Statistics:" << endl;
                        cout << battle.at(0)->getName() << "'s Hp: " << battle.at(0)->getHp() << endl;
                        cout << battle.at(1)->getName() << "'s Hp: " << battle.at(1)->getHp() << endl
                             << endl;
                        int inputMove; // the code asks player 2 to enter an ability
                        cin >> inputMove;

                        if ((inputMove == 2) && ((tempStamina - 3) >= 0)) // if the player has enough stamina, this ability is called
                        {
                            int inflictedDamage = battle.at(0)->getHp();
                            inflictedDamage -= 300 * pow(1 + 0.1, battle.at(1)->getLevel() - 1);
                            battle.at(0)->setHp(inflictedDamage);
                            tempStamina = tempStamina - 3;
                            cout << battle.at(1)->getName() << " used large claymore attack!" << endl
                                 << endl;
                        }
                        else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) // if the player has enough stamina, this ability is called
                        {
                            int inflictedDamage = battle.at(0)->getHp();
                            inflictedDamage = inflictedDamage - battle.at(1)->getDamage();
                            battle.at(0)->setHp(inflictedDamage);
                            tempStamina = tempStamina - 1;
                            cout << battle.at(1)->getName() << " used short sword attack!" << endl
                                 << endl;
                        }
                        else // if conditions are not met, then the code asks player 2 to select a different move
                        {
                            cout << "Not enough stamina remaining or not a valid move" << endl;
                            cout << "Please select another move" << endl
                                 << endl;
                        }

                        if (tempStamina <= 0) // if player 2's stamina reaches zero, player 2's turn is over
                        {
                            cout << battle.at(1)->getName() << "'s turn is over" << endl
                                 << endl;
                            break;
                        }
                    }
                }

                if (battle.at(1)->getType() == "thief") // if player 2's character is a thief type, this loop is executed
                {

                    int tempStamina = battle.at(1)->getStamina();
                    while (tempStamina > 0)
                    {
                        if (battle.at(0)->getHp() <= 0)
                        {
                            break;
                        }

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

                        cout << endl // player 2's abilities are called
                             << battle.at(1)->getName() << "'s stamina remaining: " << tempStamina << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Select Move" << endl;
                        cout << "1 - Use knife attack: " << battle.at(1)->getDamage() << " - Stamina cost: 1" << endl;
                        cout << "2 - Use loot bag ability +" << (100 * pow(1 + 0.1, battle.at(1)->getLevel() - 1)) << " Hp and Dmg - Stamina cost: 3" << endl;
                        cout << "--------------------------------------------------" << endl;
                        cout << "Match Statistics:" << endl;
                        cout << battle.at(0)->getName() << "'s Hp: " << battle.at(0)->getHp() << endl;
                        cout << battle.at(1)->getName() << "'s Hp: " << battle.at(1)->getHp() << endl
                             << endl;
                        int inputMove;
                        cin >> inputMove; // the program asks player 2 to enter a move

                        if ((inputMove == 2) && ((tempStamina - 3) >= 0)) // if player 2 has enough stamina, this ability is executed
                        {
                            int inflictedDamage = battle.at(0)->getHp();
                            inflictedDamage = inflictedDamage - (100 * pow(1 + 0.1, battle.at(1)->getLevel() - 1));
                            battle.at(0)->setHp(inflictedDamage);
                            battle.at(1)->setHp(battle.at(1)->getHp() + (100 * pow(1 + 0.1, battle.at(1)->getLevel() - 1)));
                            cout << battle.at(1)->getName() << " used loot bag ability!" << endl
                                 << endl;
                            tempStamina = tempStamina - 3;
                        }
                        else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) // if player 2 has enough stamina, this ability is executed
                        {
                            int inflictedDamage = battle.at(0)->getHp();
                            inflictedDamage = inflictedDamage - battle.at(1)->getDamage();
                            battle.at(0)->setHp(inflictedDamage);
                            tempStamina = tempStamina - 1;
                            cout << battle.at(1)->getName() << " used knife attack!" << endl
                                 << endl;
                        }
                        else // if the conditions are not met, the program asks the user to select a different ability
                        {
                            cout << "Not enough stamina remaining or not a valid move" << endl;
                            cout << "Please select another move" << endl
                                 << endl;
                        }

                        if (tempStamina <= 0) // if the character's stamina reaches zero, the character's turn is over
                        {
                            cout << battle.at(1)->getName() << "'s turn is over" << endl
                                 << endl;
                            break;
                        }
                    }
                }

                if ((battle.at(0)->getHp() <= 0) || (battle.at(1)->getHp() <= 0)) // if either player's health reaches zero, the match ends
                {
                    for (int i = 0; i < battle.size(); i++)
                    {
                        if ((battle.at(i)->getHp() > 0))
                        {
                            winner = battle.at(i); // the player with positive health is deemed the winner
                        }
                        else if ((battle.at(i)->getHp() <= 0))
                        {
                            loser = battle.at(i); // the player with negative health is deemed the loser
                        }
                    }

                    gameOver = true;
                    break;
                }
            }

            cout << "--------------------Game Over!--------------------" << endl // the game is over
                 << endl;

            cout << "Match winner: " << winner->getName() << " +300 xp" << endl; // winner and loser are printed along with earned xp
            cout << "Match loser: " << loser->getName() << " +100 xp" << endl
                 << endl;
            cout << "--------------------------------------------------" << endl;
            for (int q = 0; q < characters.size(); q++)
            {
                if (winner->getName() == characters.at(q)->getName()) // the program tries to find the winner within the characters vector
                {
                    characters.at(q)->setXp(characters.at(q)->getXp() + 300); // once the winner is found, the earned xp is updated and so is the level if the xp reaches the next 1000 mark
                    characters.at(q)->setLevel((characters.at(q)->getXp() / 1000) + 1);

                    if (characters.at(q)->getType() == "knight")
                    { // if the winning character is a knight type and levels up, the health and damage are updated with a 10% boost
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
                        characters.at(q)->setDamage(200 * pow(1 + 0.1, battle.at(0)->getLevel() - 1));
                        characters.at(q)->setHp(1200 * pow(1 + 0.1, battle.at(0)->getLevel() - 1));
                    }
                    else if ((characters.at(q)->getType() == "wizard")) // if the winning character is a wizard type and levels up, the health and damage are updated with a 10% boost
                    {
                        cout << "                     ____" << endl;
                        cout << "                   .'* *.'" << endl;
                        cout << "               __/_*_*(_" << endl;
                        cout << "               / _______ \\" << endl;
                        cout << "              _\\_)/___\\(_/_ " << endl;
                        cout << "             / _((\\- -/))_ \\" << endl;
                        cout << "             \\ \\())(-)(()/ /" << endl;
                        cout << "              ' \\(((()))/ '" << endl;
                        cout << "             / ' \\)).))/ ' \\" << endl;
                        cout << "            / _ \\ - | - /_  \\" << endl;
                        cout << "           (   ( .;''';. .'  )" << endl;
                        cout << "           _\"__ /    )\\ __/_" << endl;
                        cout << "             \\/  \\   ' /  \\/" << endl;
                        cout << "              .'  '...' ' )" << endl;
                        cout << "               / /  |  \\ \\" << endl;
                        cout << "              / .   .   . \\" << endl;
                        cout << "             /   .     .   \\" << endl;
                        cout << "            /   /   |   \\   \\" << endl;
                        cout << "          .'   /    b    '.  '." << endl;
                        cout << "      _.-'    /     Bb     '-. '-._ " << endl;
                        cout << "  _.-'       |      BBb       '-.  '-. " << endl;
                        cout << " (________mrf\\____.dBBBb.________)____) " << endl
                             << endl;
                        characters.at(q)->setDamage(220 * pow(1 + 0.1, battle.at(0)->getLevel() - 1));
                        characters.at(q)->setHp(900 * pow(1 + 0.1, battle.at(0)->getLevel() - 1));
                    }
                    else if (characters.at(q)->getType() == "thief") // if the winning character is a thief type and levels up, the health and damage are updated with a 10% boost
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
                        characters.at(q)->setDamage(180 * pow(1 + 0.1, battle.at(0)->getLevel() - 1));
                        characters.at(q)->setHp(1000 * pow(1 + 0.1, battle.at(0)->getLevel() - 1));
                    }
                    characters.at(q)->setStamina(5 + (characters.at(q)->getLevel() / 5));

                    cout << winner->getName() << "'s level: " << characters.at(q)->getLevel() << endl; // the wining character's xp and level are displayed
                    cout << winner->getName() << "'s xp: " << characters.at(q)->getXp() << endl;
                }
            }

            cout << "--------------------------------------------------" << endl;

            for (int v = 0; v < characters.size(); v++)
            {
                if (loser->getName() == characters.at(v)->getName()) // the program tries to find the winner within the characters vector
                {
                    characters.at(v)->setXp(characters.at(v)->getXp() + 100); // once the winner is found, the earned xp is updated and so is the level if the xp reaches the next 1000 mark
                    characters.at(v)->setLevel((characters.at(v)->getXp() / 1000) + 1);
                    cout << loser->getName() << "'s level: " << characters.at(v)->getLevel() << endl;
                    cout << loser->getName() << "'s xp: " << characters.at(v)->getXp() << endl;
                }
            }

            for (auto Character : battle) // battle vector is deleted
            {
                delete Character;
            }

            cout << "Game Over!" << endl
                 << endl;
        }
        else if (input == "6") // if user chooses 6, the menu is printed again
        {

            cout << "Menu" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "1 - create new character" << endl;
            cout << "2 - print character statistics" << endl;
            cout << "3 - save game" << endl;
            cout << "4 - load game" << endl;
            cout << "5 - start game" << endl;
            cout << "6 - print menu" << endl;
            cout << "0 - exit" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "Enter a selection" << endl
                 << endl;
        }
        else // if the user enters and invalid option, the program asks the user to enter a new input
        {
            cout << "Invalid option" << endl
                 << endl;
        }

        cout << "Menu" << endl; // the menu is printed after the option has finished executing
        cout << "--------------------------------------------------" << endl;
        cout << "1 - create new character" << endl;
        cout << "2 - print character statistics" << endl;
        cout << "3 - save game" << endl;
        cout << "4 - load game" << endl;
        cout << "5 - start game" << endl;
        cout << "6 - print menu" << endl;
        cout << "0 - exit" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Enter a selection" << endl
             << endl;

        cin >> input; // the program asks the user to make a new selection
    }
    cout << endl
         << "Closed game successfully" << endl; // if the user selects 0, the program exits
    return 0;
}