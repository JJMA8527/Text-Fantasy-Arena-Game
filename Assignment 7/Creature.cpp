#include "Creature.h"
#include <iostream>


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
}
/*2)Returns a int value representing damage.3)Generate a int value based on
strength. Displays how much damage the creature deals*/
int Creature::getDamage() {
	int dmg = (rand() % strength) + 1;
	cout << "The " << getSpecies() << " attacks for " << dmg << " points!";
	cout << endl;
	return dmg;
}
/*1) Pass by value representing start and end of range
2) Returns a random int within range. 3)Function works as a random generator*/
int Creature::randNum(int min, int max) {
	//generate random number between range
	return rand() % max + min;
}
/*Returns nothing. Function purpose is to display the stats for the player*/
void Creature::displayStats() {
	cout << "Player " << getSpecies() << " HP: " << getHP() << " "
		<< "Strength: " << getStr() << endl;
}
