#include "MouseMotionEvent.h"

MouseMotionEvent::MouseMotionEvent(): event(new internal_event::MouseMotionEvent())
{

}

MouseMotionEvent::MouseMotionEvent(internal_event::MouseMotionEvent* e): event(e)
{

}

MouseMotionEvent::~MouseMotionEvent()
{
    delete event;
}

void MouseMotionEvent::operator()(Component* c, Listener* listener) const
{
      MouseMotionListener* l = dynamic_cast<MouseMotionListener*>(listener);
      event->mouseMotionPerformed(c, l);
}

void MouseMotionEvent::operator()(FrameManager* manager, Listener* listener) const
{
      MouseMotionListener* l = dynamic_cast<MouseMotionListener*>(listener);
      event->mouseMotionPerformed(manager, l);
}

void MouseMotionEvent::addEvent(internal_event::InternalEvent* e)
{
    internal_event::MouseMotionEvent* tmp = dynamic_cast<internal_event::MouseMotionEvent*>(e);
    delete event;
    event = tmp;
}
