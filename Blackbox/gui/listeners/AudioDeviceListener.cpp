#include "AudioDeviceListener.h"

AudioDeviceListener::AudioDeviceListener(SDL_AudioDeviceEvent& e): event(e)
{

}
Listener* AudioDeviceListener::create(SDL_Event* event)
{
    return new AudioDeviceListener(event->adevice);
}
