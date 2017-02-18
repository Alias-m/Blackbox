#ifndef BLACKBOX_MOUSE_BUTTON_EVENT_H
#define BLACKBOX_MOUSE_BUTTON_EVENT_H
#include "EventFactory.h"
#include "../listeners/MouseButtonListener.h"
#include "Event.h"
#include <iostream>
#include <map>

class Component;

namespace internal_event
{
    class MouseEvent : public InternalEvent
    {
        public:
            inline virtual ~MouseEvent() {}
            virtual void mouseLeftButtonClicked(Component* c, MouseButtonListener* listener) = 0;
            virtual void mouseLeftButtonClicked(FrameManager* c, MouseButtonListener* listener) = 0;
            virtual void mouseRightButtonClicked(Component* c, MouseButtonListener* listener) = 0;
            virtual void mouseRightButtonClicked(FrameManager* c, MouseButtonListener* listener) = 0;
            virtual void mouseMiddleButtonClicked(Component* c, MouseButtonListener* listener) = 0;
            virtual void mouseMiddleButtonClicked(FrameManager* c, MouseButtonListener* listener) = 0;
            virtual void mouseX1ButtonClicked(Component* c, MouseButtonListener* listener) = 0;
            virtual void mouseX1ButtonClicked(FrameManager* c, MouseButtonListener* listener) = 0;
            virtual void mouseX2ButtonClicked(Component* c, MouseButtonListener* listener) = 0;
            virtual void mouseX2ButtonClicked(FrameManager* c, MouseButtonListener* listener) = 0;
    };

    class DefaultMouseEvent : public MouseEvent
    {
        public:
            virtual void mouseLeftButtonClicked(Component* c, MouseButtonListener* listener){}
            virtual void mouseLeftButtonClicked(FrameManager* c, MouseButtonListener* listener){}
            virtual void mouseRightButtonClicked(Component* c, MouseButtonListener* listener){}
            virtual void mouseRightButtonClicked(FrameManager* c, MouseButtonListener* listener){}
            virtual void mouseMiddleButtonClicked(Component* c, MouseButtonListener* listener){}
            virtual void mouseMiddleButtonClicked(FrameManager* c, MouseButtonListener* listener){}
            virtual void mouseX1ButtonClicked(Component* c, MouseButtonListener* listener){}
            virtual void mouseX1ButtonClicked(FrameManager* c, MouseButtonListener* listener){}
            virtual void mouseX2ButtonClicked(Component* c, MouseButtonListener* listener){}
            virtual void mouseX2ButtonClicked(FrameManager* c, MouseButtonListener* listener){}
    };
}
class MouseButtonEvent : public Event
{
    typedef void(internal_event::MouseEvent::* componentButtonEvent)(Component* c, MouseButtonListener* listener);
    typedef void(internal_event::MouseEvent::* managerButtonEvent)(FrameManager* c, MouseButtonListener* listener);
    protected:
        std::map<int, componentButtonEvent> componentClick;
        std::map<int, managerButtonEvent> managerClick;
        int type;
        internal_event::MouseEvent* event;
    public:
        MouseButtonEvent(int i);
        MouseButtonEvent(int i, internal_event::MouseEvent* event);
        ~MouseButtonEvent();
        virtual void operator()(Component* c, Listener* listener) const;
        void operator()(FrameManager* manager, Listener* listener) const;
        inline virtual int getType() const {return type;}
        void setEvent(internal_event::MouseEvent* e);
};
#endif // BLACKBOX_MOUSE_BUTTON_EVENT_H
