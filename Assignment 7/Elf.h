#pragma once
#include "Creature.h"

class Elf :public Creature {
public:
	Elf() :Creature() {}
	Elf(int newStr, int newHP) :Creature(newStr, newHP) {}
	int getDamage()override;
	string getSpecies() override {
		return "Elf";
	}
};