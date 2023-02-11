#include <stb/stb_image.h>
#include <spdlog/spdlog.h>
#include <stdio.h>

#include "Minecraft.h"
#include "render/render.h"

GameConfig config;
GLFWwindow* window;
bool running;

void errorcallback(int error_code, const char* description){
    spdlog::error("OpenGL Error(code:{} ): {}",error_code,description);
}

void SetIcon(){
    unsigned char* pixloc = nullptr;;
    int width,height,channels;

    pixloc = stbi_load("./res/icon.png",&width,&height,&channels,0);

    if (pixloc == nullptr){
        spdlog::error("Could not set icon: image loading failed");
    }
    GLFWimage iconimg;
    iconimg.pixels = pixloc;
    iconimg.height = height;
    iconimg.width  = width;
    glfwSetWindowIcon(window,1,&iconimg);
}

void updateTitle(){
    char titlechar[256];
    std::string title;
    std::string extra;
    sprintf(titlechar,"Minecraft %s %s",config.game.launchVersion.c_str(),extra.c_str());

    title = std::string(titlechar);

    glfwSetWindowTitle(window,title.c_str());
}
void close(){
    
   running = false;
}


void MCinit(GameConfig _config,GLFWwindow * _window)
{   
    spdlog::set_level(spdlog::level::info);
    spdlog::info("Initializing MCPP...");

    running = true;
    //save the stuff
    config = _config;
    window = _window;

    //set the icon and title
    SetIcon();
    updateTitle();

    //initialize OpenGL
    glfwSetErrorCallback((GLFWerrorfun)&errorcallback);
    initGlad();
    glClearColor(0,0,0,0);

    //initialize other stuff
    CreateCrosshair();

    spdlog::info("Initialization done!");
}
void MCupdate()
{
    glClear(GL_COLOR_BUFFER_BIT);

    renderCrosshair();

    if(glfwWindowShouldClose(window))
        close();
}


bool IsRunning()
{
    return running;
}
