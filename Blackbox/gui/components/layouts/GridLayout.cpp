#include "GridLayout.h"
#include "../components.h"
#include "../frames/Frame.h"


GridLayout::GridLayout(Component* c, unsigned int x, unsigned int y): x_pos(0), y_pos(0), x_size(x), y_size(y)
{
    container = c;
    if(x+y == 0)
        throw ("Layout size can't be infiny");
}



void GridLayout::addComponent(Component* c)
{
    if(x_pos == x_size)
    {
        x_pos = 0;
        y_pos++;
        if(y_pos > y_size && y_size != 0)
            throw("Layout is full");
    }
    //TODO : gérer division par 0
    int width = container->bounds.getWidth() / x_size;
    int height = container->bounds.getHeight() / y_size;
    c->bounds.setEditable(true);
    c->bounds.setX(x_pos * width);
    c->bounds.setY(y_pos * height);
    c->bounds.setWidth(width);
    c->bounds.setHeight(height);
    c->bounds.setEditable(false);
    x_pos++;
}
