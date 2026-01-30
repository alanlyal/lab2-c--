#include "GameUtils.h"
#include <iostream>
void printStats(const CharacterStats& stats)
{
	std::cout << "character stats";
	std::cout << "hp: "<<stats.health;
	std::cout << "mana: " << stats.mana;
	std::cout << "stamina: " << stats.stamina;
	std::cout << "class: ";
	switch (stats.characterClass) 
	{
	case CharacterClass::Warrior: std::cout << "warrior";break;
	case CharacterClass::Mage: std::cout << "mage";break;
	case CharacterClass::Archer: std::cout << "Archer";break;
	}
}
void deleteCharacter(CharacterStats* character)
{
	delete character;
}