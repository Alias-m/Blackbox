#include "AudioDeviceEvent.h"
#include "../../../components/components.h"


AudioDeviceAddedEvent::AudioDeviceAddedEvent()
{
    event = new internal_event::AudioDeviceAddedEvent();
}
AudioDeviceAddedEvent::AudioDeviceAddedEvent(internal_event::AudioDeviceAddedEvent* e)
{
    event = e;
}
AudioDeviceAddedEvent::~AudioDeviceAddedEvent()
{
    delete event;
}

AudioDeviceRemovedEvent::AudioDeviceRemovedEvent()
{
    event = new internal_event::AudioDeviceRemovedEvent();
}
AudioDeviceRemovedEvent::AudioDeviceRemovedEvent(internal_event::AudioDeviceRemovedEvent* e)
{
    event = e;
}
AudioDeviceRemovedEvent::~AudioDeviceRemovedEvent()
{
    delete event;
}

void AudioDeviceAddedEvent::operator()(Component* c, Listener* listener) const
{
    AudioDeviceListener* l = dynamic_cast<AudioDeviceListener*>(listener);
    event->addDevice(c, l);
}

void AudioDeviceAddedEvent::operator()(FrameManager* manager, Listener* listener) const
{
    AudioDeviceListener* l = dynamic_cast<AudioDeviceListener*>(listener);
    event->addDevice(manager, l);
}

void AudioDeviceRemovedEvent::operator()(Component* c, Listener* listener) const
{
    AudioDeviceListener* l = dynamic_cast<AudioDeviceListener*>(listener);
    event->removeDevice(c, l);
}

void AudioDeviceRemovedEvent::operator()(FrameManager* manager, Listener* listener) const
{
    AudioDeviceListener* l = dynamic_cast<AudioDeviceListener*>(listener);
    event->removeDevice(manager, l);
}

void AudioDeviceAddedEvent::addEvent(internal_event::InternalEvent* e)
{
    internal_event::AudioDeviceAddedEvent* tmp = dynamic_cast<internal_event::AudioDeviceAddedEvent*>(e);
    delete event;
    event = tmp;
}
void AudioDeviceRemovedEvent::addEvent(internal_event::InternalEvent* e)
{
    internal_event::AudioDeviceRemovedEvent* tmp = dynamic_cast<internal_event::AudioDeviceRemovedEvent*>(e);
    delete event;
    event = tmp;
}
