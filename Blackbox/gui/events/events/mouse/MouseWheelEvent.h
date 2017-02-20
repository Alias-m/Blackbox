#ifndef BLACKBOX_MOUSE_WHEEL_EVENT_H
#define BLACKBOX_MOUSE_WHEEL_EVENT_H
#include "../../../listeners/mouse/MouseWheelListener.h"
#include "../Event.h"
#include <iostream>
class Component;

namespace internal_event
{
    class MouseWheelEvent : public InternalEvent
    {
        public:
            virtual void mouseWheelPerformed(Component* c, MouseWheelListener* listener) {}
            virtual void mouseWheelPerformed(FrameManager* c, MouseWheelListener* listener) {}
            inline const int getType() const { return SDL_MOUSEWHEEL;}
    };
}
class MouseWheelEvent : public Event
{
    protected:
        internal_event::MouseWheelEvent* event;
    public:
        MouseWheelEvent();
        MouseWheelEvent(internal_event::MouseWheelEvent* event);
        ~MouseWheelEvent();
        void operator()(Component* c, Listener* listener) const;
        void operator()(FrameManager* manager, Listener* listener) const;
        inline int getType() const {return SDL_MOUSEWHEEL;}
        void addEvent(internal_event::InternalEvent* e);
};
#endif // BLACKBOX_MOUSE_MOTION_EVENT_H
