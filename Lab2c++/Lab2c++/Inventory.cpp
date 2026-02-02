#include "Inventory.h"
#include "HealthPotion.h"
#include "ManaPotion.h"
#include <iostream>

Inventory::Inventory(int size) : mainSize(size) {
	for (int i = 0; i < QUICK_SLOTS; i++) {
		quickAccess[i] = nullptr;
	}

	mainInventory = new Item * [mainSize];
	for (int i = 0; i < mainSize; i++) {
		mainInventory[i] = nullptr;
	}
}

Inventory::~Inventory() {
	for (int i = 0; i < QUICK_SLOTS; i++) {
		delete quickAccess[i];
	}

	for (int i = 0; i < mainSize; i++) {
		delete mainInventory[i];
	}
	delete[] mainInventory;

	for (Item* item : questItems) {
		delete item;
	}
}

void Inventory::addQuickItem(Item* item, int slot) {
	if (slot >= 0 && slot < QUICK_SLOTS) {
		quickAccess[slot] = item;
	}
}

void Inventory::removeQuickItem(int slot) {
	if (slot >= 0 && slot < QUICK_SLOTS) {
		delete quickAccess[slot];
		quickAccess[slot] = nullptr;
	}
}

void Inventory::addMainItem(Item* item, int index) {
	if (index >= 0 && index < mainSize) {
		mainInventory[index] = item;
	}
}

void Inventory::removeMainItem(int index) {
	if (index >= 0 && index < mainSize) {
		delete mainInventory[index];
		mainInventory[index] = nullptr;
	}
}

void Inventory::addQuestItem(Item* item) {
	questItems.push_back(item);
}

void Inventory::removeQuestItem(int index) {
	if (index >= 0 && index < questItems.size()) {
		delete questItems[index];
		questItems.erase(questItems.begin() + index);
	}
}

void Inventory::useItem(int slot) {
	if (slot < 0 || slot >= QUICK_SLOTS || quickAccess[slot] == nullptr) {
		std::cout << "Invalid or empty quick-access slot." << std::endl;
		return;
	}

	if (HealthPotion* hp = dynamic_cast<HealthPotion*>(quickAccess[slot])) {
		hp->use();
	}
	else if (ManaPotion* mp = dynamic_cast<ManaPotion*>(quickAccess[slot])) {
		mp->use();
	}
	else {
		std::cout << "Item type not usable." << std::endl;
	}
}

void Inventory::useAllQuestItems() {
	for (Item* item : questItems) {
		item->use();
	}
}