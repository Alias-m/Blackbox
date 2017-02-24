#include "components.h"
#include "frames/frame.h"
void Component::close()
{

}

void Component::setEventFactory(EventFactory* e)
{
    delete events;
    events = e;
}

void Component::addEvent(Event* e)
{
    events->addEvent(e);
}

void Component::addEvent(internal_event::InternalEvent* e)
{
    events->addEvent(e);
}

void Component::paint(Graphics* g)
{
    g->setRender(this);
    g->setColor(&Color::BLACK);
    paintComponent(g);
    g->finalize(parent);
    for(std::vector<Component*>::iterator it = components.begin(); it != components.end(); it++)
    {
        (*it)->paint(g);
    }
}
Bounds Component::getShowableBounds()
{
    if(parent)
    {
        Bounds b = parent->getShowableBounds();
        b.setEditable(true);
        int x = bounds.getX() + b.getX();
        int y = bounds.getY() + b.getY();

        int bound_width = x + bounds.getWidth();
        int b_width = b.getX() + b.getWidth();
        int width = bound_width > b_width ? bounds.getWidth() - (bound_width - b_width) : bounds.getWidth();

        int bound_height = y + bounds.getHeight();
        int b_height = b.getY() + b.getHeight();
        int height = bound_height > b_height ? bounds.getHeight() - (bound_height - b_height) : bounds.getHeight();

        b.setX(x);
        b.setY(y);
        b.setWidth(width);
        b.setHeight(height);
        return b;
    }
    else
        return bounds;
}

void Component::addComponent(Component* c)
{
    components.push_back(c);
    c->parent = this;
    std::cout << "KOUKOU > "<<getContainer() <<std::endl;
    getContainer()->link(c);
    if(layout != NULL)
    {
        layout->addComponent(c);
        c->bounds.setEditable(false);
    }
}

void Component::link()
{

}
Component* Component::find(int x, int y) const
{
    for(std::vector<Component*>::const_iterator it = components.begin(); it != components.end(); it++)
        if((*it)->match(x, y))
            return (*it);
    return NULL;
}
bool Component::match(const int x, const int y)
{
    int x_value = getXToFrame();
    int y_value = getYToFrame();
    return (x >= x_value && x <= x_value + bounds.getWidth()) && (y >= y_value && y <= y_value + bounds.getHeight());
}
