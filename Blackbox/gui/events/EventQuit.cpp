#include "EventQuit.h"
#include "../components/components.h"
#include "../components/FrameManager.h"
void EventQuit::operator()(Component* c, Listener* listener) const
{
}

void EventQuit::operator()(FrameManager* manager, Listener* listener) const
{
    manager->close();
}
