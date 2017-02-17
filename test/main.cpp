#include <stdio.h>
#include <stdlib.h>
#include "../Blackbox/gui/components/frames/frame.h"
#include "../Blackbox/gui/components/FrameManager.h"
#include "../Blackbox/gui/events/BaseEventFactory.h"
#include "MouseButtonEventCustom.h"

int main( int argc , char ** argv )
{
    Frame f("The game", FRAME_CENTERED_X, FRAME_CENTERED_Y, 700, 300);
    f.setVisible(true);


    CustomEventFactory* events = new CustomEventFactory();
    f.setEventFactory(events);

    FrameManager::manager.run();
    return 0;
}
