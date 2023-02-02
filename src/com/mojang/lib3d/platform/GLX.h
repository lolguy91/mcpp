#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include <src/com/mojang/lib3d/platform/Window.h>
#include <iostream>

class GLX {
public:
    static std::string cpuInfo;

    static std::string getOpenGLVersionString();

    static int _getRefreshRate(Window window);

    static long _initGlfw();

    static bool _shouldClose(Window window);

    static void _init(int n, boolean bl);

    static std::string _getCpuInfo();

    //static void _renderCrosshair(int n, boolean bl, boolean bl2, boolean bl3);
}