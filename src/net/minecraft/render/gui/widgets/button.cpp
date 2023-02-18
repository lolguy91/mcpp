#include "button.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <spdlog/spdlog.h>

#include <net/minecraft/render/utils/shader.h>
#include <net/minecraft/render/utils/texture.h>
#include <net/minecraft/render/render.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

unsigned int vao;
unsigned int shader;

button::button(int _x,int _y,int _width,int _height)
{
    x = _x;
    y = _y;
    width  = _width;
    height = _height;
}

button::~button()
{
}

void button::prepare(Window context){
    unsigned int vbo;
    Vertex crossverts[]{
        {glm::vec2(x + width,y + height)    ,glm::vec2(  1,1)},
        {glm::vec2(x + width,y)             ,glm::vec2(  1,0)},
        {glm::vec2(x,y)                     ,glm::vec2(  0,0)},

        {glm::vec2(x,y)                     ,glm::vec2(  0,0)},
        {glm::vec2(x,y + height)            ,glm::vec2(  0,1)},
        {glm::vec2(x + width,y +height)     ,glm::vec2(  1,1)},
    };
    glm::mat4 projection = glm::ortho<int>(0, context.width,context.height,0);
    glm::mat4 identity;
    glm::mat4 mvp = projection * identity * identity;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(crossverts),crossverts,GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(sizeof(float)*2));
    glEnableVertexAttribArray(1);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    ShaderProgramSource source = ParseShader("./res/shader/basic.glsl");
    shader = CreateShader(source.VertexSource,source.FragmentSource);

    Texture tex;
    tex.parse("./res/mc/assets/icons/icon_32x32.png");

    tex.bind(0);

    glUniform1i(glGetUniformLocation(shader,"u_Texture"),0);
    glUniformMatrix4fv(glGetUniformLocation(shader,"u_MVP"),00,false,&mvp[0][0]);
}
void button::draw(){
    glUseProgram(shader);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES,0,12);
}
void button::update(){
    
}