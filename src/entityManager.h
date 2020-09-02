#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "./entity.h"
#include "./component.h"
#include <vector>

class EntityManager {
    private:
        std::vector<Entity*> entities;
    public:
        void clearData();
        void update(float deltaTime);
        void render();
        void getInfo();
        bool hasNoEntities();
        Entity& addEntity(std::string entityName);
        std::vector<Entity*> getEntities() const;
        unsigned int getEntityCount();
};

#endif