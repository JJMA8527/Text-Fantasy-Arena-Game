#pragma once
#include "Creature.h"

class Demon :public Creature {
public:
	Demon() :Creature() {};
	Demon(int newStr, int newHP) :Creature(newStr, newHP) {}
	int getDamage() override;
	string getSpecies() override {
		return "Demon";
	}
};