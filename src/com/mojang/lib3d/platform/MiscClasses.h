#ifndef __MISCCLASSES_H__
#define __MISCCLASSES_H__
#include <GLFW/glfw3.h>
#include <list>

struct VideoMode {
    int width;
    int height;
    int redBits;
    int greenBits;
    int blueBits;
    int refreshRate;

    VideoMode() {}
    VideoMode(int n, int n2, int n3, int n4, int n5, int n6);
    VideoMode(GLFWvidmode VidMode);
    bool equals(VideoMode videoMode);
};

class Monitor {
    public:
    GLFWmonitor* monitor;
    std::list<VideoMode> videoModes;
    VideoMode currentMode;
    int x;
    int y;

    Monitor(){}
    Monitor(GLFWmonitor* monitor);
    void refreshVideoModes();
    VideoMode getPreferredVidMode(VideoMode videoMode = VideoMode());
    int getVideoModeIndex(VideoMode videoMode);
    VideoMode getCurrentMode();
    VideoMode getMode(int i);
    int getModeCount();
    GLFWmonitor* getMonitor();
    bool equals(Monitor monitor);

};
#endif // __MISCCLASSES_H__