#pragma once
#include "CharacterStats.h"

// No curly braces here! Just semicolons.
CharacterStats* createCharacterOnHeap(int hp, int mp, int sp, CharacterClass cls);
void deleteCharacter(CharacterStats* character);
void printStats(const CharacterStats& stats);