#include "EventFactory.h"

EventFactory::EventFactory()
{
    default_event = new DefaultEvent();
}

Event* EventFactory::getEvent(int i)
{
    std::map<int, Event*>::iterator it;
    it = eventList.find(i);
    return it != eventList.end() ? eventList[i] : default_event;
}

void EventFactory::addEvent(Event* e)
{
    Event* event = getEvent(e->getType());
    if(event != default_event)
        delete event;
    eventList[e->getType()] = e;
}
