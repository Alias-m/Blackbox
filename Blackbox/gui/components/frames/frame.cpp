#include "frame.h"
#include "../FrameManager.h"

Frame::Frame(std::string n, const int x, const int y, const int w, const int h) throw(): Component(x, y, w, h), name(n)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw(FRAME_INIT_FAIL);

    frame = SDL_CreateWindow(name.c_str(), bounds.x, bounds.y, bounds.width, bounds.height, 0);
    if (frame == NULL)
        throw (FRAME_CREATE_FAIL);
    events = new BaseEventFactory();
    FrameManager::manager.addFrame(this);
}

void Frame::setVisible(bool b) throw()
{
    if(b)
    {
        renderer = SDL_CreateRenderer(frame, -1, 0);
        if (renderer == NULL)
            throw (FRAME_SHOW_FAIL);
    }
}

void Frame::notifyObserver(Observable* o)
{

}

const int Frame::getID() const
{
    return SDL_GetWindowID(frame);
}

void Frame::close()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(frame);
    FrameManager::manager.removeFrame(this);
}

void Frame::execute(Listener* l)
{
    (*events->getEvent(l->getType()))(this, l);
}
