/*Assignment 7 - 3/18/2021
A fantasy game where the user can pick a race and fight against a opponent of 
their choosing. Uses class and inheritance to represent the different race. 
Compete in a simple battle arena and pray RNG blesses you.*/
#include <iostream>
#include <random>
#include <string>
#include "Creature.h"
#include "Human.h"
#include "Elf.h"
#include "Demon.h"
#include "Cyberdemon.h"
#include "Balrog.h"


using namespace std;
const int ELF_DMG = 10;//chances of dealing more dmg
const int DEMON_DMG = 5;

/*class Creature
{
protected:
	int type; 
	int strength; // How much damage we can inflict
	int hitpoints; // How much damage we can sustain
public:
	Creature() {
		//default for human or other
		type = 0;
		strength = 10;
		hitpoints = 10;
	}
	Creature(int newType, int newStrength, int newHit) {
		// Initialize creature to new type, strength, hit points
		// Also add appropriate accessor and mutator functions
		// for type, strength, and hit points
		type = newType;
		strength = newStrength;
		hitpoints = newHit;
	}
	Creature(int newStr, int newHP) {
		type = 0;
		strength = newStr;
		hitpoints = newHP;
	}
	// Returns amount of damage this creature 
	// inflicts in one round of combat
	 virtual int getDamage();
	 virtual string getSpecies()=0;//pure virtual function
	 int getType();
	 int getStr();
	 int getHP();
	 void setType(int type);
	 void setStr(int str);
	 void setHP(int hp);
	 int randNum(int min,int max);//random generator
	 void displayStats();
}; 

string Creature::getSpecies()
{
	return "Unknown";
}

//getter, setter functions for creature
int Creature::getType() {
	return type;
}
int Creature::getStr() {
	return strength;
}
int Creature::getHP() {
	return hitpoints;
}
void Creature::setStr(int str) {
	strength = str;
}
void Creature::setHP(int hp) {
	hitpoints = hp;
}
void Creature::setType(int type) {
	this->type = type;
} */

/*2)Returns a int value representing damage.3)Generate a int value based on 
strength. Displays how much damage the creature deals*/

/*int Creature::getDamage() {
	int dmg = (rand() % strength) + 1;
	cout << "The " << getSpecies() << " attacks for " << dmg << " points!";
	cout << endl;
	return dmg;
} /*

/*1) Pass by value representing start and end of range
2) Returns a random int within range. 3)Function works as a random generator*/
/*int Creature::randNum(int min, int max) {
	//generate random number between range
	return rand() % max + min;
}*/
/*Returns nothing. Function purpose is to display the stats for the player*/

/*void Creature::displayStats() {
	cout << "Player " <<getSpecies() << " HP: " << getHP() << " "
		<< "Strength: " << getStr() << endl;
} */


/*class Human :public Creature {
public:
	Human() :Creature() {} //call the base default class constructor
	Human(int newStr, int newHP) :Creature(newStr, newHP) {} //inherit base
	int getDamage()override;
	string getSpecies() override {
		return "Human";
	}

}; */

/*Returns the default base function*/

/*int Human::getDamage() {
	return Creature::getDamage();
}*/

/*class Elf :public Creature {
public:
	Elf() :Creature() {}
	Elf(int newStr, int newHP) :Creature(newStr, newHP) {}
	int getDamage()override;
	string getSpecies() override {
		return "Elf";
	}
}; */

/*2)Returns int value of dmg inflicted by elf. 3)Damage modified for Elf due to
their affinity for magic. Deals twice the dmg if successful chance*/

/*int Elf::getDamage() {
	//elves inflict double magic dmg with 10% chance
	int dmgMod = Creature::getDamage();
	int chance = randNum(0, 9);
	if (chance == 0) {
		cout << "Whoops! Missed your chance to deal additional damage" << endl;
	}
	else if(chance < 10 && chance > 0) {
		dmgMod *= 2;
		cout << "Success! Magical attack inflicts " << dmgMod << " additional "
			<< "points!" << endl;
		}
	return dmgMod;
} */

/*class Demon :public Creature {
public:
	Demon() :Creature() {};
	Demon(int newStr, int newHP) :Creature(newStr, newHP) {}
	int getDamage() override;
	string getSpecies() override {
		return "Demon";
	}
}; */

/*2)Returns int value for demon dmg. 3)Damage modified for Demon because 
of their race. Adds 50 dmg additional if successful*/

/*int Demon::getDamage() {
	int dmgMod = Creature::getDamage();
	int chance = randNum(0, 4);
	if (chance == 0) {
		cout << "Whoops! Missed your chance to deal additional damage" << endl;
	}
	else if (chance < 10 && chance > 0) {
		cout << "Success! Demonic attack inflicts 50 additinal damage" << endl;
		dmgMod += 50;
	}
	return dmgMod;
}*/

/*class Cyberdemon : public Demon {
public:
	Cyberdemon() :Demon() {};
	Cyberdemon(int newStr, int newHP):Demon(newStr,newHP){}
	int getDamage() override;
	string getSpecies()override {
		return "Cyberdemon";
	}
};*/

/*2)Returns int value of dmg 3)Refer to the Demon class for dmg explanation*/

/*int Cyberdemon::getDamage() {
	return Demon::getDamage();
}*/

/*class Balrog :public Demon {
public:
	Balrog() :Demon() {}
	Balrog(int newStr, int newHP) : Demon(newStr, newHP) {}
	int getDamage() override;
	string getSpecies() override {
		return "Balrog";
	}
};*/

/*2)Returns int value for balrog dmg. 3)Balrogs are fast so they get to strike
twice.*/

/*int Balrog::getDamage() {
	int dmg = Demon::getDamage();
	dmg += Demon::getDamage();
	return dmg;
}*/

/*1)Pass by two reference of class objects 2)return nothing 3)Player will be 
facing against the opponent they choose. Game will continue until one reaches 0
or both*/
void battleArena(Creature& c1, Creature& c2) {
	bool gameContinue = true;
	int hp1=c1.getHP(), hp2=c2.getHP();//stores hp values
	while (gameContinue) {
		hp1 = c1.getHP() - c2.getDamage();
		hp2 = c2.getHP() - c1.getDamage();
		cout << c1.getSpecies() << " remaining hp: " << hp1 << endl;
		cout << c2.getSpecies() << " remaining hp: " << hp2 << endl;
		 if (hp1 <= 0 && hp2 <= 0) {
			cout << "Tie! Both HP is less than or equal to 0" << endl;
			gameContinue = false;
			}
		 else if (hp1 <= 0) {
			cout << c1.getSpecies() << " received a critical hit! "
				<< "Unable to continue." << endl;
			cout << c2.getSpecies() << " wins!" << endl;
			gameContinue = false;
			}
		 else if (hp2 <= 0) {
			cout << c2.getSpecies() << " received a critical hit! "
				<< "Unable to continue. " << endl;
			cout << c1.getSpecies() << " wins!" << endl;
			gameContinue = false;

		}

	}
}
/*1)Pass by reference of class object 2)return nothing 3)User can customize 
stats if they want to within reasonable range(max:100) or have the random
generator do the work.*/
void customizeStats(Creature &c1) {
	int choice;
	int statHP, statDmg;//max stat is 100, default stat is 10
	cout << "Use randomizer or choose yourself? 1-random,2-do it yourself: ";
	cin >> choice;
	if (choice == 1) {
		cout << "Random stats done." << endl;
		statHP = rand() % 100 + 1;
		statDmg = rand() % 100 + 1;
		c1.setHP(statHP);
		c1.setStr(statDmg);
		c1.displayStats();
	}
	else if (choice == 2) {
		cout << "Please enter valid numbers for HP and Dmg (max:100): ";
		cin >> statHP;
		cin >> statDmg;
		if (statHP > 100 || statDmg > 100) {
			cout << "Only from 0-100. Try again." << endl;
			while (statHP > 100 || statDmg > 100) {
				cin >> statHP;
				cin >> statDmg;
			}
		}
		c1.setHP(statHP);
		c1.setStr(statDmg);
		c1.displayStats();
	}
	else {
		cout << "Invalid choice! Setting to default..." << endl;
		c1.getHP();
		c1.getStr();
		c1.displayStats();
	}

}
/*1)Pass by reference of class object 2)return nothing 3)Function purpose is
to select a random opponent with the given options. Stats are 
randomly generated.Player will then face the opponent in the battleArena*/
void selectMatch(Creature &player) {
	int ch;
	int statHP = rand() % 100 + 1;
	int statDmg = rand() % 100 + 1;
	cout << "Select your opponent ";
	cout << "1-Human, 2-Elf, 3-Demon, 4-Cyberdemon, 5-Balrog" << endl;
	cin >> ch;
	if (ch == 1) {
		Human cp;
		cp.setHP(statHP);
		cp.setStr(statDmg);
		cout << "Opponent " << cp.getSpecies() << " HP: " << cp.getHP() <<
			" " << "Strength: " << cp.getStr() << endl;
		battleArena(player, cp);
	}
	else if (ch == 2) {
		Elf cp;
		cp.setHP(statHP);
		cp.setStr(statDmg);
		cout << "Opponent " << cp.getSpecies() << " HP: " << cp.getHP() <<
			" " << "Strength: " << cp.getStr() << endl;
		battleArena(player, cp);
	}
	else if (ch == 3) {
		Demon cp;
		cp.setHP(statHP);
		cp.setStr(statDmg);
		cout << "Opponent " << cp.getSpecies() << " HP: " << cp.getHP() <<
			" " << "Strength: " << cp.getStr() << endl;
		battleArena(player, cp);
	}
	else if (ch == 4) {
		Cyberdemon cp;
		cp.setHP(statHP);
		cp.setStr(statDmg);
		cout << "Opponent " << cp.getSpecies() << " HP: " << cp.getHP() <<
			" " << "Strength: " << cp.getStr() << endl;
		battleArena(player, cp);
	}
	else if (ch == 5) {
		Balrog cp;
		cp.setHP(statHP);
		cp.setStr(statDmg);
		cout << "Opponent " << cp.getSpecies() << " HP: " << cp.getHP() <<
			" " << "Strength: " << cp.getStr() << endl;
		battleArena(player, cp);
	}
	else {
		cout << "Invalid choice. Setting enemy to human..." << endl;
		Human cp;
		cp.setHP(statHP);
		cp.setStr(statDmg);
		cout << "Opponent " << cp.getSpecies() << " HP: " << cp.getHP() <<
			" " << "Strength: " << cp.getStr() << endl;
		battleArena(player, cp);
	}
}


int main()
{
	srand(static_cast<int>(time(NULL)));
	int choice;
	string ch;
	bool restart = true;
	Human human1;
	Elf elf1;
	Demon demon1;
	Cyberdemon cdemon;
	Balrog balrog1;
	do {
		cout << "Pick your character from these options ";
		cout << "1-Human, 2-Elf, 3-Demon, 4-Cyberdemon, 5-Balrog" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "You've chosen human. Now, for the stats" << endl;
			customizeStats(human1);
			//pick your opponent
			selectMatch(human1);
		}
		else if (choice == 2) {
			cout << "You've chosen elf. Now, for the stats" << endl;
			customizeStats(elf1);
			selectMatch(elf1);
		}
		else if (choice == 3) {
			cout << "You've chosen demon. Now, for the stats" << endl;
			customizeStats(demon1);
			selectMatch(demon1);

		}
		else if (choice == 4) {
			cout << "You've chosen cyberdemon. Now, for the stats" << endl;
			customizeStats(cdemon);
			selectMatch(cdemon);

		}
		else if (choice == 5) {
			cout << "You've chosen balrog. Now, for the stats" << endl;
			customizeStats(balrog1);
			selectMatch(balrog1);
		}
		else {
			cout << "Invalid choice! Human set as default then..." << endl;
			customizeStats(human1);
			selectMatch(human1);
		}
		cout << "Do you wish to restart the match?(Y/N): ";
		cin.ignore();
		getline(cin, ch);
		if (ch == "Y" || ch == "y") {
			cout << "Next match!" << endl;
		}
		if (ch == "N" || ch == "n") {
			cout << "Goodbye." << endl;
			restart = false;
		}

	} while (restart);

	return 0;
}
/*Pick your character from these options 1-Human, 2-Elf, 3-Demon, 4-Cyberdemon, 5-Balrog
1
You've chosen human. Now, for the stats
Use randomizer or choose yourself? 1-random,2-do it yourself: 2
Please enter valid numbers for HP and Dmg (max:100): 50 200
Only from 0-100. Try again.
50 60
Player Human HP: 50 Strength: 60
Select your opponent 1-Human, 2-Elf, 3-Demon, 4-Cyberdemon, 5-Balrog
2
Opponent Elf HP: 34 Strength: 53
The Elf attacks for 51 points!
Success! Magical attack inflicts 102 additional points!
The Human attacks for 20 points!
Human remaining hp: -52
Elf remaining hp: 14
Human received a critical hit! Unable to continue.
Elf wins!
Do you wish to restart the match?(Y/N): y
Next match!
Pick your character from these options 1-Human, 2-Elf, 3-Demon, 4-Cyberdemon, 5-Balrog
3
You've chosen demon. Now, for the stats
Use randomizer or choose yourself? 1-random,2-do it yourself: 1
Random stats done.
Player Demon HP: 32 Strength: 41
Select your opponent 1-Human, 2-Elf, 3-Demon, 4-Cyberdemon, 5-Balrog
4
Opponent Cyberdemon HP: 66 Strength: 97
The Cyberdemon attacks for 51 points!
Success! Demonic attack inflicts 50 additinal damage
The Demon attacks for 7 points!
Whoops! Missed your chance to deal additional damage
Demon remaining hp: -69
Cyberdemon remaining hp: 59
Demon received a critical hit! Unable to continue.
Cyberdemon wins!
Do you wish to restart the match?(Y/N): y
Next match!
Pick your character from these options 1-Human, 2-Elf, 3-Demon, 4-Cyberdemon, 5-Balrog
5
You've chosen balrog. Now, for the stats
Use randomizer or choose yourself? 1-random,2-do it yourself: 1
Random stats done.
Player Balrog HP: 79 Strength: 62
Select your opponent 1-Human, 2-Elf, 3-Demon, 4-Cyberdemon, 5-Balrog
2
Opponent Elf HP: 81 Strength: 36
The Elf attacks for 7 points!
Success! Magical attack inflicts 14 additional points!
The Balrog attacks for 44 points!
Success! Demonic attack inflicts 50 additinal damage
The Balrog attacks for 31 points!
Success! Demonic attack inflicts 50 additinal damage
Balrog remaining hp: 65
Elf remaining hp: -94
Elf received a critical hit! Unable to continue.
Balrog wins!
Do you wish to restart the match?(Y/N): n
Goodbye.*/