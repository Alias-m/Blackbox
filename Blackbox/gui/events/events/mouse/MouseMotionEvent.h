#ifndef BLACKBOX_MOUSE_MOTION_EVENT_H
#define BLACKBOX_MOUSE_MOTION_EVENT_H
#define BLACKBOX_MOUSE_MOTION_EVENT 2
#include "../../../listeners/mouse/MouseMotionListener.h"
#include "../Event.h"
#include <iostream>
class Component;

namespace internal_event
{
    class MouseMotionEvent : public InternalEvent
    {
        public:
            virtual void mouseMotionPerformed(Component* c, MouseMotionListener* listener) {};
            virtual void mouseMotionPerformed(FrameManager* c, MouseMotionListener* listener) {};
            inline const int getType() const { return SDL_MOUSEMOTION;}
    };
}
class MouseMotionEvent : public Event
{
    protected:
        internal_event::MouseMotionEvent* event;
    public:
        MouseMotionEvent();
        MouseMotionEvent(internal_event::MouseMotionEvent* event);
        ~MouseMotionEvent();
        void operator()(Component* c, Listener* listener) const;
        void operator()(FrameManager* manager, Listener* listener) const;
        inline int getType() const {return SDL_MOUSEMOTION;}
        void addEvent(internal_event::InternalEvent* e);
};
#endif // BLACKBOX_MOUSE_MOTION_EVENT_H
