#pragma once
#include "Creature.h"

class Human :public Creature {
public:
	Human() :Creature() {} //call the base default class constructor
	Human(int newStr, int newHP) :Creature(newStr, newHP) {} //inherit base
	int getDamage()override;
	string getSpecies() override {
		return "Human";
	}

};