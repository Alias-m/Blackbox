#include "WindowEvent.h"
#include "../components/components.h"
#include "../listeners/WindowListener.h"
#include <iostream>

WindowEvent::WindowEvent()
{
    addEvent(new window_events::ShowEvent());
    addEvent(new window_events::HideEvent());
    addEvent(new window_events::ExposeEvent());
    addEvent(new window_events::MoveEvent());
    addEvent(new window_events::ResizeEvent());
    addEvent(new window_events::SizeChangedEvent());
    addEvent(new window_events::MinimizedEvent());
    addEvent(new window_events::MaximizedEvent());
    addEvent(new window_events::RestoredEvent());
    addEvent(new window_events::EnterEvent());
    addEvent(new window_events::LeaveEvent());
    addEvent(new window_events::FocusGainedEvent());
    addEvent(new window_events::FocusLostEvent());
    addEvent(new window_events::CloseEvent());
    addEvent(new window_events::TakeFocusEvent());
    addEvent(new window_events::HitTestEvent());
    addEvent(new window_events::UnknownEvent());
}

void WindowEvent::addEvent(window_events::WindowInternalEvent* e)
{

    std::map<int, window_events::WindowInternalEvent*>::const_iterator it;
    it = eventType.find(e->getType());
    if(it != eventType.end())
        delete it->second;
    eventType[e->getType()] = e;
}

void WindowEvent::operator()(Component* c, Listener* listener) const
{
    WindowListener* w = dynamic_cast<WindowListener*>(listener);
    (*getEvent(w->getWindowEvent()))(c, w);
}

void WindowEvent::operator()(FrameManager* manager, Listener* listener) const
{
    WindowListener* w = dynamic_cast<WindowListener*>(listener);
    (*getEvent(w->getWindowEvent()))(manager, w);
}

window_events::WindowInternalEvent* WindowEvent::getEvent(const int i) const
{
    std::map<int, window_events::WindowInternalEvent*>::const_iterator it;
    it = eventType.find(i);
    return it != eventType.end() ? it->second : eventType.find(-1)->second;
}



void window_events::ShowEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d shown", c->getID());
}

void window_events::ShowEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::HideEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d hidden", c->getID());
}
void window_events::HideEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::ExposeEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d exposed", c->getID());
}
void window_events::ExposeEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::MoveEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d moved to %d,%d", c->getID(), listener->getData1(), listener->getData2());
}
void window_events::MoveEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::ResizeEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d resized to %dx%d", c->getID(), listener->getData1(), listener->getData2());
}
void window_events::ResizeEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::SizeChangedEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d size changed to %dx%d", c->getID(), listener->getData1(), listener->getData2());
}
void window_events::SizeChangedEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::MinimizedEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d minimized", c->getID());
}
void window_events::MinimizedEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::MaximizedEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d maximized", c->getID());
}
void window_events::MaximizedEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::RestoredEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d restored", c->getID());
}
void window_events::RestoredEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::EnterEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Mouse entered window %d", c->getID());
}
void window_events::EnterEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::LeaveEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Mouse left window %d", c->getID());
}
void window_events::LeaveEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::FocusGainedEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d gained keyboard focus", c->getID());
}
void window_events::FocusGainedEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::FocusLostEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d lost keyboard focus", c->getID());
}
void window_events::FocusLostEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::CloseEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d is closed", c->getID());
    c->close();
}
void window_events::CloseEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::TakeFocusEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d is offered a focus", c->getID());
}
void window_events::TakeFocusEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::HitTestEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d has a special hit test", c->getID());
}
void window_events::HitTestEvent::operator()(FrameManager* manager, WindowListener* listener) const {}

void window_events::UnknownEvent::operator()(Component* c, WindowListener* listener) const
{
    SDL_Log("Window %d got unknown event", c->getID());
}
void window_events::UnknownEvent::operator()(FrameManager* manager, WindowListener* listener) const {}
