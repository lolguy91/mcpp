#include "render.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

void initGlad()
{
    if(!gladLoadGL()){
        spdlog::error("Could not Initialize GLAD");
        exit(EXIT_FAILURE);
    }
}

struct {
unsigned int vbo;

} crosshairData;

void CreateCrosshair(){
float crossverts[]{
    .5,.5,
    .5,-.5,
    -.5,-.5,

    -.5,-.5,
    -.5,.5,
    -.5,.5,
};

glGenBuffers(1,&crosshairData.vbo);
glBindBuffer(GL_ARRAY_BUFFER,crosshairData.vbo);
glBufferData(GL_ARRAY_BUFFER,sizeof(crossverts),crossverts,GL_STATIC_DRAW);
}

void renderCrosshair()
{
    glDrawArrays(GL_TRIANGLES,0,6);
}

