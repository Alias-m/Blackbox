#ifndef BLACKBOX_CONTROLLER_AXIS_LISTENER_H
#define BLACKBOX_CONTROLLER_AXIS_LISTENER_H
#include "SDL2/SDL.h"
#include "Listener.h"

class ControllerAxisListener : public Listener
{
    protected:
        SDL_ControllerAxisEvent event;
    public:
        ControllerAxisListener(SDL_ControllerAxisEvent& e);
        inline int getTarget() const { return 0;}
        inline int getType() const { return SDL_CONTROLLERAXISMOTION;}
        static Listener* create(SDL_Event* event);
};
#endif // BLACKBOX_CONTROLLER_AXIS_LISTENER_H
