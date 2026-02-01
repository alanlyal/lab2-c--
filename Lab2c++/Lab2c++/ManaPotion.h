#ifndef MANAPOTION_H
#define MANAPOTION_H

#include "Item.h"

class ManaPotion : public Item {
public:
	ManaPotion() : Item("Mana Potion") {}

	void use() override {
		std::cout << "Using Mana Potion: Restores 30 mana." << std::endl;
	}
};

#endif