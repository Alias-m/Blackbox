#include "ListenerFactory.h"

ListenerFactory ListenerFactory::instance;


ListenerFactory::ListenerFactory()
{
    default_listener = CommonEventListener::create;
    listenerList[SDL_WINDOWEVENT] = WindowListener::create;
    listenerList[SDL_MOUSEBUTTONDOWN] = MouseButtonListener::create;
    listenerList[SDL_MOUSEBUTTONUP] = MouseButtonListener::create;
    listenerList[SDL_MOUSEMOTION] = MouseMotionListener::create;
    listenerList[SDL_MOUSEWHEEL] = MouseWheelListener::create;
    listenerList[SDL_QUIT] = QuitListener::create;
    listenerList[SDL_AUDIODEVICEADDED] = AudioDeviceListener::create;
    listenerList[SDL_AUDIODEVICEREMOVED] = AudioDeviceListener::create;

    //TODO : Simple � r�aliser
    //listenerList[SDL_CONTROLLERAXISMOTION] = ControllerAxisListener::create;
    //TODO : long � �crire
    //listenerList[SDL_KEYDOWN] = KeyDownListener::create;
    //listenerList[SDL_KEYUP] = KeyUpListener::create;


    /*
    listenerList[SDL_JOYAXISMOTION] = JoyAxisMotionListener();
    listenerList[SDL_JOYBALLMOTION] = JoyBallMotionListener();
    listenerList[SDL_JOYHATMOTION] = JoyHatListener();
    listenerList[SDL_JOYBUTTONDOWN] = JoyButtonDownListener();
    listenerList[SDL_JOYBUTTONUP] = JoyButtonUpListener();
    listenerList[SDL_SYSWMEVENT] = SysWEventListener();
    listenerList[SDL_VIDEORESIZE] = VideoResizeListener();
    listenerList[SDL_VIDEOEXPOSE] = VideoExposeListener();
    listenerList[SDL_USEREVENT] = UserEventListener();*/

}

ListenerFactory::~ListenerFactory()
{
    //TODO : delete all from tab
}

Listener* ListenerFactory::getListener(SDL_Event* event)
{
    std::map<int, generator>::iterator it;
    it = listenerList.find(event->type);
    return it != listenerList.end() ? listenerList[event->type](event) : default_listener(event);
}
