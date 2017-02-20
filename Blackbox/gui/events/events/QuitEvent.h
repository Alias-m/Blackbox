#ifndef BLACKBOX_QUIT_EVENT_H
#define BLACKBOX_QUIT_EVENT_H
#define BLACKBOX_QUIT_EVENT 4
#include "Event.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "../../listeners/QuitListener.h"

class Component;

namespace internal_event
{
    class QuitEvent : public InternalEvent
    {
        public:
            inline const int getType() const {return SDL_QUIT;}
            virtual void quit(Component* c, QuitListener* listener);
            virtual void quit(FrameManager* c, QuitListener* listener);
    };
}
class QuitEvent : public Event
{
    protected:
        internal_event::QuitEvent* event;
    public:
        QuitEvent();
        void operator()(Component* c, Listener* listener) const;
        void operator()(FrameManager* manager, Listener* listener) const;
        inline int getType() const {return SDL_QUIT;}
        void addEvent(internal_event::InternalEvent* e);
};
#endif // BLACKBOX_QUIT_EVENT_H
