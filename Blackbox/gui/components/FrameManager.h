#ifndef FRAME_MANAGER_H
#define FRAME_MANAGER_H
#include <map>
#include "frames/frame.h"

class FrameManager final
{
    private:
        std::map<int, Frame*> frames;
        FrameManager();
        EventFactory* events;
        int state;
    public:
        static FrameManager manager;
        void addFrame(Frame* f);
        void removeFrame(Frame* f);
        void run();
        void close();
};
#endif // FRAME_MANAGER_H
