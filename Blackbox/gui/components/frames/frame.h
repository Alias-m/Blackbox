#ifndef BLACKBOX_FRAME_H
#define BLACKBOX_FRAME_H
#define FRAME_CREATE_FAIL "Window creation failed\n"
#define FRAME_SHOW_FAIL "Frame display failed\n"
#define FRAME_CENTERED_X SDL_WINDOWPOS_CENTERED
#define FRAME_CENTERED_Y SDL_WINDOWPOS_CENTERED
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "../components.h"
#include "../layouts/GridLayout.h"
#include "../layouts/Layout.h"
#include "../../events/factories/BaseEventFactory.h"
class FrameManager;
class Frame : public Component
{
    friend class Graphics;
    protected:
        SDL_Window *frame;
        SDL_Renderer *renderer;
        std::string name;
        int datasMask;
    public:
        Frame(std::string n, const int x = FRAME_CENTERED_X, const int y = FRAME_CENTERED_Y, const int w = 0, const int h = 0) throw();
        void setVisible(bool b) throw();
        void notifyObserver(Observable* o);
        //virtual void addComponent(Component* c);
        void close();
        const int getID() const;
        void execute(Listener* l);
        void setResizable(bool b);
        void setTitleBorder(bool b);
        void setFullScreen(bool b);
        void setName(const char* n);
        void setIcon();
        void paintComponent(Graphics* g);
        void link(Component* c);
        void addComponent(Component* c);
        void updateUI();
        //TODO : ajouter toutes les options https://wiki.libsdl.org/SDL_WindowFlags
        /*
        void SDL_SetWindowPosition(SDL_Window* window , int x, int y);  //déplace la fenêtre à la position (x;y) dans le repère présenté précédemment
        void SDL_SetWindowSize(SDL_Window* window , int w , int h);  //redimensionne la fenêtre qui sera ensuite large de w pixels et haute de h pixels
        void SDL_MaximizeWindow(SDL_Window* window);//agrandissement de la fenêtre
        void SDL_MinimizeWindow(SDL_Window* window);//réduction de la fenêtre
        void SDL_RestoreWindow(SDL_Window* window);//restauration de la fenêtre
        int SDL_SetWindowFullscreen(SDL_Window* window , SDL_bool fullscreen); // La fonction renvoie 0 en cas de succès et une valeur négative en cas d'erreur.
        int SDL_SetWindowBrightness(SDL_Window* window, float luminosite);//définir la luminosité de l'écran
        float SDL_GetWindowBrightness(SDL_Window* window);//récupérer la luminosité
        void SDL_RenderPresent(SDL_Renderer* renderer);
        SDL_Renderer* SDL_GetRenderer(SDL_Window* window);
        int SDL_GetRendererInfo(SDL_Renderer* renderer ,SDL_RendererInfo* info);
        int SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r,  Uint8 g , Uint8 b , Uint8  a);
        */
};
#endif // BLACKBOX_FRAME_H
