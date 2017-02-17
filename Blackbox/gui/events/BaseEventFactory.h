#ifndef BLACKBOX_BASE_EVENT_FACTORY_H
#define BLACKBOX_BASE_EVENT_FACTORY_H
#include "EventQuit.h"
#include "WindowEvent.h"
#include "MouseButtonEvent.h"
#include "MouseMotionEvent.h"
#include "EventFactory.h"
#include "SDL2/SDL.h"

class BaseEventFactory : public EventFactory
{
    public:
        BaseEventFactory();
        ~BaseEventFactory();
};
#endif // BLACKBOX_BASE_EVENT_FACTORY_H
