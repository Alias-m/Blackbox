#include "MouseButtonEvent.h"
#include "../../../components/components.h"


MouseButtonEventDown::MouseButtonEventDown()
{
    std::cout << "INIT" << std::endl;
    event = new internal_event::MouseEventClicked();
    componentClick[SDL_BUTTON_LEFT] = &internal_event::MouseEventClicked::mouseLeftButtonClicked;
    componentClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEventClicked::mouseMiddleButtonClicked;
    componentClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEventClicked::mouseRightButtonClicked;
    componentClick[SDL_BUTTON_X1] =&internal_event::MouseEventClicked::mouseX1ButtonClicked;
    componentClick[SDL_BUTTON_X2] =&internal_event::MouseEventClicked::mouseX2ButtonClicked;
    managerClick[SDL_BUTTON_LEFT] = &internal_event::MouseEventClicked::mouseLeftButtonClicked;
    managerClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEventClicked::mouseMiddleButtonClicked;
    managerClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEventClicked::mouseRightButtonClicked;
    managerClick[SDL_BUTTON_X1] =&internal_event::MouseEventClicked::mouseX1ButtonClicked;
    managerClick[SDL_BUTTON_X2] =&internal_event::MouseEventClicked::mouseX2ButtonClicked;
}
MouseButtonEventDown::MouseButtonEventDown(internal_event::MouseEventClicked* e)
{
    event = e;
    componentClick[SDL_BUTTON_LEFT] = &internal_event::MouseEventClicked::mouseLeftButtonClicked;
    componentClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEventClicked::mouseMiddleButtonClicked;
    componentClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEventClicked::mouseRightButtonClicked;
    componentClick[SDL_BUTTON_X1] =&internal_event::MouseEventClicked::mouseX1ButtonClicked;
    componentClick[SDL_BUTTON_X2] =&internal_event::MouseEventClicked::mouseX2ButtonClicked;
    managerClick[SDL_BUTTON_LEFT] = &internal_event::MouseEventClicked::mouseLeftButtonClicked;
    managerClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEventClicked::mouseMiddleButtonClicked;
    managerClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEventClicked::mouseRightButtonClicked;
    managerClick[SDL_BUTTON_X1] =&internal_event::MouseEventClicked::mouseX1ButtonClicked;
    managerClick[SDL_BUTTON_X2] =&internal_event::MouseEventClicked::mouseX2ButtonClicked;
}
MouseButtonEventDown::~MouseButtonEventDown()
{
    delete event;
}

MouseButtonEventUp::MouseButtonEventUp()
{
    event = new internal_event::MouseEventReleased();
    componentClick[SDL_BUTTON_LEFT] = &internal_event::MouseEventReleased::mouseLeftButtonReleased;
    componentClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEventReleased::mouseMiddleButtonReleased;
    componentClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEventReleased::mouseRightButtonReleased;
    componentClick[SDL_BUTTON_X1] =&internal_event::MouseEventReleased::mouseX1ButtonReleased;
    componentClick[SDL_BUTTON_X2] =&internal_event::MouseEventReleased::mouseX2ButtonReleased;
    managerClick[SDL_BUTTON_LEFT] = &internal_event::MouseEventReleased::mouseLeftButtonReleased;
    managerClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEventReleased::mouseMiddleButtonReleased;
    managerClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEventReleased::mouseRightButtonReleased;
    managerClick[SDL_BUTTON_X1] =&internal_event::MouseEventReleased::mouseX1ButtonReleased;
    managerClick[SDL_BUTTON_X2] =&internal_event::MouseEventReleased::mouseX2ButtonReleased;
}
MouseButtonEventUp::MouseButtonEventUp(internal_event::MouseEventReleased* e)
{
    event = e;
    componentClick[SDL_BUTTON_LEFT] = &internal_event::MouseEventReleased::mouseLeftButtonReleased;
    componentClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEventReleased::mouseMiddleButtonReleased;
    componentClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEventReleased::mouseRightButtonReleased;
    componentClick[SDL_BUTTON_X1] =&internal_event::MouseEventReleased::mouseX1ButtonReleased;
    componentClick[SDL_BUTTON_X2] =&internal_event::MouseEventReleased::mouseX2ButtonReleased;
    managerClick[SDL_BUTTON_LEFT] = &internal_event::MouseEventReleased::mouseLeftButtonReleased;
    managerClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEventReleased::mouseMiddleButtonReleased;
    managerClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEventReleased::mouseRightButtonReleased;
    managerClick[SDL_BUTTON_X1] =&internal_event::MouseEventReleased::mouseX1ButtonReleased;
    managerClick[SDL_BUTTON_X2] =&internal_event::MouseEventReleased::mouseX2ButtonReleased;
}
MouseButtonEventUp::~MouseButtonEventUp()
{
    delete event;
}

void MouseButtonEventDown::operator()(Component* c, Listener* listener) const
{
    MouseButtonListener* l = dynamic_cast<MouseButtonListener*>(listener);
    (event->*((componentClick.find(l->buttonClicked()))->second))(c, l);
}

void MouseButtonEventDown::operator()(FrameManager* manager, Listener* listener) const
{
    MouseButtonListener* l = dynamic_cast<MouseButtonListener*>(listener);
    (event->*((managerClick.find(l->buttonClicked()))->second))(manager, l);
}

void MouseButtonEventUp::operator()(Component* c, Listener* listener) const
{
    MouseButtonListener* l = dynamic_cast<MouseButtonListener*>(listener);
    (event->*((componentClick.find(l->buttonClicked()))->second))(c, l);
}

void MouseButtonEventUp::operator()(FrameManager* manager, Listener* listener) const
{
    MouseButtonListener* l = dynamic_cast<MouseButtonListener*>(listener);
    (event->*((managerClick.find(l->buttonClicked()))->second))(manager, l);
}

void MouseButtonEventDown::addEvent(internal_event::InternalEvent* e)
{
    internal_event::MouseEventClicked* tmp = dynamic_cast<internal_event::MouseEventClicked*>(e);
    delete event;
    event = tmp;
}
void MouseButtonEventUp::addEvent(internal_event::InternalEvent* e)
{
    internal_event::MouseEventReleased* tmp = dynamic_cast<internal_event::MouseEventReleased*>(e);
    delete event;
    event = tmp;
}
