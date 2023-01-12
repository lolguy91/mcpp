#include <GLFW/glfw3.h>
#include <src/com/mojang/lib3d/platform/MiscClasses.h>
#include <spdlog/spdlog.h>
#include <stb/stb_image.h>
class Window{
    public:
    //GLFWErrorCallback defaultErrorCallback = GLFWErrorCallback.create((arg_0, arg_1) -> defaultErrorCallback(arg_0, arg_1));
    //WindowEventHandler eventHandler;
    //ScreenManager screenManager;
    GLFWwindow* window;
    int windowedX;
    int windowedY;
    int windowedWidth;
    int windowedHeight;
    VideoMode preferredFullscreenVideoMode;
    bool fullscreen;
    bool actuallyFullscreen;
    int posx;
    int posy;
    int width;
    int height;
    int framebufferWidth;
    int framebufferHeight;
    int guiScaledWidth;
    int guiScaledHeight;
    double guiScale;
    char* errorSection = "";
    bool dirty;
    int framerateLimit;
    bool vsync;

    Window(
        //WindowEventHandler windowEventHandler,
        //ScreenManager screenManager,
        //DisplayData displayData,
        VideoMode fullscrvidmode, char* title) {
        //RenderSystem.assertInInitPhase();
        //screenManager = screenManager;
        //setBootErrorCallback();
        //setErrorSection("Pre startup");
        //eventHandler = windowEventHandler;
        preferredFullscreenVideoMode = fullscrvidmode;
        //actuallyFullscreen = fullscreen = displayData.isFullscreen;
        Monitor monitor = /*screenManager.getMonitor(*/Monitor(glfwGetPrimaryMonitor());
        width = 800;//displayData.width > 0 ? displayData.width : 1;
        //windowedWidth = width;
        height = 600;//displayData.height > 0 ? displayData.height : 1;
        //windowedHeight = height;
        glfwDefaultWindowHints();
        glfwWindowHint((int)139265, (int)196609);
        glfwWindowHint((int)139275, (int)221185);
        glfwWindowHint((int)139266, (int)3);
        glfwWindowHint((int)139267, (int)2);
        glfwWindowHint((int)139272, (int)204801);
        glfwWindowHint((int)139270, (int)1);
        window = glfwCreateWindow((int)width, (int)height, (const char*)title, (fullscreen && monitor.equals(Monitor()) ? monitor.monitor : NULL), NULL);
        if (monitor.equals(Monitor())) {
            VideoMode videoMode = monitor.getPreferredVidMode(fullscreen ? preferredFullscreenVideoMode : VideoMode());
            windowedX = posx = monitor.x + videoMode.width / 2 - width / 2;
            windowedY = posy = monitor.y + videoMode.height / 2 - height / 2;
        } else {
            int x,y;
            glfwGetWindowPos(window, &x, &y);
            windowedX = posx = x;
            windowedY = posy = y;
        }
        glfwMakeContextCurrent(window);
        //GL.createCapabilities();
        setMode();
        refreshFramebufferSize();
        glfwSetFramebufferSizeCallback(window, (GLFWframebuffersizefun)&onFramebufferResize);
        glfwSetWindowPosCallback(window, (GLFWwindowposfun)&onMove);
        glfwSetWindowSizeCallback(window, (GLFWwindowsizefun)&onResize);
        glfwSetWindowFocusCallback(window, (GLFWwindowfocusfun)&onFocus);
        glfwSetCursorEnterCallback(window, (GLFWcursorenterfun)&onEnter);
    }

    bool shouldClose() {
        return glfwWindowShouldClose(window);
    }
    //void checkGlfwError(BiConsumer<Integer, String> biConsumer) {
    //    RenderSystem.assertInInitPhase();
    //    try (MemoryStack memoryStack = MemoryStack.stackPush();){
    //        PointerBuffer pointerBuffer = memoryStack.mallocPointer(1);
    //        int n = glfwGetError((PointerBuffer)pointerBuffer);
    //        if (n != 0) {
    //            long l = pointerBuffer.get();
    //            String string = l == 0L ? "" : MemoryUtil.memUTF8((long)l);
    //            biConsumer.accept(n, string);
    //        }
    //    }
    //}
//
    void setIcon(char* fileloc, char* fileloc2) {
        
        //RenderSystem.assertInInitPhase();
	    int m_Width, m_Height;
	    unsigned char* m_LocalBuffer;
        stbi_set_flip_vertically_on_load(1);
		m_LocalBuffer = stbi_load(fileloc, &m_Width, &m_Height, nullptr, 4);

		if (!m_LocalBuffer)
		{
			spdlog::error("could not set icon 1 to : '{}'",fileloc);
            return;
		}

        int m_Width2, m_Height2;
	    unsigned char* m_LocalBuffer2;
        stbi_set_flip_vertically_on_load(1);
		m_LocalBuffer2 = stbi_load(fileloc, &m_Width2, &m_Height2, nullptr, 4);

		if (!m_LocalBuffer2)
		{
			spdlog::error("could not set icon 2 to : '{}'",fileloc2);
            return;
		}

        GLFWimage images[2];

        images[0].pixels = m_LocalBuffer;
        images[0].height = m_Height;
        images[0].width  = m_Width;

        images[1].pixels = m_LocalBuffer2;
        images[1].height = m_Height2;
        images[1].width  = m_Width2;

        glfwSetWindowIcon(window,2,images);
    }
//
    ///*
    // * WARNING - Removed try catching itself - possible behaviour change.
    // */
    //
    //ByteBuffer readIconPixels(InputStream inputStream, IntBuffer intBuffer, IntBuffer intBuffer2, IntBuffer intBuffer3) throws IOException {
    //    RenderSystem.assertInInitPhase();
    //    ByteBuffer byteBuffer = null;
    //    try {
    //        byteBuffer = TextureUtil.readResource(inputStream);
    //        byteBuffer.rewind();
    //        ByteBuffer byteBuffer2 = STBImage.stbi_load_from_memory((ByteBuffer)byteBuffer, (IntBuffer)intBuffer, (IntBuffer)intBuffer2, (IntBuffer)intBuffer3, (int)0);
    //        return byteBuffer2;
    //    }
    //    finally {
    //        if (byteBuffer != null) {
    //            MemoryUtil.memFree((Buffer)byteBuffer);
    //        }
    //    }
    //}
//


    //void setBootErrorCallback() {
    //    RenderSystem.assertInInitPhase();
    //    glfwSetErrorCallback(Window::bootCrash);
    //}
//
    //static void bootCrash(int n, long l) {
    //    RenderSystem.assertInInitPhase();
    //    String string = "GLFW error " + n + ": " + MemoryUtil.memUTF8((long)l);
    //    TinyFileDialogs.tinyfd_messageBox((CharSequence)"Minecraft", (CharSequence)(string + ".\n\nPlease make sure you have up-to-date drivers (see aka.ms/mcdriver for instructions)."), (CharSequence)"ok", (CharSequence)"error", (bool)false);
    //    throw new WindowInitFailed(string);
    //}
//
    void defaultErrorCallback(int n, long l) {
        //TODO: implement this
        //RenderSystem.assertOnRenderThread();
        spdlog::error("########## GL ERROR ##########");
        spdlog::error("@ {}", errorSection);
        spdlog::error("{0:d}: {0:d}", n, l);
    }

    void setDefaultErrorCallback() {
    glfwSetErrorCallback((GLFWerrorfun)&defaultErrorCallback);
    }

    void updateVsync(bool bl) {
    //TODO:implement this
    //RenderSystem.assertOnRenderThreadOrInit();
        vsync = bl;
        glfwSwapInterval((int)(bl ? 1 : 0));
    }

    void close() {
        //TODO:implement this
        //RenderSystem.assertOnRenderThread();
        //Callbacks.glfwFreeCallbacks((long)window);
        //defaultErrorCallback.close();
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    GLFWwindowposfun onMove(long l, int n, int n2) {
        posx = n;
        posy = n2;
    }

    void onFramebufferResize(GLFWwindow* _window, int n, int n2) {
        if (_window != window) {
            return;
        }
        int n3 = width;
        int n4 = height;
        if (n == 0 || n2 == 0) {
            return;
        }
        framebufferWidth = n;
        framebufferHeight = n2;
        if (width != n3 || height != n4) {
        //TODO: implement this
        //    eventHandler.resizeDisplay();
        }
    }

    void refreshFramebufferSize() {
        //TODO:implement this
        //RenderSystem.assertInInitPhase();
        int x,y;
        glfwGetFramebufferSize(window, &x, &y);
        framebufferWidth = x > 0 ? x : 1;
        framebufferHeight = y > 0 ? y : 1;
    }

    void onResize(GLFWwindow* l, int n, int n2) {
        width = n;
        height = n2;
    }

    void onFocus(GLFWwindow* l, bool bl) {
        if (l == window) {
            //TODO: implement this
            //eventHandler.setWindowActive(bl);
        }
    }
//
    void onEnter(GLFWwindow* l, bool bl) {
        if (bl) {
            //TODO: implement this
            //eventHandler.cursorEntered();
        }
    }

    //void updateDisplay() {
    //    RenderSystem.flipFrame(window);
    //    if (fullscreen != actuallyFullscreen) {
    //        actuallyFullscreen = fullscreen;
    //        updateFullscreen(vsync);
    //    }
    //}


    void setPreferredFullscreenVideoMode(VideoMode vm) {
        bool bl = !vm.equals(preferredFullscreenVideoMode);
        preferredFullscreenVideoMode = vm;
        if (bl) {
            dirty = true;
        }
    }

    void changeFullscreenVideoMode() {
        if (fullscreen && dirty) {
            dirty = false;
            setMode();
            //TODO:implement this
            //eventHandler.resizeDisplay();
        }
    }

    void setMode() {
        bool bl;
        //TODO:implement this
        //RenderSystem.assertInInitPhase();
        bool bl2 = bl = glfwGetWindowMonitor(window) != 0L;
        if (fullscreen) {
            //TODO: implement this
            //GLFWmonitor* _monitor = screenManager.findBestGLFWMonitor(this);
            //if (_monitor == nullptr) {
            //    spdlog::warn("Failed to find suitable monitor for fullscreen mode");
            //    fullscreen = false;
            //} else {
            //    //TODO:mac compatibility
            //    //if (Minecraft.ON_OSX) {
            //    //    MacosUtil.toggleFullscreen(window);
            //    //}
            //    VideoMode videoMode = monitor.getPreferredVidMode(preferredFullscreenVideoMode);
            //    if (!bl) {
            //        windowedX = posx;
            //        windowedY = posy;
            //        windowedWidth = width;
            //        windowedHeight = height;
            //    }
            //    posx = 0;
            //    posy = 0;
            //    width = videoMode.width;
            //    height = videoMode.height;
            //    glfwSetWindowMonitor(window, monitor.getGLFWMonitor(), (int)posx, (int)posy, (int)width, (int)height, (int)videoMode.refreshRate);
           // }
        } else {
            posx = windowedX;
            posy = windowedY;
            width = windowedWidth;
            height = windowedHeight;
            glfwSetWindowMonitor(window, NULL, (int)posx, (int)posy, (int)width, (int)height, (int)-1);
        }
    }

    void toggleFullScreen() {
        fullscreen = !fullscreen;
    }

    void setWindowed(int _windowedWidth, int _windowedHeight) {
        windowedWidth = _windowedWidth;
        windowedHeight = _windowedHeight;
        fullscreen = false;
        setMode();
    }
    //void updateFullscreen(bool bl) {
    //    RenderSystem.assertOnRenderThread();
    //    try {
    //        setMode();
    //        eventHandler.resizeDisplay();
    //        updateVsync(bl);
    //        updateDisplay();
    //    }
    //    catch (Exception exception) {
    //        spdlog::error("Couldn't toggle fullscreen");
    //    }
    //}
//
    //int calculateScale(int n, bool bl) {
    //    int n2;
    //    for (n2 = 1; n2 != n && n2 < framebufferWidth && n2 < framebufferHeight && framebufferWidth / (n2 + 1) >= 320 && framebufferHeight / (n2 + 1) >= 240; ++n2) {
    //    }
    //    if (bl && n2 % 2 != 0) {
    //        ++n2;
    //    }
    //    return n2;
    //}
//
    //void setGuiScale(double d) {
    //    guiScale = d;
    //    int n = (int)((double)framebufferWidth / d);
    //    guiScaledWidth = (double)framebufferWidth / d > (double)n ? n + 1 : n;
    //    int n2 = (int)((double)framebufferHeight / d);
    //    guiScaledHeight = (double)framebufferHeight / d > (double)n2 ? n2 + 1 : n2;
    //}
//
    //void setTitle(String string) {
    //    glfwSetWindowTitle((long)window, (CharSequence)string);
    //}
//
    //GLFWMonitor findBestGLFWMonitor() {
    //    return screenManager.findBestGLFWMonitor(this);
    //}
//
    //void updateRawMouseInput(bool bl) {
    //    InputConstants.updateRawMouseInput(window, bl);
    //}

};