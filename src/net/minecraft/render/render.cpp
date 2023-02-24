#include "render.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include "utils/shader.h"
#include "utils/texture.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

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

void CreateCrosshair(Window context){
Vertex crossverts[]{
    {glm::vec2(200.0f,200.0f),glm::vec2(  1.0f,1.0f)},
    {glm::vec2(200.0f,100.0f),glm::vec2(  1.0f,0.0f)},
    {glm::vec2(100.0f,100.0f),glm::vec2(  0.0f,0.0f)},

    {glm::vec2(100.0f,100.0f),glm::vec2(  0.0f,0.0f)},
    {glm::vec2(100.0f,200.0f),glm::vec2(  0.0f,1.0f)},
    {glm::vec2(200.0f,200.0f),glm::vec2(  1.0f,1.0f)},
};
spdlog::info("btw is spdlog actually fast?");
spdlog::info("context.width: {} context.height: {}",context.width,context.height);

glm::mat4 projection = glm::ortho<float>(0.,(float)context.width,(float)context.height,0.0f,0.0f,10000.0f);
glm::mat4 identity(1.0f);

glm::mat4 mvp = identity * identity * projection;

spdlog::info("mvp: \n {} {} {} {}\n {} {} {} {}\n {} {} {} {}\n {} {} {} {}"
,mvp[0][0],mvp[0][1],mvp[0][2],mvp[0][3]
,mvp[1][0],mvp[1][1],mvp[1][2],mvp[1][3]
,mvp[2][0],mvp[2][1],mvp[2][2],mvp[2][3]
,mvp[3][0],mvp[3][1],mvp[3][2],mvp[3][3]);//debug

glGenVertexArrays(1, &crosshairData.vao);
glBindVertexArray(crosshairData.vao);

glGenBuffers(1,&crosshairData.vbo);
glBindBuffer(GL_ARRAY_BUFFER,crosshairData.vbo);
glBufferData(GL_ARRAY_BUFFER,sizeof(crossverts),crossverts,GL_STATIC_DRAW);

glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
glEnableVertexAttribArray(0);

glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(sizeof(float)*2));
glEnableVertexAttribArray(1);

glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

ShaderProgramSource source = ParseShader("./res/shader/basic.glsl");
crosshairData.shader = CreateShader(source.VertexSource,source.FragmentSource);
glUseProgram(crosshairData.shader);

Texture tex;
tex.parse("./res/mc/assets/icons/icon_32x32.png");

tex.bind(0);

int utexture    =   glGetUniformLocation(crosshairData.shader,"u_Texture");
int umvp        =   glGetUniformLocation(crosshairData.shader,"u_MVP");
glUniform1i(utexture,0);
glUniformMatrix4fv(umvp,1,GL_FALSE,glm::value_ptr(mvp));

} 
void renderCrosshair()
{   
    glUseProgram(crosshairData.shader);
    glBindVertexArray(crosshairData.vao);
    glDrawArrays(GL_TRIANGLES,0,12);
}