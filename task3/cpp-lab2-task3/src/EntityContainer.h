#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

// Template container that stores pointers to entities (T*).
// Assumes T has:
//   - int getId() const
//   - void printInfo() const
template <typename T>
class EntityContainer
{
public:
    // Adds a pointer to the container (does NOT take ownership by itself).
    // Caller is still responsible for deleting
    void addEntity(T *entity)
    {
        if (!entity)
            return; // ignore null pointers
        entities.push_back(entity);
    }

    // Removes the pointer from the container (does NOT delete it).
    // Removes ALL matching pointers.
    void removeEntity(T *entity)
    {
        if (!entity)
            return;

        entities.erase(
            std::remove(entities.begin(), entities.end(), entity),
            entities.end());
    }

    // Finds the FIRST entity whose getId() matches.
    // Returns nullptr if not found.
    T *findEntityById(int id)
    {
        for (T *e : entities)
        {
            if (e && e->getId() == id)
            {
                return e;
            }
        }
        return nullptr;
    }

    // Prints all entities by calling their printInfo() method.
    void printAllEntities() const
    {
        for (const T *e : entities)
        {
            if (e)
            {
                e->printInfo();
            }
        }
    }

    std::vector<T *> &getAll() { return entities; }
    const std::vector<T *> &getAll() const { return entities; }

private:
    std::vector<T *> entities;
};
