#include "MouseWheelListener.h"

MouseWheelListener::MouseWheelListener(SDL_MouseWheelEvent& e): event(e)
{
}
Listener* MouseWheelListener::create(SDL_Event* event)
{
    return new MouseWheelListener(event->wheel);
}
