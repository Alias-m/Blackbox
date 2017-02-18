#include "Debug.h"
#include "../../Blackbox/gui/components/components.h"

DebugEventFactory::DebugEventFactory(): BaseEventFactory()
{
    WindowEvent* win = new WindowEvent();
    win->setEvent(new DebugWindowEvent());
    MouseButtonEvent* m1 = new MouseButtonEvent(SDL_MOUSEBUTTONDOWN);
    MouseButtonEvent* m2 = new MouseButtonEvent(SDL_MOUSEBUTTONUP);
    DebugMouseClick* custom = new DebugMouseClick();
    m1->setEvent(custom);
    m2->setEvent(custom);
    addEvent(new DebugMouseMotionEvent());
    addEvent(win);
    addEvent(m1);
    addEvent(m2);
}

void DebugMouseMotionEvent::operator()(Component* c, Listener* listener) const
{
    MouseMotionListener* l = dynamic_cast<MouseMotionListener*>(listener);
    std::cout << "Action de motion de souris sur la fenetre " << c->getID() << " : (" <<  l->getX() << ", " << l->getY() << "), real : (" << l->getRelX() << ", "<<l->getRelY()<< ")." << std::endl;
}

void DebugMouseClick::mouseLeftButtonClicked(Component* c, MouseButtonListener* listener)
{
    std::cout << "Action de bouton de souris sur la fenetre " << c->getID() << " : (" <<  listener->getX() << ", " << listener->getY() << "). Nombre de clicks : " << listener->getClicks() <<", press ? " << listener->isPressed() << ", released ? "<< listener->isReleased() << ", Bouton utilise : " << listener->buttonClicked() << std::endl;
}

void DebugWindowEvent::showEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d shown", c->getID());
}

void DebugWindowEvent::hideEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d hidden", c->getID());
}

void DebugWindowEvent::exposeEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d exposed", c->getID());
}

void DebugWindowEvent::moveEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d moved to %d,%d", c->getID(), listener->getData1(), listener->getData2());
}

void DebugWindowEvent::resizeEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d resized to %dx%d", c->getID(), listener->getData1(), listener->getData2());
}

void DebugWindowEvent::sizeChangedEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d size changed to %dx%d", c->getID(), listener->getData1(), listener->getData2());
}

void DebugWindowEvent::minimizedEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d minimized", c->getID());
}

void DebugWindowEvent::maximizedEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d maximized", c->getID());
}

void DebugWindowEvent::restoredEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d restored", c->getID());
}

void DebugWindowEvent::enterEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Mouse entered window %d", c->getID());
}

void DebugWindowEvent::leaveEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Mouse left window %d", c->getID());
}

void DebugWindowEvent::focusGainedEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d gained keyboard focus", c->getID());
}

void DebugWindowEvent::focusLostEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d lost keyboard focus", c->getID());
}

void DebugWindowEvent::closeEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d is closed", c->getID());
    c->close();
}

void DebugWindowEvent::takeFocusEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d is offered a focus", c->getID());
}

void DebugWindowEvent::hitTestEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d has a special hit test", c->getID());
}

void DebugWindowEvent::unknownEvent(Component* c, WindowListener* listener)
{
    SDL_Log("Window %d got unknown event", c->getID());
}
