#include <stb/stb_image.h>
#include <spdlog/spdlog.h>
#include <stdio.h>

#include "Minecraft.h"
#include "render/render.h"


Minecraft mc;

void errorcallback(int error_code, const char* description){
    spdlog::error("OpenGL Error(code:{} ): {}",error_code,description);
}

void SetIcon(){
    unsigned char* pixloc = nullptr;;
    int width,height,channels;

    unsigned char* pixloc2 = nullptr;;
    int width2,height2,channels2;

    pixloc = stbi_load("./res/mc/assets/icons/icon_16x16.png",&width,&height,&channels,0);

    pixloc2 = stbi_load("./res/mc/assets/icons/icon_32x32.png",&width2,&height2,&channels2,0);

    if (pixloc == nullptr){
        spdlog::error("Could not set 16x icon: image loading failed");
    }

    if (pixloc2 == nullptr){
        spdlog::error("Could not set 32x icon: image loading failed");
    }
    GLFWimage iconimgs[2];
    iconimgs[0].pixels = pixloc;
    iconimgs[0].height = height;
    iconimgs[0].width  = width;

    iconimgs[1].pixels = pixloc2;
    iconimgs[1].height = height2;
    iconimgs[1].width  = width2;
    glfwSetWindowIcon(mc.window.nativeWindow,2,iconimgs);
}

void updateTitle(){
    char titlechar[256];
    std::string title;
    std::string extra;
    sprintf(titlechar,"Minecraft %s %s",mc.config.game.launchVersion.c_str(),extra.c_str());

    title = std::string(titlechar);

    glfwSetWindowTitle(mc.window.nativeWindow,title.c_str());
}
void close(){ 
   mc.running = false;
}


void MCinit(GameConfig _config,GLFWwindow * _window)
{   
    spdlog::set_level(spdlog::level::info);
    spdlog::info("Initializing MCPP...");


    //initialize the stuff
    mc.running = true;
    mc.config = _config;
    mc.window = Window(_window);

    //set the icon and title
    SetIcon();
    updateTitle();

    //initialize OpenGL
    initGlad();

    //glEnable(GL_DEBUG_OUTPUT);
    glfwSetErrorCallback((GLFWerrorfun)&errorcallback);
    
    glClearColor(.5,.5,1,0);

    //initialize other stuff
    //CreateCrosshair(window);
    mc.test.prepare(mc.window);
    mc.test2.prepare(mc.window);

    spdlog::info("Initialization done!");
}
void MCupdate()
{
    glClear(GL_COLOR_BUFFER_BIT);
    mc.test.update();
    mc.test.draw();

    mc.test2.update();
    mc.test2.draw();

    //renderCrosshair();

    if(glfwWindowShouldClose(mc.window.nativeWindow))
        close();
}


bool IsRunning()
{
    return mc.running;
}

Minecraft* GetMinecraft(){
    return &mc;
}

Minecraft::Minecraft():
test(130,150,350,50,false),
test2(130,250,350,50,true){
   
}
