#ifndef BLACKBOX_MOUSE_MOTION_EVENT_H
#define BLACKBOX_MOUSE_MOTION_EVENT_H
#include "EventFactory.h"
#include "../listeners/MouseButtonListener.h"
#include "Event.h"
#include <iostream>
class Component;

class MouseMotionEvent : public Event
{
    public:
        virtual void operator()(Component* c, Listener* listener) const;
        void operator()(FrameManager* manager, Listener* listener) const;
        inline virtual int getType() const {return SDL_MOUSEMOTION;}
};
#endif // BLACKBOX_MOUSE_MOTION_EVENT_H
