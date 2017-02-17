#ifndef BLACKBOX_EVENT_QUIT_H
#define BLACKBOX_EVENT_QUIT_H
#include "EventFactory.h"
#include "Event.h"
#include <iostream>
class Component;

class EventQuit : public Event
{
    public:
        virtual void operator()(Component* c, Listener* listener) const;
        void operator()(FrameManager* manager, Listener* listener) const;
        inline virtual int getType() const {return SDL_QUIT;}
};
#endif // BLACKBOX_EVENT_QUIT_H
