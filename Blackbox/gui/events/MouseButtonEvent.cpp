#include "MouseButtonEvent.h"
#include "../components/components.h"


MouseButtonEvent::MouseButtonEvent(int i): type(i), event(new mouse_button_event::DefaultMouseEvent())
{
    componentClick[SDL_BUTTON_LEFT] = &mouse_button_event::MouseEvent::mouseLeftButtonClicked;
    componentClick[SDL_BUTTON_MIDDLE] = &mouse_button_event::MouseEvent::mouseMiddleButtonClicked;
    componentClick[SDL_BUTTON_RIGHT] =&mouse_button_event::MouseEvent::mouseRightButtonClicked;
    componentClick[SDL_BUTTON_X1] =&mouse_button_event::MouseEvent::mouseX1ButtonClicked;
    componentClick[SDL_BUTTON_X2] =&mouse_button_event::MouseEvent::mouseX2ButtonClicked;
    managerClick[SDL_BUTTON_LEFT] = &mouse_button_event::MouseEvent::mouseLeftButtonClicked;
    managerClick[SDL_BUTTON_MIDDLE] = &mouse_button_event::MouseEvent::mouseMiddleButtonClicked;
    managerClick[SDL_BUTTON_RIGHT] =&mouse_button_event::MouseEvent::mouseRightButtonClicked;
    managerClick[SDL_BUTTON_X1] =&mouse_button_event::MouseEvent::mouseX1ButtonClicked;
    managerClick[SDL_BUTTON_X2] =&mouse_button_event::MouseEvent::mouseX2ButtonClicked;
}
MouseButtonEvent::MouseButtonEvent(int i, mouse_button_event::MouseEvent* e): type(i), event(e)
{
    componentClick[SDL_BUTTON_LEFT] = &mouse_button_event::MouseEvent::mouseLeftButtonClicked;
    componentClick[SDL_BUTTON_MIDDLE] = &mouse_button_event::MouseEvent::mouseMiddleButtonClicked;
    componentClick[SDL_BUTTON_RIGHT] =&mouse_button_event::MouseEvent::mouseRightButtonClicked;
    componentClick[SDL_BUTTON_X1] =&mouse_button_event::MouseEvent::mouseX1ButtonClicked;
    componentClick[SDL_BUTTON_X2] =&mouse_button_event::MouseEvent::mouseX2ButtonClicked;
    managerClick[SDL_BUTTON_LEFT] = &mouse_button_event::MouseEvent::mouseLeftButtonClicked;
    managerClick[SDL_BUTTON_MIDDLE] = &mouse_button_event::MouseEvent::mouseMiddleButtonClicked;
    managerClick[SDL_BUTTON_RIGHT] =&mouse_button_event::MouseEvent::mouseRightButtonClicked;
    managerClick[SDL_BUTTON_X1] =&mouse_button_event::MouseEvent::mouseX1ButtonClicked;
    managerClick[SDL_BUTTON_X2] =&mouse_button_event::MouseEvent::mouseX2ButtonClicked;
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

void MouseButtonEvent::setEvent(mouse_button_event::MouseEvent* e)
{
    delete event;
    event = e;
}
