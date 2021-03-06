#ifndef BLACKBOX_WINDOW_EVENT_H
#define BLACKBOX_WINDOW_EVENT_H
#include <iostream>
#include "../listeners/WindowListener.h"
#include "Event.h"
#include <map>
class Component;


namespace internal_event
{
    class WindowEvent : public InternalEvent
    {
        public:
            inline virtual ~WindowEvent() {}
            virtual void showEvent(Component* c, WindowListener* listener) = 0;
            virtual void showEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void hideEvent(Component* c, WindowListener* listener) = 0;
            virtual void hideEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void exposeEvent(Component* c, WindowListener* listener) = 0;
            virtual void exposeEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void moveEvent(Component* c, WindowListener* listener) = 0;
            virtual void moveEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void resizeEvent(Component* c, WindowListener* listener) = 0;
            virtual void resizeEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void sizeChangedEvent(Component* c, WindowListener* listener) = 0;
            virtual void sizeChangedEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void minimizedEvent(Component* c, WindowListener* listener) = 0;
            virtual void minimizedEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void maximizedEvent(Component* c, WindowListener* listener) = 0;
            virtual void maximizedEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void restoredEvent(Component* c, WindowListener* listener) = 0;
            virtual void restoredEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void enterEvent(Component* c, WindowListener* listener) = 0;
            virtual void enterEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void leaveEvent(Component* c, WindowListener* listener) = 0;
            virtual void leaveEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void focusGainedEvent(Component* c, WindowListener* listener) = 0;
            virtual void focusGainedEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void focusLostEvent(Component* c, WindowListener* listener) = 0;
            virtual void focusLostEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void closeEvent(Component* c, WindowListener* listener) = 0;
            virtual void closeEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void takeFocusEvent(Component* c, WindowListener* listener) = 0;
            virtual void takeFocusEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void hitTestEvent(Component* c, WindowListener* listener) = 0;
            virtual void hitTestEvent(FrameManager* c, WindowListener* listener) = 0;
            virtual void unknownEvent(Component* c, WindowListener* listener) = 0;
            virtual void unknownEvent(FrameManager* c, WindowListener* listener) = 0;
    };

    class DefaultWindowEvent : public WindowEvent
    {
        public:
            inline virtual void showEvent(Component* c, WindowListener* listener) {}
            inline virtual void showEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void hideEvent(Component* c, WindowListener* listener) {}
            inline virtual void hideEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void exposeEvent(Component* c, WindowListener* listener) {}
            inline virtual void exposeEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void moveEvent(Component* c, WindowListener* listener) {}
            inline virtual void moveEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void resizeEvent(Component* c, WindowListener* listener) {}
            inline virtual void resizeEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void sizeChangedEvent(Component* c, WindowListener* listener) {}
            inline virtual void sizeChangedEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void minimizedEvent(Component* c, WindowListener* listener) {}
            inline virtual void minimizedEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void maximizedEvent(Component* c, WindowListener* listener) {}
            inline virtual void maximizedEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void restoredEvent(Component* c, WindowListener* listener) {}
            inline virtual void restoredEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void enterEvent(Component* c, WindowListener* listener) {}
            inline virtual void enterEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void leaveEvent(Component* c, WindowListener* listener) {}
            inline virtual void leaveEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void focusGainedEvent(Component* c, WindowListener* listener) {}
            inline virtual void focusGainedEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void focusLostEvent(Component* c, WindowListener* listener) {}
            inline virtual void focusLostEvent(FrameManager* c, WindowListener* listener) {}
            virtual void closeEvent(Component* c, WindowListener* listener);
            inline virtual void closeEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void takeFocusEvent(Component* c, WindowListener* listener) {}
            inline virtual void takeFocusEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void hitTestEvent(Component* c, WindowListener* listener) {}
            inline virtual void hitTestEvent(FrameManager* c, WindowListener* listener) {}
            inline virtual void unknownEvent(Component* c, WindowListener* listener) {}
            inline virtual void unknownEvent(FrameManager* c, WindowListener* listener) {}
    };
}

class WindowEvent : public Event
{
    typedef void(internal_event::WindowEvent::* componentWindowEvent)(Component* c, WindowListener* listener);
    typedef void(internal_event::WindowEvent::* managerWindowEvent)(FrameManager* c, WindowListener* listener);
    private:
        std::map<int, componentWindowEvent> componentWindow;
        std::map<int, managerWindowEvent> managerWindow;
        internal_event::WindowEvent* event;
    public:
        WindowEvent();
        ~WindowEvent();
        virtual void operator()(Component* c, Listener* listener) const;
        virtual void operator()(FrameManager* manager, Listener* listener) const;
        void setEvent(internal_event::WindowEvent* e);
        inline virtual int getType() const {return SDL_WINDOWEVENT;}
};
#endif // BLACKBOX_WINDOW_EVENT_H
