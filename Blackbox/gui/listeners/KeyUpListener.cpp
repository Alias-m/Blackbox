#include "KeyUpListener.h"

KeyUpListener::KeyUpListener(SDL_KeyboardEvent& e): event(e)
{
}
Listener* KeyUpListener::create(SDL_Event* event)
{
    return new KeyUpListener(event->key);
}
