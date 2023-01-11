#include <GLFW/glfw3.h>

//now, go though every function and try to fix the errors in them if you need help, ping me in session chat ok?
//are you here?
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
    //VideoMode preferredFullscreenVideoMode;
    bool fullscreen;
    bool actuallyFullscreen;
    int x;
    int y;
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
        char* string, char* string2) {
        //RenderSystem.assertInInitPhase();
        //screenManager = screenManager;
        //setBootErrorCallback();
        //setErrorSection("Pre startup");
        //eventHandler = windowEventHandler;
        //Optional<VideoMode> optional = VideoMode.read(string);
        //preferredFullscreenVideoMode = optional.isPresent() ? optional : (displayData.fullscreenWidth.isPresent() && displayData.fullscreenHeight.isPresent() ? Optional.of(new VideoMode(displayData.fullscreenWidth.getAsInt(), displayData.fullscreenHeight.getAsInt(), 8, 8, 8, 60)) : Optional.empty());
        //actuallyFullscreen = fullscreen = displayData.isFullscreen;
        GLFWmonitor* monitor = /*screenManager.getMonitor(*/glfwGetPrimaryMonitor();
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
        window = glfwCreateWindow((int)width, (int)height, (const char*)string2, (fullscreen && !monitor ? monitor/*.getGLFWMonitor()*/ : NULL), NULL);
        //if (monitor != null) {
        //    VideoMode videoMode = monitor.getPreferredVidMode(fullscreen ? preferredFullscreenVideoMode : Optional.empty());
        //    windowedX = x = monitor.getX() + videoMode.getWidth() / 2 - width / 2;
        //    windowedY = y = monitor.getY() + videoMode.getHeight() / 2 - height / 2;
        //} else {
        //    int[] arrn = new int[1];
        //    int[] arrn2 = new int[1];
        //    glfwGetWindowPos((long)window, (int[])arrn, (int[])arrn2);
        //    windowedX = x = arrn[0];
        //    windowedY = y = arrn2[0];
        //}
        glfwMakeContextCurrent(window);
        //GL.createCapabilities();
        //setMode();
        //refreshFramebufferSize();
        //glfwSetFramebufferSizeCallback(window, &onFramebufferResize);
        //glfwSetWindowPosCallback(window, &onMove);
        //glfwSetWindowSizeCallback(window, &onResize);
        //glfwSetWindowFocusCallback(window, &onFocus);
        //glfwSetCursorEnterCallback(window, &onEnter);
    }

    //int getRefreshRate() {
    //    RenderSystem.assertOnRenderThread();
    //    return _getRefreshRate(this);
    //}
//
    //bool shouldClose() {
    //    return GLX._shouldClose(this);
    //}
//
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
    //void setIcon(InputStream inputStream, InputStream inputStream2) {
    //    RenderSystem.assertInInitPhase();
    //    try (MemoryStack memoryStack = MemoryStack.stackPush();){
    //        if (inputStream == null) {
    //            throw new FileNotFoundException("icons/icon_16x16.png");
    //        }
    //        if (inputStream2 == null) {
    //            throw new FileNotFoundException("icons/icon_32x32.png");
    //        }
    //        IntBuffer intBuffer = memoryStack.mallocInt(1);
    //        IntBuffer intBuffer2 = memoryStack.mallocInt(1);
    //        IntBuffer intBuffer3 = memoryStack.mallocInt(1);
    //        GLFWImage.Buffer buffer = GLFWImage.mallocStack((int)2, (MemoryStack)memoryStack);
    //        ByteBuffer byteBuffer = readIconPixels(inputStream, intBuffer, intBuffer2, intBuffer3);
    //        if (byteBuffer == null) {
    //            throw new IllegalStateException("Could not load icon: " + STBImage.stbi_failure_reason());
    //        }
    //        buffer.position(0);
    //        buffer.width(intBuffer.get(0));
    //        buffer.height(intBuffer2.get(0));
    //        buffer.pixels(byteBuffer);
    //        ByteBuffer byteBuffer2 = readIconPixels(inputStream2, intBuffer, intBuffer2, intBuffer3);
    //        if (byteBuffer2 == null) {
    //            throw new IllegalStateException("Could not load icon: " + STBImage.stbi_failure_reason());
    //        }
    //        buffer.position(1);
    //        buffer.width(intBuffer.get(0));
    //        buffer.height(intBuffer2.get(0));
    //        buffer.pixels(byteBuffer2);
    //        buffer.position(0);
    //        glfwSetWindowIcon((long)window, (GLFWImage.Buffer)buffer);
    //        STBImage.stbi_image_free((ByteBuffer)byteBuffer);
    //        STBImage.stbi_image_free((ByteBuffer)byteBuffer2);
    //    }
    //    catch (IOException iOException) {
    //        LOGGER.error("Couldn't set icon", (Throwable)iOException);
    //    }
    //}
//
    ///*
    // * WARNING - Removed try catching itself - possible behaviour change.
    // */
    //@Nullable
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
    //void setErrorSection(String string) {
    //    errorSection = string;
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
    //void defaultErrorCallback(int n, long l) {
    //    RenderSystem.assertOnRenderThread();
    //    String string = MemoryUtil.memUTF8((long)l);
    //    LOGGER.error("########## GL ERROR ##########");
    //    LOGGER.error("@ {}", (Object)errorSection);
    //    LOGGER.error("{}: {}", (Object)n, (Object)string);
    //}
//
    //void setDefaultErrorCallback() {
    //    GLFWErrorCallback gLFWErrorCallback = glfwSetErrorCallback((GLFWErrorCallbackI)defaultErrorCallback);
    //    if (gLFWErrorCallback != null) {
    //        gLFWErrorCallback.free();
    //    }
    //}
//
    //void updateVsync(bool bl) {
    //    RenderSystem.assertOnRenderThreadOrInit();
    //    vsync = bl;
    //    glfwSwapInterval((int)(bl ? 1 : 0));
    //}
//
    //@Override
    //void close() {
    //    RenderSystem.assertOnRenderThread();
    //    Callbacks.glfwFreeCallbacks((long)window);
    //    defaultErrorCallback.close();
    //    glfwDestroyWindow((long)window);
    //    glfwTerminate();
    //}
//
    //void onMove(long l, int n, int n2) {
    //    x = n;
    //    y = n2;
    //}
//
    //void onFramebufferResize(long l, int n, int n2) {
    //    if (l != window) {
    //        return;
    //    }
    //    int n3 = getWidth();
    //    int n4 = getHeight();
    //    if (n == 0 || n2 == 0) {
    //        return;
    //    }
    //    framebufferWidth = n;
    //    framebufferHeight = n2;
    //    if (getWidth() != n3 || getHeight() != n4) {
    //        eventHandler.resizeDisplay();
    //    }
    //}
//
    //void refreshFramebufferSize() {
    //    RenderSystem.assertInInitPhase();
    //    int[] arrn = new int[1];
    //    int[] arrn2 = new int[1];
    //    glfwGetFramebufferSize((long)window, (int[])arrn, (int[])arrn2);
    //    framebufferWidth = arrn[0] > 0 ? arrn[0] : 1;
    //    framebufferHeight = arrn2[0] > 0 ? arrn2[0] : 1;
    //}
//
    //void onResize(long l, int n, int n2) {
    //    width = n;
    //    height = n2;
    //}
//
    //void onFocus(long l, bool bl) {
    //    if (l == window) {
    //        eventHandler.setWindowActive(bl);
    //    }
    //}
//
    //void onEnter(long l, bool bl) {
    //    if (bl) {
    //        eventHandler.cursorEntered();
    //    }
    //}
//
    //void setFramerateLimit(int n) {
    //    framerateLimit = n;
    //}
//
    //int getFramerateLimit() {
    //    return framerateLimit;
    //}
//
    //void updateDisplay() {
    //    RenderSystem.flipFrame(window);
    //    if (fullscreen != actuallyFullscreen) {
    //        actuallyFullscreen = fullscreen;
    //        updateFullscreen(vsync);
    //    }
    //}
//
    //Optional<VideoMode> getPreferredFullscreenVideoMode() {
    //    return preferredFullscreenVideoMode;
    //}
//
    //void setPreferredFullscreenVideoMode(Optional<VideoMode> optional) {
    //    bool bl = !optional.equals(preferredFullscreenVideoMode);
    //    preferredFullscreenVideoMode = optional;
    //    if (bl) {
    //        dirty = true;
    //    }
    //}
//
    //void changeFullscreenVideoMode() {
    //    if (fullscreen && dirty) {
    //        dirty = false;
    //        setMode();
    //        eventHandler.resizeDisplay();
    //    }
    //}
//
    //void setMode() {
    //    bool bl;
    //    RenderSystem.assertInInitPhase();
    //    bool bl2 = bl = glfwGetWindowGLFWMonitor((long)window) != 0L;
    //    if (fullscreen) {
    //        GLFWMonitor monitor = screenManager.findBestGLFWMonitor(this);
    //        if (monitor == null) {
    //            LOGGER.warn("Failed to find suitable monitor for fullscreen mode");
    //            fullscreen = false;
    //        } else {
    //            if (Minecraft.ON_OSX) {
    //                MacosUtil.toggleFullscreen(window);
    //            }
    //            VideoMode videoMode = monitor.getPreferredVidMode(preferredFullscreenVideoMode);
    //            if (!bl) {
    //                windowedX = x;
    //                windowedY = y;
    //                windowedWidth = width;
    //                windowedHeight = height;
    //            }
    //            x = 0;
    //            y = 0;
    //            width = videoMode.getWidth();
    //            height = videoMode.getHeight();
    //            glfwSetWindowGLFWMonitor((long)window, (long)monitor.getGLFWMonitor(), (int)x, (int)y, (int)width, (int)height, (int)videoMode.getRefreshRate());
    //        }
    //    } else {
    //        x = windowedX;
    //        y = windowedY;
    //        width = windowedWidth;
    //        height = windowedHeight;
    //        glfwSetWindowGLFWMonitor((long)window, (long)0L, (int)x, (int)y, (int)width, (int)height, (int)-1);
    //    }
    //}
//
    //void toggleFullScreen() {
    //    fullscreen = !fullscreen;
    //}
//
    //void setWindowed(int n, int n2) {
    //    windowedWidth = n;
    //    windowedHeight = n2;
    //    fullscreen = false;
    //    setMode();
    //}
//
    //void updateFullscreen(bool bl) {
    //    RenderSystem.assertOnRenderThread();
    //    try {
    //        setMode();
    //        eventHandler.resizeDisplay();
    //        updateVsync(bl);
    //        updateDisplay();
    //    }
    //    catch (Exception exception) {
    //        LOGGER.error("Couldn't toggle fullscreen", (Throwable)exception);
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