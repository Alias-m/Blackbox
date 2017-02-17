#ifndef BLACKBOX_WINDOW_LISTENER_H
#define BLACKBOX_WINDOW_LISTENER_H
#include "SDL2/SDL.h"
#include "Listener.h"

class WindowListener : public Listener
{
    protected:
        SDL_WindowEvent event;
    public:
        WindowListener(SDL_WindowEvent& e);
        inline int getTarget() const { return event.windowID;}
        inline int getType() const { return SDL_WINDOWEVENT;}
        static Listener* create(SDL_Event* event);
        const int getWindowEvent() const;
        inline int getData1() const { return event.data1;}
        inline int getData2() const { return event.data2;}
};
#endif // BLACKBOX_WINDOW_LISTENER_H

