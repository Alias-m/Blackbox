#ifndef BLACKBOX_BASE_EVENT_FACTORY_H
#define BLACKBOX_BASE_EVENT_FACTORY_H
#include "../events/QuitEvent.h"
#include "../events/WindowEvent.h"
#include "../events/mouse/MouseButtonEvent.h"
#include "../events/mouse/MouseMotionEvent.h"
#include "../events/mouse/MouseWheelEvent.h"
#include "../events/audio/AudioDeviceEvent.h"
#include "EventFactory.h"
#include "SDL2/SDL.h"

class BaseEventFactory : public EventFactory
{
    public:
        BaseEventFactory();
        ~BaseEventFactory();
};
#endif // BLACKBOX_BASE_EVENT_FACTORY_H
