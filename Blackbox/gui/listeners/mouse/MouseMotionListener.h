#ifndef BLACKBOX_MOUSE_MOTION_LISTENER_H
#define BLACKBOX_MOUSE_MOTION_LISTENER_H
#include "SDL2/SDL.h"
#include "../Listener.h"

class MouseMotionListener : public Listener
{
    protected:
        SDL_MouseMotionEvent event;
    public:
        MouseMotionListener(SDL_MouseMotionEvent& e);
        inline int getTarget() const { return event.windowID;}
        inline int getType() const { return event.type ;}
        static Listener* create(SDL_Event* event);
        inline bool isLeftButtonPressed() {return (event.state & SDL_BUTTON_LMASK);}
        inline bool isRightButtonPressed() {return (event.state & SDL_BUTTON_RMASK);}
        inline bool isMiddleButtonPressed() {return (event.state & SDL_BUTTON_MMASK);}
        inline bool isX1ButtonPressed() {return (event.state & SDL_BUTTON_X1MASK);}
        inline bool isX2ButtonPressed() {return (event.state & SDL_BUTTON_X2MASK);}
        inline int getX() const { return event.x ;}
        inline int getY() const { return event.y ;}
        inline int getRelX() const { return event.xrel ;}
        inline int getRelY() const { return event.yrel ;}
        //TODO : Touch du champ which
};
#endif // BLACKBOX_MOUSE_MOTION_LISTENER_H
