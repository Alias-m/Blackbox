#include "DefaultEvent.h"

void DefaultEvent::operator()(Component* c, Listener* listener) const
{
    std::cout << "Yoooou" << std::endl;
}

void DefaultEvent::operator()(FrameManager* c, Listener* listener) const
{
    std::cout << "Unknown" << std::endl;
}
