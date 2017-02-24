#ifndef BLACKBOX_LAYOUT_H
#define BLACKBOX_LAYOUT_H
#include <string>
#include <iostream>
#include <SDL2/SDL.h>

class Component;
class Frame;

class Layout
{
    protected:
    public:
        inline ~Layout() {}
        virtual void addComponent(Component* c) = 0;
};
#endif // BLACKBOX_COLOR_H
