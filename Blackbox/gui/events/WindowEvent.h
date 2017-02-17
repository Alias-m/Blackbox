#ifndef BLACKBOX_WINDOW_EVENT_H
#define BLACKBOX_WINDOW_EVENT_H
#include <iostream>
#include "../listeners/WindowListener.h"
#include "Event.h"
#include <map>
class Component;


namespace window_events
{
    class WindowInternalEvent
    {
        public:
            inline virtual ~WindowInternalEvent() {}
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            virtual int getType() const = 0;
    };
    class UnknownEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            int getType() const { return -1;}
    };
    class ShowEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_SHOWN;}
    };
    class HideEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_HIDDEN;}
    };
    class ExposeEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_EXPOSED;}
    };
    class MoveEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_MOVED;}
    };
    class ResizeEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_RESIZED;}
    };
    class SizeChangedEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_SIZE_CHANGED;}
    };
    class MinimizedEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_MINIMIZED;}
    };
    class MaximizedEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_MAXIMIZED;}
    };
    class RestoredEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_RESTORED;}
    };
    class EnterEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_ENTER;}
    };
    class LeaveEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_LEAVE;}
    };
    class FocusGainedEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_FOCUS_GAINED;}
    };
    class FocusLostEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_FOCUS_LOST;}
    };
    class CloseEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_CLOSE;}
    };
    class TakeFocusEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_TAKE_FOCUS;}
    };
    class HitTestEvent : public WindowInternalEvent
    {
        public:
            virtual void operator()(Component* c, WindowListener* listener) const;
            virtual void operator()(FrameManager* c, WindowListener* listener) const;
            inline int getType() const { return SDL_WINDOWEVENT_HIT_TEST;}
    };
}

class WindowEvent : public Event
{
    private:
        std::map<int, window_events::WindowInternalEvent*> eventType;
    public:
        WindowEvent();
        virtual void operator()(Component* c, Listener* listener) const;
        virtual void operator()(FrameManager* manager, Listener* listener) const;
        void addEvent(window_events::WindowInternalEvent* e);
        window_events::WindowInternalEvent* getEvent(const int i) const;
        inline virtual int getType() const {return SDL_WINDOWEVENT;}
};
#endif // BLACKBOX_WINDOW_EVENT_H
