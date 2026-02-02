#pragma once
#include <string>

// Base class: polymorphic (virtual functions)
class GameEntity {
public:
    explicit GameEntity(int id); 
    virtual ~GameEntity();                 // virtual because we will delete via base pointer

    int getId() const; 

    virtual std::string getType() const;   
    virtual void printInfo() const; 

protected:
    int id; 
};

// Derived class: Enemy
class Enemy : public GameEntity { 
public:
    Enemy(int id, int health);
    std::string getType() const override;
    void printInfo() const override; 

private:
    int health;
};

// Derived class: NPC
class NPC : public GameEntity {
public:
    NPC(int id, const std::string& dialogue); 
    std::string getType() const override;
    void printInfo() const override;

private:
    std::string dialogue;
};