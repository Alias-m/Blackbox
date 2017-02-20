#include "QuitListener.h"

Listener* QuitListener::create(SDL_Event* event)
{
    return new QuitListener();
}
