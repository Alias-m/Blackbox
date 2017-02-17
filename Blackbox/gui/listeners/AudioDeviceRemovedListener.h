#ifndef BLACKBOX_AUDIO_DEVICE_REMOVED_LISTENER_H
#define BLACKBOX_AUDIO_DEVICE_REMOVED_LISTENER_H
#include "SDL2/SDL.h"
#include "Listener.h"

class AudioDeviceRemovedListener : public Listener
{
    protected:
        SDL_AudioDeviceEvent event;
    public:
        AudioDeviceRemovedListener(SDL_AudioDeviceEvent& e);
        inline int getTarget() const { return 0;}
        inline int getType() const { return SDL_AUDIODEVICEREMOVED;}
        static Listener* create(SDL_Event* event);
};
#endif // BLACKBOX_AUDIO_DEVICE_REMOVED_LISTENER_H
