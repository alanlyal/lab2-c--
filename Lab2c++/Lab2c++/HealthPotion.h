#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Item.h"

class HealthPotion : public Item {
public:
	HealthPotion() : Item("Health Potion") {}

	void use() override {
		std::cout << "Using Health Potion: Restores 50 health." << std::endl;
	}
};

#endif