#ifndef BLACKBOX_OBSERVABLE_H
#define BLACKBOX_OBSERVABLE_H
#include <vector>

class Observer;
class Observable;


class Observer
{
    protected:
    private:
    public:
        virtual void notifyObserver(Observable* source) = 0;
};

class Observable
{
    protected:
    private:
        std::vector<Observer*> observers;
    public:
        void addObserver(Observer* o);
        void notifyObservers();
};
#endif // BLACKBOX_OBSERVABLE_H
