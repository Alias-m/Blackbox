#include "CommonEventListener.h"

CommonEventListener::CommonEventListener(SDL_CommonEvent& e): event(e)
{
}
Listener* CommonEventListener::create(SDL_Event* event)
{
    return new CommonEventListener(event->common);
}
