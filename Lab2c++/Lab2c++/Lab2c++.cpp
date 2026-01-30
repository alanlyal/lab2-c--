

#include "CharacterStats.h"
#include "GameUtils.h"
#include <iostream>

int main()
{
    //task 1
    CharacterStats warrior = { 100,50,75,CharacterClass::Warrior };
    printStats(warrior);
    CharacterStats* mage = createCharacterOnHeap(80, 100, 50, CharacterClass::Mage);
    printStats(*mage);
 
    deleteCharacter(mage);
    return 0;
}


