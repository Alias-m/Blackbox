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
