

#include "CharacterStats.h"
#include "GameUtils.h"
#include <iostream>

int main()
{
    //task 1
    CharacterStats warrior = { 100,50,75,CharacterClass::Warrior };// warrior lives on the stack
    printStats(warrior);// access the memory of stack on once main ends the warrior memory is freed
    CharacterStats* mage = createCharacterOnHeap(80, 100, 50, CharacterClass::Mage);//allocates object on heap
    printStats(*mage);//accesses heap onject via stack pointer
 
    deleteCharacter(mage);//free the heap memory
    return 0;
}


