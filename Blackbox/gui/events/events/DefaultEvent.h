#ifndef BLACKBOX_DEFAULT_EVENT_H
#define BLACKBOX_DEFAULT_EVENT_H
#define BLACKBOX_DEFAULT_EVENT -1
#include <iostream>
#include "../../listeners/CommonEventListener.h"
#include "Event.h"
class Component;


namespace internal_event
{
    class DefaultEvent : public InternalEvent
    {
        public:
            inline const int getType() const {return -1;}
            virtual void action(Component* c, CommonEventListener* listener);
            virtual void action(FrameManager* c, CommonEventListener* listener);
    };
}
class DefaultEvent : public Event
{
    protected:
        internal_event::DefaultEvent* event;
    public:
        DefaultEvent();
        virtual void operator()(Component* c, Listener* listener) const;
        virtual void operator()(FrameManager* manager, Listener* listener) const;
        inline virtual int getType() const {return -1;}
        inline const int getID() const { return BLACKBOX_DEFAULT_EVENT;}
        void addEvent(internal_event::InternalEvent* e);
};
#endif // BLACKBOX_DEFAULT_EVENT_H
