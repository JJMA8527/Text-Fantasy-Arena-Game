#pragma once
#include "Demon.h"

class Cyberdemon : public Demon {
public:
	Cyberdemon() :Demon() {};
	Cyberdemon(int newStr, int newHP) :Demon(newStr, newHP) {}
	int getDamage() override;
	string getSpecies()override {
		return "Cyberdemon";
	}
};