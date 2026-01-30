#pragma once
#include "CharacterStats.h"
CharacterStats* createCharacterOnHeap(int hp, int mp, int sp, CharacterClass cls);
void deleteCharacter(CharacterStats* ptr);