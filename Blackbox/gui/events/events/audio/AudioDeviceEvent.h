#ifndef BLACKBOX_AUDIO_DEVICE_ADDED_EVENT_H
#define BLACKBOX_AUDIO_DEVICE_ADDED_EVENT_H
#include "../../../listeners/AudioDeviceListener.h"
#include "../Event.h"
#include <iostream>
#include <map>

class Component;

namespace internal_event
{
    class AudioDeviceAddedEvent : public InternalEvent
    {
        public:
            inline virtual void addDevice(Component* c, AudioDeviceListener* listener){}
            inline virtual void addDevice(FrameManager* c, AudioDeviceListener* listener){}
            inline const int getType() const { return SDL_AUDIODEVICEADDED;}
    };

    class AudioDeviceRemovedEvent : public InternalEvent
    {
        public:
            inline virtual void removeDevice(Component* c, AudioDeviceListener* listener){}
            inline virtual void removeDevice(FrameManager* c, AudioDeviceListener* listener){}
            inline const int getType() const { return SDL_AUDIODEVICEREMOVED;}
    };
}

class AudioDeviceAddedEvent : public Event
{
    protected:
        internal_event::AudioDeviceAddedEvent* event;
    public:
        AudioDeviceAddedEvent();
        AudioDeviceAddedEvent(internal_event::AudioDeviceAddedEvent* e);
        ~AudioDeviceAddedEvent();
        void operator()(Component* c, Listener* listener) const;
        void operator()(FrameManager* manager, Listener* listener) const;
        inline int getType() const {return SDL_AUDIODEVICEADDED;}
        void addEvent(internal_event::InternalEvent* e);
};

class AudioDeviceRemovedEvent : public Event
{
    protected:
        internal_event::AudioDeviceRemovedEvent* event;
    public:
        AudioDeviceRemovedEvent();
        AudioDeviceRemovedEvent(internal_event::AudioDeviceRemovedEvent* e);
        ~AudioDeviceRemovedEvent();
        void operator()(Component* c, Listener* listener) const;
        void operator()(FrameManager* manager, Listener* listener) const;
        inline int getType() const {return SDL_AUDIODEVICEREMOVED;}
        void addEvent(internal_event::InternalEvent* e);
};
#endif // BLACKBOX_MOUSE_BUTTON_EVENT_H
