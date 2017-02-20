#ifndef BLACKBOX_MOUSE_BUTTON_LISTENER_H
#define BLACKBOX_MOUSE_BUTTON_LISTENER_H
#include "SDL2/SDL.h"
#include "../Listener.h"

class MouseButtonListener : public Listener
{
    protected:
        SDL_MouseButtonEvent event;
    public:
        MouseButtonListener(SDL_MouseButtonEvent& e);
        inline int getTarget() const { return event.windowID;}
        inline int getType() const { return event.type ;}
        static Listener* create(SDL_Event* event);
        inline int getX() const { return event.x ;}
        inline int getY() const { return event.y ;}
        inline int getClicks() const { return event.clicks ;}
        inline bool isPressed() const { return event.state == SDL_PRESSED;}
        inline bool isReleased() const { return event.state == SDL_RELEASED;}
        inline int buttonClicked() const { return event.button;} // TODO : objets foncteur pour chaque valeur possible :  SDL_BUTTON_LEFT, SDL_BUTTON_MIDDLE, SDL_BUTTON_RIGHT, SDL_BUTTON_X1, SDL_BUTTON_X2
        //SDL_TOUCH_MOUSEID pour le champ which, � tester avec l'event SDL_TouchFingerEvent
};
#endif // BLACKBOX_MOUSE_BUTTON_DOWN_LISTENER_H
