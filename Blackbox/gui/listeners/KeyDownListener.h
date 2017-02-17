#ifndef BLACKBOX_KEYDOWN_LISTENER_H
#define BLACKBOX_KEYDOWN_LISTENER_H
#include "SDL2/SDL.h"
#include "Listener.h"
class KeyDownListener : public Listener
{
    protected:
        SDL_KeyboardEvent event;
    public:
        KeyDownListener(SDL_KeyboardEvent& e);
        inline int getTarget() const { return event.windowID;}
        inline int getType() const { return SDL_KEYDOWN;}
        static Listener* create(SDL_Event* event);
};
#endif // BLACKBOX_KEYDOWN_LISTENER_H

