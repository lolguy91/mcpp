#include "button.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <spdlog/spdlog.h>

#include <net/minecraft/render/utils/shader.h>
#include <net/minecraft/render/utils/texture.h>
#include <net/minecraft/render/render.h>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
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
        {glm::vec2(x+ width ,        y)    ,glm::vec2(  0.784   ,0.742  )},//hard coded UVs lol
        {glm::vec2(x+ width ,y+ height)    ,glm::vec2(  0.784   ,0.664  )},
        {glm::vec2(x        ,y+ height)    ,glm::vec2(  0       ,0.664  )},

        {glm::vec2(x        ,y + height)   ,glm::vec2(  0       ,0.664  )},
        {glm::vec2(x        ,y         )   ,glm::vec2(  0       ,0.742  )},
        {glm::vec2(x+ width ,         y)   ,glm::vec2(  0.784   ,0.742  )}
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
    glUseProgram(shader);

    Texture tex;
    tex.parse("./res/mc/assets/minecraft/textures/gui/widgets.png");

    tex.bind(0);

    int utexture    =   glGetUniformLocation(shader,"u_Texture");
    int umvp        =   glGetUniformLocation(shader,"u_MVP");
    glUniform1i(utexture,0);
    glUniformMatrix4fv(umvp,1,GL_FALSE,glm::value_ptr(mvp));
}
void button::draw(){
    glUseProgram(shader);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES,0,12);
}
void button::update(){
    
}