#include <iostream>
#include "EntityContainer.h"
#include "GameEntity.h"

// Task 3 #4: template function outside the class
template <typename T>
void swapEntities(T *&a, T *&b)
{
    T *temp = a;
    a = b;
    b = temp;
}

int main()
{
    std::cout << "=== Task 3: EntityContainer demo ===\n";

    EntityContainer<GameEntity> container; // STACK: container is a local variable; it lives on da stack and is destroyed automatically at end of main.
    // The vector object itself is part of 'container' (stack here),
    // but the vector's *dynamic storage* for its elements grows on the HEAP as you push_back.

    // Create entities dynamically (on da heap) and add them to the container
    GameEntity *e1 = new Enemy(1, 100);
    GameEntity *e2 = new NPC(2, "Hello, traveler!");
    GameEntity *e3 = new Enemy(3, 250);
    GameEntity *e4 = new NPC(4, "Stay awhile and listen.");

    container.addEntity(e1);
    container.addEntity(e2);
    container.addEntity(e3);
    container.addEntity(e4);

    std::cout << "\n-- All entities (initial so before swap) --\n";
    container.printAllEntities();

    // Swap two entity POINTERS (not values)
    std::cout << "\n-- Swapping e1 and e4 pointers --\n";
    auto &vec = container.getAll();
    swapEntities(vec[0], vec[3]);

    std::cout << "\n-- Container AFTER swap --\n";
    container.printAllEntities();

    // Find by id
    int targetId = 3;
    std::cout << "\n-- Finding entity with id=" << targetId << " --\n";
    if (GameEntity *found = container.findEntityById(targetId))
    {
        found->printInfo();
    }
    else
    {
        std::cout << "Entity not found.\n";
    }

    // Remove an entity for the fun of it
    targetId = 2;
    std::cout << "\n-- Finding entity with id and the removing it from container=" << targetId << " --\n";
    if (GameEntity *toRemove = container.findEntityById(targetId))
    {
        container.removeEntity(toRemove);
        delete toRemove;
        std::cout << "\n-- Success! --\n";
    }
    else
    {
        std::cout << "Entity not found.\n";
    }

    // Clean up dynamic memory
    std::cout << "\n-- Cleaning up --\n";
    delete e1;
    delete e3;
    delete e4;

    std::cout << "Cleanup complete.\n";
    return 0;
}