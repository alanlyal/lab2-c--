#include "GameEntity.h"
#include <iostream>

// ---------- GameEntity ----------
GameEntity::GameEntity(int id) : id(id) {} 

GameEntity::~GameEntity() = default; 

int GameEntity::getId() const { 
    return id; 
}

std::string GameEntity::getType() const { 
    return "GameEntity"; 
}

void GameEntity::printInfo() const {
    std::cout << "[" << getType() << "] id=" << id << "\n"; 
}

// ---------- Enemy ----------
Enemy::Enemy(int id, int health) : GameEntity(id), health(health) {} 

std::string Enemy::getType() const { 
    return "Enemy";
}

void Enemy::printInfo() const {
    std::cout << "[" << getType() << "] id=" << id << ", health=" << health << "\n";
}

// ---------- NPC ----------
NPC::NPC(int id, const std::string& dialogue) : GameEntity(id), dialogue(dialogue) {} 

std::string NPC::getType() const {
    return "NPC";
}

void NPC::printInfo() const {
    std::cout << "[" << getType() << "] id=" << id << ", dialogue=\"" << dialogue << "\"\n";
}