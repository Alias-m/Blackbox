#include "WindowListener.h"

WindowListener::WindowListener(SDL_WindowEvent& e): event(e)
{
}
Listener* WindowListener::create(SDL_Event* event)
{
    return new WindowListener(event->window);
}
const int WindowListener::getWindowEvent() const
{
    return event.event;
}
