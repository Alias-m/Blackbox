#include "BaseEventFactory.h"

BaseEventFactory::BaseEventFactory(): EventFactory()
{
    eventList[SDL_QUIT] = new EventQuit();
    eventList[SDL_WINDOWEVENT] = new WindowEvent();
    eventList[SDL_MOUSEBUTTONDOWN] = new MouseButtonEvent(SDL_MOUSEBUTTONDOWN);
    eventList[SDL_MOUSEBUTTONUP] = new MouseButtonEvent(SDL_MOUSEBUTTONUP);
    eventList[SDL_MOUSEMOTION] = new MouseMotionEvent();
}

BaseEventFactory::~BaseEventFactory()
{

}
