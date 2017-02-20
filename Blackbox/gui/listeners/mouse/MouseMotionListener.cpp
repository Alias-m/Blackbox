#include "MouseMotionListener.h"

MouseMotionListener::MouseMotionListener(SDL_MouseMotionEvent& e): event(e)
{
}
Listener* MouseMotionListener::create(SDL_Event* event)
{
    return new MouseMotionListener(event->motion);
}
