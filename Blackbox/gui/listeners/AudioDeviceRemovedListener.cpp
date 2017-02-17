#include "AudioDeviceRemovedListener.h"

AudioDeviceRemovedListener::AudioDeviceRemovedListener(SDL_AudioDeviceEvent& e): event(e)
{

}
Listener* AudioDeviceRemovedListener::create(SDL_Event* event)
{
    return new AudioDeviceRemovedListener(event->adevice);
}
