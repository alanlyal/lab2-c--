#include "CharacterStats.h"
#include "GameUtils.h"
#include <iostream>

#include "Inventory.h"
#include "HealthPotion.h"
#include "ManaPotion.h"

int main()
{
    //task 1
    CharacterStats warrior = { 100,50,75,CharacterClass::Warrior };// warrior lives on the stack
    printStats(warrior);// access the memory of stack on once main ends the warrior memory is freed
    CharacterStats* mage = createCharacterOnHeap(80, 100, 50, CharacterClass::Mage);//allocates object on heap
    printStats(*mage);//accesses heap onject via stack pointer
 
    deleteCharacter(mage);//free the heap memory
    return 0;

	//task 2
	Inventory inventory(3);

	inventory.addQuickItem(new HealthPotion(), 0);
	inventory.addQuickItem(new ManaPotion(), 1);

	inventory.addMainItem(new HealthPotion(), 0);
	inventory.addMainItem(new ManaPotion(), 1);

	inventory.addQuestItem(new HealthPotion());
	inventory.addQuestItem(new ManaPotion());

	inventory.useItem(0);
	inventory.useItem(1);
	inventory.useItem(4);

	inventory.useAllQuestItems();

	return 0;
}
