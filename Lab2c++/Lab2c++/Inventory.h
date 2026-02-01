#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
private:
	static const int QUICK_SLOTS = 5;

	Item* quickAccess[QUICK_SLOTS];
	Item** mainInventory;
	int mainSize;

	std::vector<Item*> questItems;

public:
	Inventory(int Size);
	~Inventory();

	void addQuickItem(Item* item, int slot);
	void removeQuickItem(int slot);

	void addMainItem(Item* item, int index);
	void removeMainItem(int index);

	void addQuestItem(Item* item);
	void removeQuestItem(int index);

	void useItem(int slot);
	void useAllQuestItems();
};

#endif