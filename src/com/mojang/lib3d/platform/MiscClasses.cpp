#include <src/com/mojang/lib3d/platform/MiscClasses.h>
#include <spdlog/spdlog.h>
    VideoMode::VideoMode(int n, int n2, int n3, int n4, int n5, int n6) {
        width = n;
        height = n2;
        redBits = n3;
        greenBits = n4;
        blueBits = n5;
        refreshRate = n6;
    }

    VideoMode::VideoMode(GLFWvidmode VidMode) {
        width = VidMode.width;
        height = VidMode.height;
        redBits = VidMode.redBits;
        greenBits = VidMode.greenBits;
        blueBits = VidMode.blueBits;
        refreshRate = VidMode.refreshRate;
    }

    bool VideoMode::equals(VideoMode videoMode) {
        return  width       == videoMode.width &&
                height      == videoMode.height &&
                redBits     == videoMode.redBits &&
                greenBits   == videoMode.greenBits &&
                blueBits    == videoMode.blueBits &&
                refreshRate == videoMode.refreshRate;
    }
    //Monitor

    Monitor::Monitor(GLFWmonitor* _monitor) {

        monitor = _monitor;
        refreshVideoModes();
    }

    void Monitor::refreshVideoModes() {
        VideoMode vidmode;
        //TODO: implement this
        //RenderSystem.assertInInitPhase();
        videoModes.clear();
        int count;
        if (monitor == NULL){
            spdlog::error("monitor is null when trying to refresh video modes");
            __glibcxx_assert(true);
        }
        const GLFWvidmode* buffer = glfwGetVideoModes(monitor,&count);
        for (int i = count - 1; i >= 0; --i) {
            vidmode = VideoMode(buffer[i]);
            if (((VideoMode)vidmode).redBits < 8 || ((VideoMode)vidmode).greenBits < 8 || ((VideoMode)vidmode).blueBits < 8) continue;
            videoModes.push_back(vidmode);
        }
        glfwGetMonitorPos(monitor, &x,&y);
        const GLFWvidmode* gLFWVidMode = glfwGetVideoMode(monitor);
        currentMode = VideoMode(*gLFWVidMode);
    }

    VideoMode Monitor::getPreferredVidMode(VideoMode videoMode) {
        //RenderSystem.assertInInitPhase();
        if (!videoMode.equals(VideoMode())) {
            for (VideoMode videoMode2 : videoModes) {
                if (!videoMode2.equals(videoMode)) continue;
                return videoMode2;
            }
        }
        return getCurrentMode();
    }

    int Monitor::getVideoModeIndex(VideoMode videoMode) {
        //RenderSystem.assertInInitPhase();
        for (int i;i < videoModes.size();i++) {
            std::list<VideoMode>::iterator it = videoModes.begin();
            std::advance(it, i);
            VideoMode videoMode2 = *it;
            if (videoMode2.equals(videoMode))
            return i;
        }
        
    }

    VideoMode Monitor::getCurrentMode() {
        return currentMode;
    }

    VideoMode Monitor::getMode(int i) {
        std::list<VideoMode>::iterator it = videoModes.begin();
        std::advance(it, i);
        VideoMode videoMode2 = *it;
    }

    int Monitor::getModeCount() {
        return videoModes.size();
    }

    GLFWmonitor* Monitor::getMonitor() {
        return monitor;
    }
    
    bool Monitor::equals(Monitor _monitor)
    {
        return monitor == _monitor.monitor;
    }