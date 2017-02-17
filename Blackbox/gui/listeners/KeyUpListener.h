#ifndef BLACKBOX_KEYUP_LISTENER_H
#define BLACKBOX_KEYUP_LISTENER_H
#include "SDL2/SDL.h"
#include "Listener.h"

class KeyUpListener : public Listener
{
    protected:
        SDL_KeyboardEvent event;
    public:
        KeyUpListener(SDL_KeyboardEvent& e);
        inline int getTarget() const { return event.windowID;}
        inline int getType() const { return SDL_KEYUP;}
        static Listener* create(SDL_Event* event);
};
#endif // BLACKBOX_KEYUP_LISTENER_H

