#ifndef BLACKBOX_LISTENER_FACTORY_H
#define BLACKBOX_LISTENER_FACTORY_H
#include "Listener.h"
#include <map>
#include <SDL2/SDL.h>
#include "CommonEventListener.h"
#include "AudioDeviceListener.h"
#include "ControllerAxisListener.h"
#include "KeyDownListener.h"
#include "KeyUpListener.h"
#include "mouse/MouseButtonListener.h"
#include "mouse/MouseMotionListener.h"
#include "mouse/MouseWheelListener.h"
#include "WindowListener.h"
#include "QuitListener.h"

typedef Listener*(*generator)(SDL_Event*);
class ListenerFactory final
{
    private:
        ListenerFactory();
        std::map<int, generator> listenerList;
        generator default_listener;
    public:
        static ListenerFactory instance;
        ~ListenerFactory();
        Listener* getListener(SDL_Event*);
};
#endif // BLACKBOX_LISTENER_FACTORY_H
