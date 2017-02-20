#include "BaseEventFactory.h"

BaseEventFactory::BaseEventFactory(): EventFactory()
{
    eventList[SDL_QUIT] = new QuitEvent();
    eventList[SDL_WINDOWEVENT] = new WindowEvent();
    eventList[SDL_MOUSEBUTTONDOWN] = new MouseButtonEventDown();
    eventList[SDL_MOUSEBUTTONUP] = new MouseButtonEventUp();
    eventList[SDL_MOUSEWHEEL] = new MouseWheelEvent();
    eventList[SDL_MOUSEMOTION] = new MouseMotionEvent();
    eventList[SDL_AUDIODEVICEADDED] = new AudioDeviceAddedEvent();
    eventList[SDL_AUDIODEVICEREMOVED] = new AudioDeviceRemovedEvent();
}

BaseEventFactory::~BaseEventFactory()
{

}
