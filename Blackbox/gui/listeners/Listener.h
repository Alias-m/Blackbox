#ifndef BLACKBOX_LISTENER_H
#define BLACKBOX_LISTENER_H
#include <map>
#include <iostream>
class Listener
{
    public:
        virtual int getTarget() const {return 0;};
        virtual int getType() const {return 0;};
};
#endif // BLACKBOX_LISTENER_H
