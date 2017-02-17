#ifndef CUSTOM
#define CUSTOM
#include "../Blackbox/gui/events/MouseButtonEvent.h"
#include "../Blackbox/gui/events/BaseEventFactory.h"
#include <iostream>
#include <map>

class Component;

class Custom : public mouse_button_event::DefaultMouseEvent
{
    public:
        inline virtual void mouseLeftButtonClicked(Component* c, MouseButtonListener* listener){     std::cout << "Action de bouton de souris sur la fenetre " << c->getID() << " : (" <<  listener->getX() << ", " << listener->getY() << "). Nombre de clicks : " << listener->getClicks() <<", press ? " << listener->isPressed() << ", released ? "<< listener->isReleased() << ", Bouton utilise : " << listener->buttonClicked() << std::endl;}
};

class CustomEventFactory : public BaseEventFactory
{
public:
    inline CustomEventFactory(): BaseEventFactory() {MouseButtonEvent* m1 = new MouseButtonEvent(SDL_MOUSEBUTTONDOWN);MouseButtonEvent* m2 = new MouseButtonEvent(SDL_MOUSEBUTTONUP);Custom* custom = new Custom();m1->setEvent(custom); m2->setEvent(custom);addEvent(m1);addEvent(m2);}
};
#endif // CUSTOM
