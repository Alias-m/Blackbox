#ifndef BLACKBOX_DEFAULT_EVENT_H
#define BLACKBOX_DEFAULT_EVENT_H
#include <iostream>
#include "../listeners/WindowListener.h"
#include "Event.h"
class Component;

class DefaultEvent : public Event
{
    public:
        virtual void operator()(Component* c, Listener* listener) const;
        virtual void operator()(FrameManager* manager, Listener* listener) const;
        inline virtual int getType() const {return -1;}
};
#endif // BLACKBOX_DEFAULT_EVENT_H
