#include "components.h"
void Component::close()
{

}

void Component::setEventFactory(EventFactory* e)
{
    delete events;
    events = e;
}

void Component::addEvent(Event* e)
{
    events->addEvent(e);
}

void Component::addEvent(internal_event::InternalEvent* e)
{
    events->addEvent(e);
}
