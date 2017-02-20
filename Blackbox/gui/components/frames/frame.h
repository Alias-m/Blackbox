#ifndef BLACKBOX_FRAME_H
#define BLACKBOX_FRAME_H
#define FRAME_INIT_FAIL "Frame initiation failed\n"
#define FRAME_CREATE_FAIL "Window creation failed\n"
#define FRAME_SHOW_FAIL "Frame display failed\n"
#define FRAME_CENTERED_X SDL_WINDOWPOS_CENTERED
#define FRAME_CENTERED_Y SDL_WINDOWPOS_CENTERED
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "../components.h"
#include "../../events/factories/BaseEventFactory.h"
class FrameManager;
class Frame : public Component
{
    protected:
        SDL_Window *frame;
        SDL_Renderer *renderer;
        std::string name;
    public:
        Frame(std::string n, const int x = FRAME_CENTERED_X, const int y = FRAME_CENTERED_Y, const int w = 0, const int h = 0) throw();
        void setVisible(bool b) throw();
        void notifyObserver(Observable* o);
        void close();
        const int getID() const;
        void execute(Listener* l);
};
#endif // BLACKBOX_FRAME_H
