#ifndef BLACKBOX_ACTIVE_EVENT_LISTENER_H
#define BLACKBOX_ACTIVE_EVENT_LISTENER_H
#include <map>
#include "Listener.h"
#include <iostream>
#include "SDL2/SDL.h"

class CommonEventListener : public Listener
{
    protected:
        SDL_CommonEvent event;
    public:
        CommonEventListener(SDL_CommonEvent& e);
        inline int getTarget() const { return 0;}
        inline int getType() const { return -1;}
        static Listener* create(SDL_Event* event);
};
#endif // BLACKBOX_ACTIVE_EVENT_LISTENER_H

