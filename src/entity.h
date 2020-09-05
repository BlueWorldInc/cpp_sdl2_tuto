#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "./entityManager.h"
#include "./component.h"
#include <cxxabi.h>

class EntityManager;
class Component;

class Entity {
    private:
        EntityManager& manager; // une adresse d'un entityMananger
        bool active;
        std::vector<Component*> components;
        std::map<const std::type_info*, Component*> componentTypeMap;
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
            components.emplace_back(newComponent);
            componentTypeMap[&typeid(*newComponent)] = newComponent;
            newComponent->initialize();
            return *newComponent;
        }

        template <typename T>
        T* GetComponent() {
            return static_cast<T*>(componentTypeMap[&typeid(T)]);
        }

        template <typename T>
        bool hasComponent() {
            return (bool) (componentTypeMap.find(&typeid(T)) != componentTypeMap.end());
            //  if (componentTypeMap.find(&typeid(T)) == componentTypeMap.end()) {
            // if (componentTypeMap.count(&typeid(T)) == 0) {
                //  return false;
            //  } else {
                //  return true;
            //  }
        }
};

#endif
