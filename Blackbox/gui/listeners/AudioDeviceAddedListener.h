#ifndef BLACKBOX_AUDIO_DEVICE_ADDED_LISTENER_H
#define BLACKBOX_AUDIO_DEVICE_ADDED_LISTENER_H
#include "SDL2/SDL.h"
#include "Listener.h"

class AudioDeviceAddedListener : public Listener
{
    protected:
        SDL_AudioDeviceEvent event;
    public:
        AudioDeviceAddedListener(SDL_AudioDeviceEvent& e);
        inline int getTarget() const { return 0;}
        inline int getType() const { return SDL_AUDIODEVICEADDED;}
        static Listener* create(SDL_Event* event);
};
#endif // BLACKBOX_AUDIO_DEVICE_ADDED_LISTENER_H
