#pragma once
#include "Demon.h"

class Balrog :public Demon {
public:
	Balrog() :Demon() {}
	Balrog(int newStr, int newHP) : Demon(newStr, newHP) {}
	int getDamage() override;
	string getSpecies() override {
		return "Balrog";
	}
};