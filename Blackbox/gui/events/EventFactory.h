#ifndef BLACKBOX_EVENT_FACTORY_H
#define BLACKBOX_EVENT_FACTORY_H
#include "Event.h"
#include "DefaultEvent.h"
#include <map>
#include <iostream>
class EventFactory
{
    protected:
        std::map<int, Event*> eventList;
        Event* default_event;
    public:
        EventFactory();
        inline ~EventFactory() { delete default_event;}
        inline void setEvent(int i, Event* e) {eventList[i] = e;}
        Event* getEvent(int i);
        void addEvent(Event* e);
};
#endif // BLACKBOX_EVENT_FACTORY_H
