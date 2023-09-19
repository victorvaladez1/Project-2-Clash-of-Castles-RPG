#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#include "Character.h"
#include "Knight.h"
#include "Thief.h"
#include "Wizard.h"

using namespace std;

void sortVector(vector<Character *> characters) {
  for (int i = 0; i < characters.size() - 1; i++) {
    for (int j = i + 1; j < characters.size(); j++) {
      Character *temp;
      if (characters.at(i)->getLevel() > characters.at(j)->getLevel()) {
        temp = characters.at(i);
        characters.at(i) = characters.at(j);
        characters.at(j) = temp;
      }
    }
  }
}

void printRoster(vector<Character *> characters) {
  for (int i = 0; i < characters.size(); i++) {
    cout << "--------------------------------------------------" << endl;
    characters.at(i)->print();
  }
}

void copyAttrib(string name, vector<Character *> &characters,
                vector<Character *> &battle, int num) {
  int count = num;
  for (int k = 0; k < characters.size(); k++) {
    if (name == characters.at(k)->getName()) {
      if (characters.at(k)->getType() == "knight") {
        Knight *newKnight = new Knight(name);
        newKnight->setDamage(characters.at(k)->getDamage());
        newKnight->setHp(characters.at(k)->getHp());
        newKnight->setStamina(characters.at(k)->getStamina());
        newKnight->setLevel(characters.at(k)->getLevel());
        newKnight->setXp(characters.at(k)->getLevel());
        newKnight->setClaymore(300 *
                               pow(1 + 0.1, characters.at(k)->getLevel() - 1));
        battle.push_back(newKnight);
      } else if (characters.at(k)->getType() == "wizard") {
        Wizard *newWizard = new Wizard(name);
        newWizard->setDamage(characters.at(k)->getDamage());
        newWizard->setHp(characters.at(k)->getHp());
        newWizard->setStamina(characters.at(k)->getStamina());
        newWizard->setLevel(characters.at(k)->getLevel());
        newWizard->setXp(characters.at(k)->getLevel());
        newWizard->setSpell(150 *
                            pow(1 + 0.1, characters.at(k)->getLevel() - 1));
        battle.push_back(newWizard);
      } else if (characters.at(k)->getType() == "thief") {
        Thief *newThief = new Thief(name);
        newThief->setDamage(characters.at(k)->getDamage());
        newThief->setHp(characters.at(k)->getHp());
        newThief->setStamina(characters.at(k)->getStamina());
        newThief->setLevel(characters.at(k)->getLevel());
        newThief->setXp(characters.at(k)->getLevel());
        newThief->setLootbag(100 *
                             pow(1 + 0.1, characters.at(k)->getLevel() - 1));
        battle.push_back(newThief);
      }
      cout << "Player " << count << " selected " << characters.at(k)->getType()
           << " named " << characters.at(k)->getName() << endl;
    }
  }
}

int main() {

  vector<Character *> characters;

  cout << "Clash of Castles PVP RPG " << endl << endl;

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
  cout << "Enter a selection" << endl << endl;

  string input;
  cin >> input;

  while (input != "0") {
    if (input == "1") {
      cout << "Enter name for new character" << endl << endl;
      string name;
      cin >> name;

      cout << endl << "Select character type:" << endl;
      cout << "--------------------------------------------------" << endl;
      cout << "1 - Knight" << endl;
      cout << "2 - Wizard" << endl;
      cout << "3 - Thief" << endl << endl;
      int charType;
      cin >> charType;

      while (charType != 1 && charType != 2 && charType != 3) {
        cout << "Invalid character type, please enter a valid type" << endl;
        cin >> charType;
      }

      if (charType == 1) {
        characters.push_back(new Knight(name));
      } else if (charType == 2) {
        characters.push_back(new Wizard(name));
      } else if (charType == 3) {
        characters.push_back(new Thief(name));
      }
      cout << endl
           << "Succesfully created new "
           << characters.at(characters.size() - 1)->getType() << " named "
           << characters.at(characters.size() - 1)->getName() << endl
           << endl;
    } else if (input == "2") {
      cout << endl << "Printing all roster statistics" << endl << endl;
      printRoster(characters);
      cout << endl;
    } else if (input == "3") {
      ofstream fout;
      cout << "Enter file name to save" << endl << endl;
      string saveFile;
      cin >> saveFile;
      fout.open(saveFile);
      fout << characters.size() << endl;
      for (int i = 0; i < characters.size(); i++) {
        fout << characters.at(i)->getName() << endl;
        fout << characters.at(i)->getType() << endl;
        fout << characters.at(i)->getDamage() << endl;
        fout << characters.at(i)->getHp() << endl;
        fout << characters.at(i)->getStamina() << endl;
        fout << characters.at(i)->getLevel() << endl;
        fout << characters.at(i)->getXp() << endl;
        if (characters.at(i)->getType() == "knight") {
          fout << 300 * pow(1 + 0.1, characters.at(i)->getLevel() - 1) << endl;
        } else if (characters.at(i)->getType() == "wizard") {
          fout << 150 * pow(1 + 0.1, characters.at(i)->getLevel() - 1) << endl;
        } else if (characters.at(i)->getType() == "thief") {
          fout << 100 * pow(1 + 0.1, characters.at(i)->getLevel() - 1) << endl;
        }
      }

      cout << "Game file: " << input << " - saved successfully" << endl << endl;

      fout.close();
    } else if (input == "4") {
      ifstream fin;
      cout << "Enter save file name" << endl << endl;
      string saveFile;
      cin >> saveFile;
      fin.open(saveFile);

      if (!fin.is_open()) {
        cout << "File not found!" << endl << endl;
        break;
      }

      for (auto Character : characters) {
        delete Character;
      }

      characters.clear();

      int newInst;
      fin >> newInst;

      for (int i = 0; i < newInst; i++) {
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

        if (typeN == "knight") {

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
        } else if (typeN == "wizard") {

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
        } else if (typeN == "thief") {

          Thief *newThief = new Thief(nameN);
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
      cout << "File loaded successfully" << endl << endl;
      fin.close();
    } else if (input == "5") {
      cout << "Starting new game" << endl << endl;
      cout << "Character Roster" << endl << endl;

      printRoster(characters);

      vector<Character *> battle;

      cout << endl << "Player 1: Enter character name" << endl;
      string nameB1;
      cin >> nameB1;

      bool validNameB1 = false;

      for (int i = 0; i < characters.size(); i++) {
        if (characters.at(i)->getName() == nameB1) {
          validNameB1 = true;
        }
      }
      while (validNameB1 == false) {
        cout << endl
             << nameB1 << " does not exist!" << endl
             << "Enter another character name:" << endl
             << endl;
        cin >> nameB1;
        for (int i = 0; i < characters.size(); i++) {
          if (characters.at(i)->getName() == nameB1) {
            validNameB1 = true;
            break;
          }
        }
      }

      copyAttrib(nameB1, characters, battle, 1);

      cout << endl << "Player 2: Enter character name" << endl;
      string nameB2;
      cin >> nameB2;

      bool validNameB2 = false;

      for (int i = 0; i < characters.size(); i++) {
        if (characters.at(i)->getName() == nameB2) {
          validNameB2 = true;
        }
      }
      while (validNameB2 == false) {
        cout << endl
             << nameB2 << " does not exist!" << endl
             << "Enter another character name:" << endl
             << endl;
        cin >> nameB2;
        for (int i = 0; i < characters.size(); i++) {
          if (characters.at(i)->getName() == nameB2) {
            validNameB2 = true;
            break;
          }
        }
      }

      copyAttrib(nameB2, characters, battle, 2);

      Character *winner;
      Character *loser;

      bool gameOver = false;

      while (gameOver == false) {

        cout << endl << battle.at(0)->getName() << "'s Turn" << endl;

        if (battle.at(0)->getType() == "knight") {

          int tempStamina = battle.at(0)->getStamina();
          while (tempStamina > 0) {
            if (battle.at(1)->getHp() <= 0) {
              break;
            }

            cout << endl
                 << battle.at(0)->getName()
                 << "'s stamina remaining: " << tempStamina << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Select Move" << endl;
            cout << "1 - Use short sword attack: " << battle.at(0)->getDamage()
                 << " - Stamina cost: 1" << endl;
            cout << "2 - Use large claymore attack "
                 << 300 * pow(1 + 0.1, battle.at(0)->getLevel() - 1)
                 << " - Stamina cost: 3" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Match Statistics:" << endl;
            cout << battle.at(0)->getName()
                 << "'s Hp: " << battle.at(0)->getHp() << endl;
            cout << battle.at(1)->getName()
                 << "'s Hp: " << battle.at(1)->getHp() << endl
                 << endl;
            int inputMove;
            cin >> inputMove;

            if ((inputMove == 2) && ((tempStamina - 3) >= 0)) {
              int inflictedDamage = battle.at(1)->getHp();
              inflictedDamage -=
                  300 * pow(1 + 0.1, battle.at(0)->getLevel() - 1);
              battle.at(1)->setHp(inflictedDamage);
              tempStamina = tempStamina - 3;
              cout << battle.at(0)->getName() << " used large claymore attack!"
                   << endl
                   << endl;
            } else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) {
              int inflictedDamage = battle.at(1)->getHp();
              inflictedDamage = inflictedDamage - battle.at(0)->getDamage();
              battle.at(1)->setHp(inflictedDamage);
              tempStamina = tempStamina - 1;
              cout << battle.at(0)->getName() << " used short sword attack!"
                   << endl
                   << endl;
            } else {
              cout << "Not enough stamina remaining or not a valid move"
                   << endl;
              cout << "Please select another move" << endl << endl;
            }

            if (tempStamina <= 0) {
              cout << battle.at(0)->getName() << "'s turn is over" << endl
                   << endl;
              break;
            }
          }

          cout << battle.at(1)->getName() << "'s turn" << endl;
          cout << battle.at(1)->getName() << "'s stamina "
               << battle.at(1)->getStamina() << endl
               << endl;
        }

        if (battle.at(0)->getType() == "wizard") {

          int tempStamina = battle.at(0)->getStamina();
          while (tempStamina > 0) {
            if (battle.at(1)->getHp() <= 0) {
              break;
            }

            cout << endl
                 << battle.at(0)->getName()
                 << "'s stamina remaining: " << tempStamina << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Select Move" << endl;
            cout << "1 - Use fireball attack: " << battle.at(0)->getDamage()
                 << " Dmg - Stamina cost: 1" << endl;
            cout << "2 - Use self healing spell ability: +"
                 << (150 * pow(1 + 0.1, battle.at(0)->getLevel() - 1))
                 << " Hp - Stamina cost: 3" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Match Statistics:" << endl;
            cout << battle.at(0)->getName()
                 << "'s Hp: " << battle.at(0)->getHp() << endl;
            cout << battle.at(1)->getName()
                 << "'s Hp: " << battle.at(1)->getHp() << endl
                 << endl;
            int inputMove;
            cin >> inputMove;

            if ((inputMove == 2) && ((tempStamina - 3) >= 0)) {
              int inflictedDamage = battle.at(0)->getHp();
              inflictedDamage +=
                  150 * pow(1 + 0.1, battle.at(0)->getLevel() - 1);
              battle.at(0)->setHp(inflictedDamage);
              tempStamina = tempStamina - 3;
              cout << battle.at(0)->getName() << " used healing spell ability!"
                   << endl
                   << endl;
            } else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) {
              int inflictedDamage = battle.at(1)->getHp();
              inflictedDamage = inflictedDamage - battle.at(0)->getDamage();
              battle.at(1)->setHp(inflictedDamage);
              tempStamina = tempStamina - 1;
              cout << battle.at(0)->getName() << " used fireball attack!"
                   << endl
                   << endl;
            } else {
              cout << "Not enough stamina remaining or not a valid move"
                   << endl;
              cout << "Please select another move" << endl << endl;
            }

            if (tempStamina <= 0) {
              cout << battle.at(0)->getName() << "'s turn is over" << endl
                   << endl;
              break;
            }
          }

          cout << battle.at(1)->getName() << "'s turn" << endl;
          cout << battle.at(1)->getName() << "'s stamina "
               << battle.at(1)->getStamina() << endl
               << endl;
        }

        if (battle.at(0)->getType() == "thief") {

          int tempStamina = battle.at(0)->getStamina();
          while (tempStamina > 0) {
            if (battle.at(1)->getHp() <= 0) {
              break;
            }

            cout << endl
                 << battle.at(0)->getName()
                 << "'s stamina remaining: " << tempStamina << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Select Move" << endl;
            cout << "1 - Use knife attack: " << battle.at(0)->getDamage()
                 << " - Stamina cost: 1" << endl;
            cout << "2 - Use loot bag ability +"
                 << (100 * pow(1 + 0.1, battle.at(0)->getLevel() - 1))
                 << " Hp and Dmg - Stamina cost: 3" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Match Statistics:" << endl;
            cout << battle.at(0)->getName()
                 << "'s Hp: " << battle.at(0)->getHp() << endl;
            cout << battle.at(1)->getName()
                 << "'s Hp: " << battle.at(1)->getHp() << endl
                 << endl;
            int inputMove;
            cin >> inputMove;

            if ((inputMove == 2) && ((tempStamina - 3) >= 0)) {
              int inflictedDamage = battle.at(1)->getHp();
              inflictedDamage =
                  inflictedDamage -
                  (100 * pow(1 + 0.1, battle.at(0)->getLevel() - 1));
              battle.at(1)->setHp(inflictedDamage);
              battle.at(0)->setHp(
                  battle.at(0)->getHp() +
                  (100 * pow(1 + 0.1, battle.at(0)->getLevel() - 1)));
              cout << battle.at(0)->getName() << " used loot bag ability!"
                   << endl
                   << endl;
              tempStamina = tempStamina - 3;
            } else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) {
              int inflictedDamage = battle.at(1)->getHp();
              inflictedDamage = inflictedDamage - battle.at(0)->getDamage();
              battle.at(1)->setHp(inflictedDamage);
              tempStamina = tempStamina - 1;
              cout << battle.at(0)->getName() << " used knife attack!" << endl
                   << endl;
            } else {
              cout << "Not enough stamina remaining or not a valid move"
                   << endl;
              cout << "Please select another move" << endl << endl;
            }

            if (tempStamina <= 0) {
              cout << battle.at(0)->getName() << "'s turn is over" << endl
                   << endl;
              break;
            }
          }
        }

        if ((battle.at(0)->getHp() <= 0) || (battle.at(1)->getHp() <= 0)) {
          for (int i = 0; i < battle.size(); i++) {
            if ((battle.at(i)->getHp() > 0)) {
              winner = battle.at(i);
            } else if ((battle.at(i)->getHp() <= 0)) {
              loser = battle.at(i);
            }
          }

          gameOver = true;

          break;
        }

        cout << battle.at(1)->getName() << "'s Turn" << endl;

        if (battle.at(1)->getType() == "wizard") {

          int tempStamina = battle.at(1)->getStamina();
          while (tempStamina > 0) {
            if (battle.at(0)->getHp() <= 0) {
              break;
            }

            cout << endl
                 << battle.at(1)->getName()
                 << "'s stamina remaining: " << tempStamina << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Select Move" << endl;
            cout << "1 - Use fireball attack: " << battle.at(1)->getDamage()
                 << " Dmg - Stamina cost: 1" << endl;
            cout << "2 - Use self healing spell ability: +"
                 << (150 * pow(1 + 0.1, battle.at(1)->getLevel() - 1))
                 << " Hp - Stamina cost: 3" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Match Statistics:" << endl;
            cout << battle.at(0)->getName()
                 << "'s Hp: " << battle.at(0)->getHp() << endl;
            cout << battle.at(1)->getName()
                 << "'s Hp: " << battle.at(1)->getHp() << endl
                 << endl;

            int inputMove;
            cin >> inputMove;

            if ((inputMove == 2) && ((tempStamina - 3) >= 0)) {
              int inflictedDamage = battle.at(1)->getHp();
              inflictedDamage +=
                  150 * pow(1 + 0.1, battle.at(1)->getLevel() - 1);
              battle.at(1)->setHp(inflictedDamage);
              tempStamina = tempStamina - 3;
              cout << battle.at(1)->getName() << " used healing spell ability!"
                   << endl
                   << endl;
            } else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) {
              int inflictedDamage = battle.at(0)->getHp();
              inflictedDamage = inflictedDamage - battle.at(1)->getDamage();
              battle.at(0)->setHp(inflictedDamage);
              tempStamina = tempStamina - 1;
              cout << battle.at(1)->getName() << " used fireball attack!"
                   << endl
                   << endl;
            }

            if (tempStamina <= 0) {
              cout << battle.at(1)->getName() << "'s turn is over" << endl
                   << endl;
              break;
            }
          }
        }

        if (battle.at(1)->getType() == "knight") {

          int tempStamina = battle.at(1)->getStamina();
          while (tempStamina > 0) {
            if (battle.at(0)->getHp() <= 0) {
              break;
              gameOver = true;
            }

            cout << endl
                 << battle.at(1)->getName()
                 << "'s stamina remaining: " << tempStamina << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Select Move" << endl;
            cout << "1 - Use short sword attack: " << battle.at(1)->getDamage()
                 << " - Stamina cost: 1" << endl;
            cout << "2 - Use large claymore attack "
                 << 300 * pow(1 + 0.1, battle.at(1)->getLevel() - 1)
                 << " - Stamina cost: 3" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Match Statistics:" << endl;
            cout << battle.at(0)->getName()
                 << "'s Hp: " << battle.at(0)->getHp() << endl;
            cout << battle.at(1)->getName()
                 << "'s Hp: " << battle.at(1)->getHp() << endl
                 << endl;
            int inputMove;
            cin >> inputMove;

            if ((inputMove == 2) && ((tempStamina - 3) >= 0)) {
              int inflictedDamage = battle.at(0)->getHp();
              inflictedDamage -=
                  300 * pow(1 + 0.1, battle.at(1)->getLevel() - 1);
              battle.at(0)->setHp(inflictedDamage);
              tempStamina = tempStamina - 3;
              cout << battle.at(1)->getName() << " used large claymore attack!"
                   << endl
                   << endl;
            } else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) {
              int inflictedDamage = battle.at(0)->getHp();
              inflictedDamage = inflictedDamage - battle.at(1)->getDamage();
              battle.at(0)->setHp(inflictedDamage);
              tempStamina = tempStamina - 1;
              cout << battle.at(1)->getName() << " used short sword attack!"
                   << endl
                   << endl;
            } else {
              cout << "Not enough stamina remaining or not a valid move"
                   << endl;
              cout << "Please select another move" << endl << endl;
            }

            if (tempStamina <= 0) {
              cout << battle.at(1)->getName() << "'s turn is over" << endl
                   << endl;
              break;
            }
          }
        }

        if (battle.at(1)->getType() == "thief") {

          int tempStamina = battle.at(1)->getStamina();
          while (tempStamina > 0) {
            if (battle.at(0)->getHp() <= 0) {
              break;
            }

            cout << endl
                 << battle.at(1)->getName()
                 << "'s stamina remaining: " << tempStamina << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Select Move" << endl;
            cout << "1 - Use knife attack: " << battle.at(1)->getDamage()
                 << " - Stamina cost: 1" << endl;
            cout << "2 - Use loot bag ability +"
                 << (100 * pow(1 + 0.1, battle.at(1)->getLevel() - 1))
                 << " Hp and Dmg - Stamina cost: 3" << endl;
            cout << "--------------------------------------------------"
                 << endl;
            cout << "Match Statistics:" << endl;
            cout << battle.at(0)->getName()
                 << "'s Hp: " << battle.at(0)->getHp() << endl;
            cout << battle.at(1)->getName()
                 << "'s Hp: " << battle.at(1)->getHp() << endl
                 << endl;
            int inputMove;
            cin >> inputMove;

            if ((inputMove == 2) && ((tempStamina - 3) >= 0)) {
              int inflictedDamage = battle.at(0)->getHp();
              inflictedDamage =
                  inflictedDamage -
                  (100 * pow(1 + 0.1, battle.at(1)->getLevel() - 1));
              battle.at(0)->setHp(inflictedDamage);
              battle.at(1)->setHp(
                  battle.at(1)->getHp() +
                  (100 * pow(1 + 0.1, battle.at(1)->getLevel() - 1)));
              cout << battle.at(1)->getName() << " used loot bag ability!"
                   << endl
                   << endl;
              tempStamina = tempStamina - 3;
            } else if ((inputMove == 1) && ((tempStamina - 1) >= 0)) {
              int inflictedDamage = battle.at(0)->getHp();
              inflictedDamage = inflictedDamage - battle.at(1)->getDamage();
              battle.at(0)->setHp(inflictedDamage);
              tempStamina = tempStamina - 1;
              cout << battle.at(1)->getName() << " used knife attack!" << endl
                   << endl;
            } else {
              cout << "Not enough stamina remaining or not a valid move"
                   << endl;
              cout << "Please select another move" << endl << endl;
            }

            if (tempStamina <= 0) {
              cout << battle.at(1)->getName() << "'s turn is over" << endl
                   << endl;
              break;
            }
          }
        }

        if ((battle.at(0)->getHp() <= 0) || (battle.at(1)->getHp() <= 0)) {
          for (int i = 0; i < battle.size(); i++) {
            if ((battle.at(i)->getHp() > 0)) {
              winner = battle.at(i);
            } else if ((battle.at(i)->getHp() <= 0)) {
              loser = battle.at(i);
            }
          }

          gameOver = true;
          break;
        }
      }

      cout << "--------------------Game Over!--------------------" << endl
           << endl;

      cout << "Match winner: " << winner->getName() << " +300 xp" << endl;
      cout << "Match loser: " << loser->getName() << " +100 xp" << endl << endl;
      cout << "--------------------------------------------------" << endl;
      for (int q = 0; q < characters.size(); q++) {
        if (winner->getName() == characters.at(q)->getName()) {
          characters.at(q)->setXp(characters.at(q)->getXp() + 300);
          characters.at(q)->setLevel((characters.at(q)->getXp() / 1000) + 1);

          if (characters.at(q)->getType() == "knight") {
            characters.at(q)->setDamage(
                200 * pow(1 + 0.1, battle.at(0)->getLevel() - 1));
            characters.at(q)->setHp(1200 *
                                    pow(1 + 0.1, battle.at(0)->getLevel() - 1));
            characters.at(q)->setHp(1200 *
                                    pow(1 + 0.1, battle.at(0)->getLevel() - 1));
          } else if ((characters.at(q)->getType() == "wizard")) {
            characters.at(q)->setDamage(
                220 * pow(1 + 0.1, battle.at(0)->getLevel() - 1));
            characters.at(q)->setHp(900 *
                                    pow(1 + 0.1, battle.at(0)->getLevel() - 1));
          } else if (characters.at(q)->getType() == "thief") {
            characters.at(q)->setDamage(
                180 * pow(1 + 0.1, battle.at(0)->getLevel() - 1));
            characters.at(q)->setHp(1000 *
                                    pow(1 + 0.1, battle.at(0)->getLevel() - 1));
          }
          characters.at(q)->setStamina(5 + (characters.at(q)->getLevel() / 5));

          cout << winner->getName()
               << "'s level: " << characters.at(q)->getLevel() << endl;
          cout << winner->getName() << "'s xp: " << characters.at(q)->getXp()
               << endl;
        }
      }

      cout << "--------------------------------------------------" << endl;

      for (int v = 0; v < characters.size(); v++) {
        if (loser->getName() == characters.at(v)->getName()) {
          characters.at(v)->setXp(characters.at(v)->getXp() + 100);
          characters.at(v)->setLevel((characters.at(v)->getXp() / 1000) + 1);
          cout << loser->getName()
               << "'s level: " << characters.at(v)->getLevel() << endl;
          cout << loser->getName() << "'s xp: " << characters.at(v)->getXp()
               << endl;
        }
      }

      for (auto Character : battle) {
        delete Character;
      }

      cout << "Game Over!" << endl << endl;
    } else if (input == "6") {

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
      cout << "Enter a selection" << endl << endl;
    } else {
      cout << "Invalid option" << endl << endl;
    }

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
    cout << "Enter a selection" << endl << endl;

    cin >> input;
  }
  cout << endl << "Closed game successfully" << endl;
  return 0;
}