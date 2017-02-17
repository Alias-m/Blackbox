#ifndef BLACKBOX_COMPONENT_H
#define BLACKBOX_COMPONENT_H
#include <vector>
#include "../../utils/Bounds.h"
#include "../../utils/Observable.h"
#include "../events/EventFactory.h"
#include "../listeners/ListenerFactory.h"

class Component;

class Component : public Observer
{
    protected:
        std::vector<Component*> components;
        Bounds bounds;
        EventFactory* events;
    private:

    public:
        inline Component(const int x = 0, const int y = 0, const int w = 0, const int h = 0): bounds(x, y, w, h) {}
        inline void addComponent(Component* c){components.push_back(c);}
        virtual void close();
        void setEventFactory(EventFactory* e);
        void addEvent(Event* e);
        virtual const int getID() const = 0;
};
#endif // BLACKBOX_COMPONENT_H
