#include "Observable.h"

void Observable::addObserver(Observer* o)
{
    observers.push_back(o);
}

void Observable::notifyObservers()
{
    for(std::vector<Observer*>::iterator i = observers.begin(); i != observers.end(); i++)
        (*i)->notifyObserver(this);
}
