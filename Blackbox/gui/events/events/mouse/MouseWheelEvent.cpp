#include "MouseWheelEvent.h"

MouseWheelEvent::MouseWheelEvent(): event(new internal_event::MouseWheelEvent())
{

}

MouseWheelEvent::MouseWheelEvent(internal_event::MouseWheelEvent* e): event(e)
{

}

MouseWheelEvent::~MouseWheelEvent()
{
    delete event;
}

void MouseWheelEvent::operator()(Component* c, Listener* listener) const
{
      MouseWheelListener* l = dynamic_cast<MouseWheelListener*>(listener);
      event->mouseWheelPerformed(c, l);
}

void MouseWheelEvent::operator()(FrameManager* manager, Listener* listener) const
{
      MouseWheelListener* l = dynamic_cast<MouseWheelListener*>(listener);
      event->mouseWheelPerformed(manager, l);
}

void MouseWheelEvent::addEvent(internal_event::InternalEvent* e)
{
    internal_event::MouseWheelEvent* tmp = dynamic_cast<internal_event::MouseWheelEvent*>(e);
    delete event;
    event = tmp;
}
