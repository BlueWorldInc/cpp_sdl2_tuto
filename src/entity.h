#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <string>
#include "./entityManager.h"
#include "./component.h"
#include <cxxabi.h>

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
        void getInfo();
        void destroy();
        bool isActive() const; // on ajoute le const pour éviter que cette méthode/fonction modifie les membres de la classe. https://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-function-declaration-of-a-class

        template <typename T, typename... TArgs>
        T& AddComponent(TArgs&&... args) {
            T* newComponent(new T(std::forward<TArgs>(args)...));
            newComponent->owner = this;
            // newComponent->componentName = typeid(T).name(); // old way
            newComponent->componentName = abi::__cxa_demangle(typeid(T).name(), 0, 0, 0); // demangling way see this: https://stackoverflow.com/a/23319351
            components.emplace_back(newComponent);
            newComponent->initialize();
            return *newComponent;
        }
};

#endif