#ifndef BLACKBOX_EVENT_H
#define BLACKBOX_EVENT_H
class Component;
class Listener;
class FrameManager;
class WindowListener;

namespace internal_event
{
    class InternalEvent
    {
        public:

    };
}
class Event
{
    public:
        virtual void operator()(Component* c, Listener* listener) const = 0;
        virtual void operator()(FrameManager* manager, Listener* listener) const = 0;
        virtual int getType() const = 0;
        inline virtual ~Event() {}
};
#endif // BLACKBOX_EVENT_H
