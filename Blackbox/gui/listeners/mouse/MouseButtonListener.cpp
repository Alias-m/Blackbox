#include "MouseButtonListener.h"

MouseButtonListener::MouseButtonListener(SDL_MouseButtonEvent& e): event(e)
{
}
Listener* MouseButtonListener::create(SDL_Event* event)
{
    return new MouseButtonListener(event->button);
}
