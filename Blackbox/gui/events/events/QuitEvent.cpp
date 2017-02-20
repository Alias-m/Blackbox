#include "QuitEvent.h"
#include "../../components/FrameManager.h"


QuitEvent::QuitEvent(): event(new internal_event::QuitEvent())
{

}
void QuitEvent::operator()(Component* c, Listener* listener) const
{
    QuitListener* q = dynamic_cast<QuitListener*>(listener);
    event->quit(c, q);
}

void QuitEvent::operator()(FrameManager* manager, Listener* listener) const
{
    QuitListener* q = dynamic_cast<QuitListener*>(listener);
    event->quit(manager, q);
}

void QuitEvent::addEvent(internal_event::InternalEvent* e)
{
    internal_event::QuitEvent* tmp = dynamic_cast<internal_event::QuitEvent*>(e);
    delete event;
    event = tmp;
}

void internal_event::QuitEvent::quit(Component* c, QuitListener* listener)
{

}
void internal_event::QuitEvent::quit(FrameManager* manager, QuitListener* listener)
{
    manager->close();
}
