#include "KeyDownListener.h"

KeyDownListener::KeyDownListener(SDL_KeyboardEvent& e): event(e)
{
}
Listener* KeyDownListener::create(SDL_Event* event)
{
    return new KeyDownListener(event->key);
}
