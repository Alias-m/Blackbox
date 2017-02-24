#ifndef BLACKBOX_PANEL_H
#define BLACKBOX_PANEL_H
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include "components.h"
#include "Color.h"
#include "../events/factories/BaseEventFactory.h"

class Panel : public Component
{
    protected:
        Color background;
    public:
        Panel(const int x, const int y, const int w, const int h);
        virtual void close();
        inline const int getID() const {return 0;}
        inline virtual void notifyObserver(Observable* source) {}
        virtual void paintComponent(Graphics* g);
        void setBackgroundColor(Color c);
};
#endif // BLACKBOX_PANEL_H
