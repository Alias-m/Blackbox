#include "DefaultEvent.h"
#include "../../components/components.h"

DefaultEvent::DefaultEvent(): event(new internal_event::DefaultEvent())
{

}
void DefaultEvent::operator()(Component* c, Listener* listener) const
{
    CommonEventListener* q = dynamic_cast<CommonEventListener*>(listener);
    event->action(c, q);
}

void DefaultEvent::operator()(FrameManager* manager, Listener* listener) const
{
    CommonEventListener* q = dynamic_cast<CommonEventListener*>(listener);
    event->action(manager, q);
}

void DefaultEvent::addEvent(internal_event::InternalEvent* e)
{
    internal_event::DefaultEvent* tmp = dynamic_cast<internal_event::DefaultEvent*>(e);
    delete event;
    event = tmp;
}

void internal_event::DefaultEvent::action(Component* c, CommonEventListener* listener)
{
    std::cout << "DefaultEvent performed on the window " << c->getID() << std::endl;
}
void internal_event::DefaultEvent::action(FrameManager* manager, CommonEventListener* listener)
{
    std::cout << "DefaultEvent performed" << std::endl;
}
