#include "./entity.h"

Entity::Entity(EntityManager& manager): manager(manager) {
    this->active = true;
}

Entity::Entity(EntityManager& manager, std::string name): manager(manager), name(name) {
    this->active = true;
}

void Entity::update(float deltaTime) {
    for (auto& component: components) {
        component->update(deltaTime);
    }
}

void Entity::render() {
    for (auto& component: components) {
        component->render();
    }
}

void Entity::getInfo() {
    std::cout << "Entity Name: " << name << std::endl;
    for (auto& component: components) {
        component->getInfo();
    }
    std::cout << std::endl;
}

void Entity::destroy() {
    this->active = false;
}

bool Entity::isActive() const {
    return this->active;
}