#include "Demon.h"
#include <iostream>

/*2)Returns int value for demon dmg. 3)Damage modified for Demon because
of their race. Adds 50 dmg additional if successful*/
int Demon::getDamage() {
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
}