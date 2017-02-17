#include "MouseMotionEvent.h"
#include "../components/components.h"

void MouseMotionEvent::operator()(Component* c, Listener* listener) const
{
    MouseMotionListener* l = dynamic_cast<MouseMotionListener*>(listener);
    std::cout << "Action de motion de souris sur la fenetre " << c->getID() << " : (" <<  l->getX() << ", " << l->getY() << "), real : (" << l->getRelX() << ", "<<l->getRelY()<< ")." << std::endl;
}

void MouseMotionEvent::operator()(FrameManager* manager, Listener* listener) const
{

}
