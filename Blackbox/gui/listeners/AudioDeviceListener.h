#ifndef BLACKBOX_AUDIO_DEVICE_LISTENER_H
#define BLACKBOX_AUDIO_DEVICE_LISTENER_H
#include "SDL2/SDL.h"
#include "Listener.h"

class AudioDeviceListener : public Listener
{
    protected:
        SDL_AudioDeviceEvent event;
    public:
        AudioDeviceListener(SDL_AudioDeviceEvent& e);
        inline int getTarget() const { return 0;}
        inline int getType() const { return event.type;}
        inline const int getDeviceID() const { return event.which;}
        //TODO : la SDL ne gère pas encore les appareils d'enregistrement, il faut attendre une version plus avancée
        inline bool isCapture() const { return event.iscapture;}
        static Listener* create(SDL_Event* event);
};
#endif // BLACKBOX_AUDIO_DEVICE_ADDED_LISTENER_H
