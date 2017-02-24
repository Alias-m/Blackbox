#include "Graphics.h"
#include "components.h"
#include "frames/frame.h"

Graphics::Graphics(Frame* f)
{
    renderer = f->renderer;
}

void Graphics::setRender(Component* c)
{
    component = c;
    SDL_SetRenderTarget(renderer, c ? c->texture: NULL);
    //SDL_RenderClear(renderer);
}
void Graphics::setColor(Color* c)
{
    SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, c->a);
}
void Graphics::fillBackground()
{
    Bounds b(0, 0, component->bounds.getWidth(), component->bounds.getHeight());
    fillRectangle(b);
}

void Graphics::fillRectangle(Bounds& b)
{
    SDL_Rect rect;
    rect.x = b.getX();
    rect.y = b.getY();
    rect.w = b.getWidth();
    rect.h = b.getHeight();
    SDL_RenderFillRect(renderer, &rect);
}
void Graphics::drawPoint(int x, int y)
{
    SDL_RenderDrawPoint(renderer, x , y);
}

void Graphics::drawImage(const char* path, int x, int y)
{
    SDL_Surface* img = IMG_Load(path);
    if(!img)
        throw ("Image not found");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, img);
    SDL_Rect rect = {x, y, img->w, img->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_FreeSurface(img);
    SDL_DestroyTexture(texture);
}

void Graphics::finalize(Component* c)
{
    SDL_SetRenderTarget(renderer, NULL);
    SDL_Rect rect;
    Bounds b = component->getShowableBounds();
    rect.x = b.getX();
    rect.y = b.getY();
    rect.w = b.getWidth();
    rect.h = b.getHeight();
    SDL_RenderCopy(renderer, component->texture,  NULL, &rect);
    //TODO : avec les scrollbar, le null sera utile
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
