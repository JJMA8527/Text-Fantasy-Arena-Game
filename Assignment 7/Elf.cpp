#include "Elf.h"
#include <iostream>

/*2)Returns int value of dmg inflicted by elf. 3)Damage modified for Elf due to
their affinity for magic. Deals twice the dmg if successful chance*/
int Elf::getDamage() {
	//elves inflict double magic dmg with 10% chance
	int dmgMod = Creature::getDamage();
	int chance = randNum(0, 9);
	if (chance == 0) {
		cout << "Whoops! Missed your chance to deal additional damage" << endl;
	}
	else if (chance < 10 && chance > 0) {
		dmgMod *= 2;
		cout << "Success! Magical attack inflicts " << dmgMod << " additional "
			<< "points!" << endl;
	}
	return dmgMod;
}