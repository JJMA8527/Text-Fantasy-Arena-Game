#include "Balrog.h"

/*2)Returns int value for balrog dmg. 3)Balrogs are fast so they get to strike
twice.*/
int Balrog::getDamage() {
	int dmg = Demon::getDamage();
	dmg += Demon::getDamage();
	return dmg;
}