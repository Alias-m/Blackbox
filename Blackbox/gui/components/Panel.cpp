#include "Panel.h"
#include "components.h"
Panel::Panel(const int x, const int y, const int w, const int h): Component(x,y,w,h)
{
    static int i = 0;
    if(i == 0)
        setBackgroundColor(Color::WHITE);
    else if(i == 1)
        setBackgroundColor(Color::GREEN);
    else if(i == 2)
        setBackgroundColor(Color::RED);
    i++;
}
void Panel::setBackgroundColor(Color c)
{
    background = c;
}
void Panel::close()
{
    SDL_DestroyTexture(texture);
}

void Panel::paintComponent(Graphics* g)
{
    static int x =0, y =0;
    g->setColor(&background);
    g->fillBackground();
    g->setColor(&Color::RED);
    g->drawPoint(x++,y++);
    //g->drawImage("694.png", 0, 0);
    bounds.setX(bounds.getX()+1);
    bounds.setY(bounds.getY()+1);
}
