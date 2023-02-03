    
#include <cpuid.h>
#include <stdio.h>
#include <src/com/mojang/lib3d/platform/GLX.h>
#include <thread>
#include <string>
    std::string GLX::getOpenGLVersionString() {
        //RenderSystem.assertOnRenderThread();
        if (glfwGetCurrentContext() == nullptr) {
            return "NO CONTEXT";
        }
        //return GlStateManager._getString(7937) + " GL version " + GlStateManager._getString(7938) + ", " + GlStateManager._getString(7936);
    }

    int GLX::_getRefreshRate(Window window) {
        //RenderSystem.assertOnRenderThread();
        GLFWmonitor* monitor = glfwGetWindowMonitor(window.window);
        if (monitor == nullptr) {
            monitor = glfwGetPrimaryMonitor();
        }
        const GLFWvidmode* VidMode = monitor == nullptr ? nullptr : glfwGetVideoMode(monitor);
        return VidMode == nullptr ? 0 : VidMode->refreshRate;
    }

    long GLX::_initGlfw() {
        long time;
        //RenderSystem.assertInInitPhase();
        //Window.checkGlfwError((n, string) -> {
        //    throw new IllegalStateException(String.format("GLFW error before init: [0x%X]%s", n, string));
        //});
        //ArrayList arrayList = Lists.newArrayList();
        //GLFWErrorCallback gLFWErrorCallback = glfwSetErrorCallback((n, l) -> arrayList.add(String.format("GLFW error during init: [0x%X]%s", n, l)));
        if (glfwInit()) {
            time = glfwGetTime() * 1.0E9;
            //for (String string2 : arrayList) {
            //    LOGGER.error("GLFW error collected during initialization: {}", (Object)string2);
            //}
        } else {
            //throw new IllegalStateException("Failed to initialize GLFW, errors: " + Joiner.on((String)",").join((Iterable)arrayList));
        }
        //RenderSystem.setErrorCallback((GLFWErrorCallbackI)gLFWErrorCallback);
        return time;
    }

    bool GLX::_shouldClose(Window window) {
        return glfwWindowShouldClose(window.window);
    }

    void GLX::_init(int n, bool bl) {
        //RenderSystem.assertInInitPhase();

        //dogy solution I found online
        char CPUBrandString[0x40];
        unsigned int CPUInfo[4] = {0,0,0,0};

        __cpuid(0x80000000, CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);
        unsigned int nExIds = CPUInfo[0];

        memset(CPUBrandString, 0, sizeof(CPUBrandString));

        for (unsigned int i = 0x80000000; i <= nExIds; ++i)
        {
            __cpuid(i, CPUInfo[0], CPUInfo[1], CPUInfo[2], CPUInfo[3]);

            if (i == 0x80000002)
                memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
            else if (i == 0x80000003)
                memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
            else if (i == 0x80000004)
                memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
        }
        cpuInfo = sprintf("%dx %s",CPUBrandString,std::thread::hardware_concurrency());

        //GlDebug.enableDebugCallback(n, bl);
    }

    std::string GLX::_getCpuInfo() {
        return cpuInfo == "" ? "<unknown>" : cpuInfo;
    }

    //void GLX::_renderCrosshair(int n, boolean bl, boolean bl2, boolean bl3) {
    //    RenderSystem.assertOnRenderThread();
    //    GlStateManager._disableTexture();
    //    GlStateManager._depthMask(false);
    //    GlStateManager._disableCull();
    //    RenderSystem.setShader(GameRenderer::getRendertypeLinesShader);
    //    Tesselator tesselator = RenderSystem.renderThreadTesselator();
    //    BufferBuilder bufferBuilder = tesselator.getBuilder();
    //    RenderSystem.lineWidth(4.0f);
    //    bufferBuilder.begin(VertexFormat.Mode.LINES, DefaultVertexFormat.POSITION_COLOR_NORMAL);
    //    if (bl) {
    //        bufferBuilder.vertex(0.0, 0.0, 0.0).color(0, 0, 0, 255).normal(1.0f, 0.0f, 0.0f).endVertex();
    //        bufferBuilder.vertex(n, 0.0, 0.0).color(0, 0, 0, 255).normal(1.0f, 0.0f, 0.0f).endVertex();
    //    }
    //    if (bl2) {
    //        bufferBuilder.vertex(0.0, 0.0, 0.0).color(0, 0, 0, 255).normal(0.0f, 1.0f, 0.0f).endVertex();
    //        bufferBuilder.vertex(0.0, n, 0.0).color(0, 0, 0, 255).normal(0.0f, 1.0f, 0.0f).endVertex();
    //    }
    //    if (bl3) {
    //        bufferBuilder.vertex(0.0, 0.0, 0.0).color(0, 0, 0, 255).normal(0.0f, 0.0f, 1.0f).endVertex();
    //        bufferBuilder.vertex(0.0, 0.0, n).color(0, 0, 0, 255).normal(0.0f, 0.0f, 1.0f).endVertex();
    //    }
    //    tesselator.end();
    //    RenderSystem.lineWidth(2.0f);
    //    bufferBuilder.begin(VertexFormat.Mode.LINES, DefaultVertexFormat.POSITION_COLOR_NORMAL);
    //    if (bl) {
    //        bufferBuilder.vertex(0.0, 0.0, 0.0).color(255, 0, 0, 255).normal(1.0f, 0.0f, 0.0f).endVertex();
    //        bufferBuilder.vertex(n, 0.0, 0.0).color(255, 0, 0, 255).normal(1.0f, 0.0f, 0.0f).endVertex();
    //    }
    //    if (bl2) {
    //        bufferBuilder.vertex(0.0, 0.0, 0.0).color(0, 255, 0, 255).normal(0.0f, 1.0f, 0.0f).endVertex();
    //        bufferBuilder.vertex(0.0, n, 0.0).color(0, 255, 0, 255).normal(0.0f, 1.0f, 0.0f).endVertex();
    //    }
    //    if (bl3) {
    //        bufferBuilder.vertex(0.0, 0.0, 0.0).color(127, 127, 255, 255).normal(0.0f, 0.0f, 1.0f).endVertex();
    //        bufferBuilder.vertex(0.0, 0.0, n).color(127, 127, 255, 255).normal(0.0f, 0.0f, 1.0f).endVertex();
    //    }
    //    tesselator.end();
    //    RenderSystem.lineWidth(1.0f);
    //    GlStateManager._enableCull();
    //    GlStateManager._depthMask(true);
    //    GlStateManager._enableTexture();
    //}