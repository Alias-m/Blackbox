#ifndef BLACKBOX_MOUSE_MOTION_LISTENER_H
#define BLACKBOX_MOUSE_MOTION_LISTENER_H
#include "SDL2/SDL.h"
#include "Listener.h"

class MouseMotionListener : public Listener
{
    protected:
        SDL_MouseMotionEvent event;
    public:
        MouseMotionListener(SDL_MouseMotionEvent& e);
        inline int getTarget() const { return event.windowID;}
        inline int getType() const { return event.type ;}
        static Listener* create(SDL_Event* event);
        inline int getX() const { return event.x ;}
        inline int getY() const { return event.y ;}
        inline int getRelX() const { return event.xrel ;}
        inline int getRelY() const { return event.yrel ;}
        // TODO : masque sur l'élément event.state
};
#endif // BLACKBOX_MOUSE_MOTION_LISTENER_H
