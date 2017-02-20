#ifndef BLACKBOX_MOUSE_WHEEL_LISTENER_H
#define BLACKBOX_MOUSE_WHEEL_LISTENER_H
#include "SDL2/SDL.h"
#include "../Listener.h"

class MouseWheelListener : public Listener
{
    protected:
        SDL_MouseWheelEvent event;
    public:
        MouseWheelListener(SDL_MouseWheelEvent& e);
        inline int getTarget() const { return event.windowID;}
        inline int getType() const { return event.type ;}
        static Listener* create(SDL_Event* event);
        inline int getX() const { return event.direction == SDL_MOUSEWHEEL_FLIPPED ? - event.x : event.x ;}
        inline int getY() const { return event.direction == SDL_MOUSEWHEEL_FLIPPED ? - event.y : event.y ;}
        //SDL_TOUCH_MOUSEID pour le champ which, � tester avec l'event SDL_TouchFingerEvent
};
#endif // BLACKBOX_MOUSE_WHEEL_LISTENER_H
