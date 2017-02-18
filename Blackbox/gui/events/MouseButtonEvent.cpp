#include "MouseButtonEvent.h"
#include "../components/components.h"


MouseButtonEvent::MouseButtonEvent(int i): type(i), event(new internal_event::DefaultMouseEvent())
{
    componentClick[SDL_BUTTON_LEFT] = &internal_event::MouseEvent::mouseLeftButtonClicked;
    componentClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEvent::mouseMiddleButtonClicked;
    componentClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEvent::mouseRightButtonClicked;
    componentClick[SDL_BUTTON_X1] =&internal_event::MouseEvent::mouseX1ButtonClicked;
    componentClick[SDL_BUTTON_X2] =&internal_event::MouseEvent::mouseX2ButtonClicked;
    managerClick[SDL_BUTTON_LEFT] = &internal_event::MouseEvent::mouseLeftButtonClicked;
    managerClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEvent::mouseMiddleButtonClicked;
    managerClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEvent::mouseRightButtonClicked;
    managerClick[SDL_BUTTON_X1] =&internal_event::MouseEvent::mouseX1ButtonClicked;
    managerClick[SDL_BUTTON_X2] =&internal_event::MouseEvent::mouseX2ButtonClicked;
}
MouseButtonEvent::MouseButtonEvent(int i, internal_event::MouseEvent* e): type(i), event(e)
{
    componentClick[SDL_BUTTON_LEFT] = &internal_event::MouseEvent::mouseLeftButtonClicked;
    componentClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEvent::mouseMiddleButtonClicked;
    componentClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEvent::mouseRightButtonClicked;
    componentClick[SDL_BUTTON_X1] =&internal_event::MouseEvent::mouseX1ButtonClicked;
    componentClick[SDL_BUTTON_X2] =&internal_event::MouseEvent::mouseX2ButtonClicked;
    managerClick[SDL_BUTTON_LEFT] = &internal_event::MouseEvent::mouseLeftButtonClicked;
    managerClick[SDL_BUTTON_MIDDLE] = &internal_event::MouseEvent::mouseMiddleButtonClicked;
    managerClick[SDL_BUTTON_RIGHT] =&internal_event::MouseEvent::mouseRightButtonClicked;
    managerClick[SDL_BUTTON_X1] =&internal_event::MouseEvent::mouseX1ButtonClicked;
    managerClick[SDL_BUTTON_X2] =&internal_event::MouseEvent::mouseX2ButtonClicked;
}
MouseButtonEvent::~MouseButtonEvent()
{
    delete event;
}
void MouseButtonEvent::operator()(Component* c, Listener* listener) const
{
    MouseButtonListener* l = dynamic_cast<MouseButtonListener*>(listener);
    (event->*((componentClick.find(l->buttonClicked()))->second))(c, l);
}

void MouseButtonEvent::operator()(FrameManager* manager, Listener* listener) const
{
    MouseButtonListener* l = dynamic_cast<MouseButtonListener*>(listener);
    (event->*((managerClick.find(l->buttonClicked()))->second))(manager, l);
}

void MouseButtonEvent::setEvent(internal_event::MouseEvent* e)
{
    delete event;
    event = e;
}
