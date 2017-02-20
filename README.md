# Blackbox
An object-oriented GUI framework in C++

##Utilization

Easy to use, the framework provides differents kinds of elements you can use to create your apps.
* **Frames** : frames are basic windows you can customize with components *(Note that it is not yet possible)*
* **Components** : components are elements a window can contains such as buttons or widgets. *(Note that no predefined component exist yet)*
* **Events** : Events are raised by the framework and linked to the window (or to the system if no window is specified). It is possible to rewrite every event of a component by the method `Component::addEvent(Event* e);`
* **Listeners** : A listener is raised whenever the framework catches an event. A listener is linked to the event which the same return value for the method `getType();`


##TODO-LIST

* **Frames**
  * Implements the event propagation system
  * Maybe it will lead to a different event handling system than components
* **Components**
  * Create some basic widgets
* **Listeners**
  * Implement all predefined listeners objects
  * Implement the secial custom listener
* **Events**
  * Implement all predefined events objects
  * Implement the special custom event
* **Design**
  * Create a class designed to define the look & feel of a component
  * These class have to be easy to override and customize
