#ifndef DEBUG
#define DEBUG
#include "../../Blackbox/gui/events/BaseEventFactory.h"
#include "../../Blackbox/gui/events/MouseButtonEvent.h"
#include <iostream>
#include <map>

class DebugWindowEvent : public internal_event::DefaultWindowEvent
{
    public:
        virtual void showEvent(Component* c, WindowListener* listener);
        virtual void hideEvent(Component* c, WindowListener* listener);
        virtual void exposeEvent(Component* c, WindowListener* listener);
        virtual void moveEvent(Component* c, WindowListener* listener);
        virtual void resizeEvent(Component* c, WindowListener* listener);
        virtual void sizeChangedEvent(Component* c, WindowListener* listener);
        virtual void minimizedEvent(Component* c, WindowListener* listener);
        virtual void maximizedEvent(Component* c, WindowListener* listener);
        virtual void restoredEvent(Component* c, WindowListener* listener);
        virtual void enterEvent(Component* c, WindowListener* listener);
        virtual void leaveEvent(Component* c, WindowListener* listener);
        virtual void focusGainedEvent(Component* c, WindowListener* listener);
        virtual void focusLostEvent(Component* c, WindowListener* listener);
        virtual void closeEvent(Component* c, WindowListener* listener);
        virtual void takeFocusEvent(Component* c, WindowListener* listener);
        virtual void hitTestEvent(Component* c, WindowListener* listener);
        virtual void unknownEvent(Component* c, WindowListener* listener);
};

class DebugMouseMotionEvent : public MouseMotionEvent
{
    public:
        void operator()(Component* c, Listener* listener) const;
};

class DebugMouseClick : public internal_event::DefaultMouseEvent
{
    public:
        virtual void mouseLeftButtonClicked(Component* c, MouseButtonListener* listener);
};

class DebugEventFactory : public BaseEventFactory
{
    public:
        DebugEventFactory();
};
#endif // DEBUG
