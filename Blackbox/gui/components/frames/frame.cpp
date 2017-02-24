#include "frame.h"
#include "../FrameManager.h"

Frame::Frame(std::string n, const int x, const int y, const int w, const int h) throw(): Component(x, y, w, h), name(n), datasMask(0)
{
    //TODO : mieux gérer le système du masque
    frame = SDL_CreateWindow(name.c_str(), bounds.getX(), bounds.getY(), bounds.getWidth(), bounds.getHeight(), datasMask);
    if (frame == NULL)
        throw (FRAME_CREATE_FAIL);
    FrameManager::manager.addFrame(this);
    renderer = SDL_CreateRenderer(frame, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
        throw (FRAME_SHOW_FAIL);
    events = new BaseEventFactory();
    layout = NULL;//new GridLayout(this, 2, 2);
}

void Frame::setResizable(bool b)
{
    datasMask |= SDL_WINDOW_RESIZABLE;
    if(!b)
        datasMask &= ~SDL_WINDOW_RESIZABLE;
}
void Frame::setTitleBorder(bool b)
{
    datasMask |= SDL_WINDOW_BORDERLESS;
    if(!b)
        datasMask &= ~SDL_WINDOW_BORDERLESS;
}
void Frame::setFullScreen(bool b)
{
    datasMask |= SDL_WINDOW_FULLSCREEN;
    if(!b)
        datasMask &= ~SDL_WINDOW_FULLSCREEN;
}

void Frame::setName(const char* n)
{
    name = n;
    SDL_SetWindowTitle(frame , name.c_str());
}
void Frame::setIcon()
{
    //void SDL_SetWindowIcon(SDL_Window*  window , SDL_Surface* icon); //ajoute une icône à la fenêtre
}
void Frame::setVisible(bool b) throw()
{
    if(b)
        SDL_ShowWindow(frame);
    else
        SDL_HideWindow(frame);
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
    updateUI();
}

void Frame::updateUI()
{
    Graphics* g = NULL;
    paintComponent(g);
}
void Frame::paintComponent(Graphics* g)
{
    SDL_RenderClear(renderer);
    g = new Graphics(this);
    for(std::vector<Component*>::iterator it = components.begin(); it != components.end(); it++)
        (*it)->paint(g);
    g->setColor(&Color::BLACK);
    SDL_RenderPresent(renderer);
    delete g;
}

void Frame::link(Component* c)
{
    c->texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,c->bounds.getWidth(),c->bounds.getHeight());
}

void Frame::addComponent(Component* c)
{
    components.push_back(c);
    c->container = this;
    c->parent = NULL;
    link(c);
    if(layout != NULL)
    {
        layout->addComponent(c);
        c->bounds.setEditable(false);
    }
}
