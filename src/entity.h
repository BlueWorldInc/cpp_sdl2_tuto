#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>

class Component;
class EntityManager;

class Entity {
    private:
        EntityManager& manager; // une adresse d'un entityMananger
        bool active;
        std::vector<Component*> components;
    public:
        std::string name;
        Entity(EntityManager& manager);
        Entity(EntityManager& manager, std::string name);
        void update(float deltaTime);
        void render();
        void destroy();
        bool isActive() const; // on ajoute le const pour éviter que cette méthode/fonction modifie les membres de la classe. https://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-function-declaration-of-a-class
};

#endif