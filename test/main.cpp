#include <stdio.h>
#include <stdlib.h>
#include "../Blackbox/gui/components/frames/frame.h"
#include "../Blackbox/gui/components/FrameManager.h"
#include "../Blackbox/gui/events/BaseEventFactory.h"
#include "debug/Debug.h"

int main( int argc , char ** argv )
{
    Frame f("The game", FRAME_CENTERED_X, FRAME_CENTERED_Y, 700, 300);
    f.setVisible(true);


    Frame f2("The game 2", FRAME_CENTERED_X, FRAME_CENTERED_Y, 700, 300);
    f2.setVisible(true);

    DebugEventFactory* events = new DebugEventFactory();
    f.setEventFactory(events);

    FrameManager::manager.run();
    return 0;
}
