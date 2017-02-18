#include "WindowEvent.h"
#include "../components/components.h"
#include "../listeners/WindowListener.h"
#include <iostream>

WindowEvent::WindowEvent():event(new internal_event::DefaultWindowEvent())
{
    componentWindow[SDL_WINDOWEVENT_SHOWN] = &internal_event::WindowEvent::showEvent;
    componentWindow[SDL_WINDOWEVENT_HIDDEN] = &internal_event::WindowEvent::hideEvent;
    componentWindow[SDL_WINDOWEVENT_EXPOSED] = &internal_event::WindowEvent::exposeEvent;
    componentWindow[SDL_WINDOWEVENT_MOVED] = &internal_event::WindowEvent::moveEvent;
    componentWindow[SDL_WINDOWEVENT_RESIZED] = &internal_event::WindowEvent::resizeEvent;
    componentWindow[SDL_WINDOWEVENT_SIZE_CHANGED] = &internal_event::WindowEvent::sizeChangedEvent;
    componentWindow[SDL_WINDOWEVENT_MINIMIZED] = &internal_event::WindowEvent::minimizedEvent;
    componentWindow[SDL_WINDOWEVENT_MAXIMIZED] = &internal_event::WindowEvent::maximizedEvent;
    componentWindow[SDL_WINDOWEVENT_RESTORED] = &internal_event::WindowEvent::restoredEvent;
    componentWindow[SDL_WINDOWEVENT_ENTER] = &internal_event::WindowEvent::enterEvent;
    componentWindow[SDL_WINDOWEVENT_LEAVE] = &internal_event::WindowEvent::leaveEvent;
    componentWindow[SDL_WINDOWEVENT_FOCUS_GAINED] = &internal_event::WindowEvent::focusGainedEvent;
    componentWindow[SDL_WINDOWEVENT_FOCUS_LOST] = &internal_event::WindowEvent::focusLostEvent;
    componentWindow[SDL_WINDOWEVENT_CLOSE] = &internal_event::WindowEvent::closeEvent;
    componentWindow[SDL_WINDOWEVENT_TAKE_FOCUS] = &internal_event::WindowEvent::takeFocusEvent;
    componentWindow[SDL_WINDOWEVENT_HIT_TEST] = &internal_event::WindowEvent::hitTestEvent;
    componentWindow[-1] = &internal_event::WindowEvent::unknownEvent;

    managerWindow[SDL_WINDOWEVENT_SHOWN] = &internal_event::WindowEvent::showEvent;
    managerWindow[SDL_WINDOWEVENT_HIDDEN] = &internal_event::WindowEvent::hideEvent;
    managerWindow[SDL_WINDOWEVENT_EXPOSED] = &internal_event::WindowEvent::exposeEvent;
    managerWindow[SDL_WINDOWEVENT_MOVED] = &internal_event::WindowEvent::moveEvent;
    managerWindow[SDL_WINDOWEVENT_RESIZED] = &internal_event::WindowEvent::resizeEvent;
    managerWindow[SDL_WINDOWEVENT_SIZE_CHANGED] = &internal_event::WindowEvent::sizeChangedEvent;
    managerWindow[SDL_WINDOWEVENT_MINIMIZED] = &internal_event::WindowEvent::minimizedEvent;
    managerWindow[SDL_WINDOWEVENT_MAXIMIZED] = &internal_event::WindowEvent::maximizedEvent;
    managerWindow[SDL_WINDOWEVENT_RESTORED] = &internal_event::WindowEvent::restoredEvent;
    managerWindow[SDL_WINDOWEVENT_ENTER] = &internal_event::WindowEvent::enterEvent;
    managerWindow[SDL_WINDOWEVENT_LEAVE] = &internal_event::WindowEvent::leaveEvent;
    managerWindow[SDL_WINDOWEVENT_FOCUS_GAINED] = &internal_event::WindowEvent::focusGainedEvent;
    managerWindow[SDL_WINDOWEVENT_FOCUS_LOST] = &internal_event::WindowEvent::focusLostEvent;
    managerWindow[SDL_WINDOWEVENT_CLOSE] = &internal_event::WindowEvent::closeEvent;
    managerWindow[SDL_WINDOWEVENT_TAKE_FOCUS] = &internal_event::WindowEvent::takeFocusEvent;
    managerWindow[SDL_WINDOWEVENT_HIT_TEST] = &internal_event::WindowEvent::hitTestEvent;
    managerWindow[-1] = &internal_event::WindowEvent::unknownEvent;
}

WindowEvent::~WindowEvent()
{
    delete event;
}
void WindowEvent::operator()(Component* c, Listener* listener) const
{
    WindowListener* w = dynamic_cast<WindowListener*>(listener);
    componentWindowEvent method;
    std::map<int,componentWindowEvent>::const_iterator it;
    it = componentWindow.find(w->getWindowEvent());
    method = (it != componentWindow.end() ? it->second : componentWindow.find(-1)->second);
    (event->*method)(c, w);
}

void WindowEvent::operator()(FrameManager* manager, Listener* listener) const
{
    WindowListener* w = dynamic_cast<WindowListener*>(listener);
    managerWindowEvent method;
    std::map<int,managerWindowEvent>::const_iterator it;
    it = managerWindow.find(w->getWindowEvent());
    method = (it != managerWindow.end() ? it->second : managerWindow.find(-1)->second);
    (event->*method)(manager, w);
}

void WindowEvent::setEvent(internal_event::WindowEvent* e)
{
    delete event;
    event = e;
}

void internal_event::DefaultWindowEvent::closeEvent(Component* c, WindowListener* listener)
{
    c->close();
}
