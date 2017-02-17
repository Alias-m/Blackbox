#include "AudioDeviceAddedListener.h"

AudioDeviceAddedListener::AudioDeviceAddedListener(SDL_AudioDeviceEvent& e): event(e)
{

}
Listener* AudioDeviceAddedListener::create(SDL_Event* event)
{
    return new AudioDeviceAddedListener(event->adevice);
}
