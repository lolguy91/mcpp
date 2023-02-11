#include "render.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include "utils/shader.h"

void initGlad()
{
    int version = gladLoadGLLoader((GLADloadproc)&glfwGetProcAddress);
    if (version == 0) {
        spdlog::error("Could not Initialize GLAD");
        exit(EXIT_FAILURE);
    }

    // Successfully loaded OpenGL
    //spdlog::info("Loaded OpenGL {}.{}\n", GLAD_VERSION (version), GLAD_VERSION_MINOR(version));
}

struct {
unsigned int vbo;
unsigned int shader;
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

ShaderProgramSource source = ParseShader("./res/shader/basic.glsl");
crosshairData.shader = CreateShader(source.VertexSource,source.FragmentSource);

}

void renderCrosshair()
{   
    glUseProgram(crosshairData.shader);
    glDrawArrays(GL_TRIANGLES,0,2);
}

