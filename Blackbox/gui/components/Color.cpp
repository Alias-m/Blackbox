#include "Color.h"
Color Color::RED((const char)255, (const char)0, (const char)0);
Color Color::BLACK((const char)0,(const char) 0, (const char)0);
Color Color::GREEN((const char)0, (const char)255, (const char)0);
Color Color::WHITE((const char)255,(const char)255,(const char)255);
Color Color::BLUE((const char)0,(const char) 0, (const char)255);

Color::Color(const char red, const char green, const char blue, const char alpha): r(red), g(green), b(blue), a(alpha)
{
}
