#include "render.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include "utils/shader.h"
#include "utils/texture.h"

void initGlad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        spdlog::error("Could not Initialize GLAD");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Successfully loaded OpenGL
    //spdlog::info("Loaded OpenGL {}.{}\n", GLAD_VERSION (version), GLAD_VERSION_MINOR(version));
}

struct {
unsigned int vbo;
unsigned int vao;
unsigned int shader;
} crosshairData;

void CreateCrosshair(){
Vertex crossverts[]{
    {glm::vec2(  .5,.5) ,glm::vec2(  1,1)},
    {glm::vec2( .5,-.5) ,glm::vec2(  1,0)},
    {glm::vec2( -.5,-.5),glm::vec2(  0,0)},

    {glm::vec2(-.5,-.5) ,glm::vec2(  0,0)},
    {glm::vec2( -.5,.5) ,glm::vec2(  0,1)},
    {glm::vec2(.5,.5)   ,glm::vec2(  1,1)},
};
glGenVertexArrays(1, &crosshairData.vao);
glBindVertexArray(crosshairData.vao);

glGenBuffers(1,&crosshairData.vbo);
glBindBuffer(GL_ARRAY_BUFFER,crosshairData.vbo);
glBufferData(GL_ARRAY_BUFFER,sizeof(crossverts),crossverts,GL_STATIC_DRAW);

glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
glEnableVertexAttribArray(0);

glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(sizeof(float)*2));
glEnableVertexAttribArray(1);

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

ShaderProgramSource source = ParseShader("./res/shader/basic.glsl");
crosshairData.shader = CreateShader(source.VertexSource,source.FragmentSource);

Texture tex;
tex.parse("./res/mc/icons/icon_32x32.png");

tex.bind(0);

glUniform1i(glGetUniformLocation(crosshairData.shader,"u_Texture"),0);
}

void renderCrosshair()
{   
    glUseProgram(crosshairData.shader);
    glBindVertexArray(crosshairData.vao);
    glDrawArrays(GL_TRIANGLES,0,12);
}