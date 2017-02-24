#ifndef BLACKBOX_EVENT_H
#define BLACKBOX_EVENT_H
class Component;
class Listener;
class FrameManager;
class WindowListener;
//TODO : finir events https://wiki.libsdl.org/SDL_Event
namespace internal_event
{
    class InternalEvent
    {
        public:
            inline virtual ~InternalEvent() {}
            virtual const int getType() const = 0;
    };
}

class Event
{
    public:
        virtual void operator()(Component* c, Listener* listener) const = 0;
        virtual void operator()(FrameManager* manager, Listener* listener) const = 0;
        virtual int getType() const = 0;
        inline virtual ~Event() {}
        virtual void addEvent(internal_event::InternalEvent* e) = 0;
};
#endif // BLACKBOX_EVENT_H
