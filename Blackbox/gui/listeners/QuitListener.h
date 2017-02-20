#ifndef BLACKBOX_QUIT_LISTENER_H
#define BLACKBOX_QUIT_LISTENER_H
#include "SDL2/SDL.h"
#include "Listener.h"

class QuitListener : public Listener
{
    protected:
    public:
        inline int getTarget() const { return 0;}
        inline int getType() const { return SDL_QUIT;}
        static Listener* create(SDL_Event* event);
};
#endif // BLACKBOX_QUIT_LISTENER_H
