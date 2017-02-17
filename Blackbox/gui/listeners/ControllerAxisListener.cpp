#include "ControllerAxisListener.h"

ControllerAxisListener::ControllerAxisListener(SDL_ControllerAxisEvent& e): event(e)
{

}
Listener* ControllerAxisListener::create(SDL_Event* event)
{
    return new ControllerAxisListener(event->caxis);
}
