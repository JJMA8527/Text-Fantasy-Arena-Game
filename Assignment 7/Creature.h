#pragma once
#include <string>
using namespace std;

class Creature
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
	virtual string getSpecies() = 0;//pure virtual function
	int getType();
	int getStr();
	int getHP();
	void setType(int type);
	void setStr(int str);
	void setHP(int hp);
	int randNum(int min, int max);//random generator
	void displayStats();
};