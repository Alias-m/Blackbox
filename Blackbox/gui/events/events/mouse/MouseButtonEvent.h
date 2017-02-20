#ifndef BLACKBOX_MOUSE_BUTTON_EVENT_H
#define BLACKBOX_MOUSE_BUTTON_EVENT_H
#define BLACKBOX_MOUSE_BUTTON_CLICKED_EVENT 1
#define BLACKBOX_MOUSE_BUTTON_RELEASED_EVENT 5
#include "../../../listeners/mouse/MouseButtonListener.h"
#include "../Event.h"
#include <iostream>
#include <map>

class Component;

namespace internal_event
{
    class MouseEvent : public InternalEvent
    {

    };
    class MouseEventClicked : public MouseEvent
    {
        public:
            inline virtual void mouseLeftButtonClicked(Component* c, MouseButtonListener* listener){}
            inline virtual void mouseLeftButtonClicked(FrameManager* c, MouseButtonListener* listener){}
            inline virtual void mouseRightButtonClicked(Component* c, MouseButtonListener* listener){}
            inline virtual void mouseRightButtonClicked(FrameManager* c, MouseButtonListener* listener){}
            inline virtual void mouseMiddleButtonClicked(Component* c, MouseButtonListener* listener){}
            inline virtual void mouseMiddleButtonClicked(FrameManager* c, MouseButtonListener* listener){}
            inline virtual void mouseX1ButtonClicked(Component* c, MouseButtonListener* listener){}
            inline virtual void mouseX1ButtonClicked(FrameManager* c, MouseButtonListener* listener){}
            inline virtual void mouseX2ButtonClicked(Component* c, MouseButtonListener* listener){}
            inline virtual void mouseX2ButtonClicked(FrameManager* c, MouseButtonListener* listener){}
            inline const int getType() const { return SDL_MOUSEBUTTONDOWN;}
    };

    class MouseEventReleased : public MouseEvent
    {
        public:
            inline virtual void mouseLeftButtonReleased(Component* c, MouseButtonListener* listener){}
            inline virtual void mouseLeftButtonReleased(FrameManager* c, MouseButtonListener* listener){}
            inline virtual void mouseRightButtonReleased(Component* c, MouseButtonListener* listener){}
            inline virtual void mouseRightButtonReleased(FrameManager* c, MouseButtonListener* listener){}
            inline virtual void mouseMiddleButtonReleased(Component* c, MouseButtonListener* listener){}
            inline virtual void mouseMiddleButtonReleased(FrameManager* c, MouseButtonListener* listener){}
            inline virtual void mouseX1ButtonReleased(Component* c, MouseButtonListener* listener){}
            inline virtual void mouseX1ButtonReleased(FrameManager* c, MouseButtonListener* listener){}
            inline virtual void mouseX2ButtonReleased(Component* c, MouseButtonListener* listener){}
            inline virtual void mouseX2ButtonReleased(FrameManager* c, MouseButtonListener* listener){}
            inline const int getType() const { return SDL_MOUSEBUTTONUP;}
    };
}

class MouseButtonEventDown : public Event
{
    typedef void(internal_event::MouseEventClicked::* componentButtonEvent)(Component* c, MouseButtonListener* listener);
    typedef void(internal_event::MouseEventClicked::* managerButtonEvent)(FrameManager* c, MouseButtonListener* listener);
    protected:
        internal_event::MouseEventClicked* event;
        std::map<int, componentButtonEvent> componentClick;
        std::map<int, managerButtonEvent> managerClick;
    public:
        MouseButtonEventDown();
        MouseButtonEventDown(internal_event::MouseEventClicked* e);
        ~MouseButtonEventDown();
        void operator()(Component* c, Listener* listener) const;
        void operator()(FrameManager* manager, Listener* listener) const;
        inline int getType() const {return SDL_MOUSEBUTTONDOWN;}
        void addEvent(internal_event::InternalEvent* e);
};

class MouseButtonEventUp : public Event
{
    typedef void(internal_event::MouseEventReleased::* componentButtonEvent)(Component* c, MouseButtonListener* listener);
    typedef void(internal_event::MouseEventReleased::* managerButtonEvent)(FrameManager* c, MouseButtonListener* listener);
    protected:
        internal_event::MouseEventReleased* event;
        std::map<int, componentButtonEvent> componentClick;
        std::map<int, managerButtonEvent> managerClick;
    public:
        MouseButtonEventUp();
        MouseButtonEventUp(internal_event::MouseEventReleased* e);
        ~MouseButtonEventUp();
        void operator()(Component* c, Listener* listener) const;
        void operator()(FrameManager* manager, Listener* listener) const;
        inline int getType() const {return SDL_MOUSEBUTTONUP;}
        void addEvent(internal_event::InternalEvent* e);
};
#endif // BLACKBOX_MOUSE_BUTTON_EVENT_H
