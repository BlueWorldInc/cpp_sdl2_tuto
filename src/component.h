#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
class Entity;


class Component {
    public:
        Entity* owner;
        std::string componentName;
        virtual ~Component() {}
        virtual void initialize() {}
        virtual void update(float deltaTime) {}
        virtual void render() {}
        virtual void getInfo() {}
};

#endif