#ifndef BLACKBOX_GRID_LAYOUT_H
#define BLACKBOX_GRID_LAYOUT_H
#include "Layout.h"

class GridLayout : public Layout
{
    protected:
        Component* container;
        unsigned int x_pos;
        unsigned int y_pos;
        unsigned int x_size;
        unsigned int y_size;
    public:
        GridLayout(Component* f, unsigned int x = 1, unsigned int y = 1);
        virtual void addComponent(Component* c);
};
#endif // BLACKBOX_GRID_LAYOUT_H
