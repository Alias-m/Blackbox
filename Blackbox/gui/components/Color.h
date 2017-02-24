#ifndef BLACKBOX_COLOR_H
#define BLACKBOX_COLOR_H
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
class Color;
class Graphics;

class Color
{
    friend class Graphics;
    protected:
        char r;
        char g;
        char b;
        char a;
    public:
        static Color RED;
        static Color BLACK;
        static Color GREEN;
        static Color WHITE;
        static Color BLUE;
        Color(const char r, const char g, const char b, const char a = (const char)255);
        inline Color() {}
};
#endif // BLACKBOX_COLOR_H
