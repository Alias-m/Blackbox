#ifndef BLACKBOX_GRAPHICS_H
#define BLACKBOX_GRAPHICS_H
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Color.h"
#include "../../utils/Bounds.h"
class Component;
class Frame;

class Graphics
{
    protected:
        SDL_Renderer* renderer;
        Component* component;
    public:
        Graphics(Frame* f);
        inline virtual ~Graphics() {}
        void setRender(Component* c);
        void setColor(Color* c);
        void drawPoint(int x, int y);
        void drawImage(const char*, int x, int y);
        void finalize(Component* c);
        virtual void fillBackground();
        virtual void fillRectangle(Bounds& b);
};
#endif // BLACKBOX_GRAPHICS_H
