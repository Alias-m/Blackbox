#include "FrameManager.h"

FrameManager FrameManager::manager;
FrameManager::FrameManager()
{
    events = new BaseEventFactory();
    state = 1;
}

void FrameManager::addFrame(Frame* f)
{
    frames[f->getID()] = f;
}

void FrameManager::removeFrame(Frame* f)
{
    frames.erase(f->getID());
    if(!frames.size())
        state = 0;
}

void FrameManager::run()
{
    SDL_Event evt;
    int windowID;
    while(state)
    {
        SDL_WaitEvent(&evt);
        Listener* l = ListenerFactory::instance.getListener(&evt);
        windowID = l->getTarget();
        if(!windowID)
           (*events->getEvent(evt.type))(this, l);
        else
            frames[windowID]->execute(l);
        delete l;
    }
}

void FrameManager::close()
{
    while(frames.size())
    {
        frames.begin()->second->close();
        frames.erase(frames.begin());
    }
    state = 0;
}
