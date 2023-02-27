#include "Font.h"
#include <net/minecraft/render/utils/shader.h>
#include <net/minecraft/render/utils/texture.h>
#include <net/minecraft/Minecraft.h>

FontRenderer::FontRenderer()
{
    
}
glm::vec2 getUVs(char idx, char corner){
    glm::vec2 coords(idx / 16,idx % 16);
    
    switch (corner)
    {
    case 1:
        coords = coords + glm::vec2(ASCII_NORM_CHAR_SIZE,0);
    case 2:
        coords = coords + glm::vec2(0,ASCII_NORM_CHAR_SIZE);
    case 3:
        coords = coords + glm::vec2(ASCII_NORM_CHAR_SIZE,ASCII_NORM_CHAR_SIZE);
    default:
        break;
    }

    return glm::vec2(coords.x / ASCII_TEX_SIZE,coords.y / ASCII_TEX_SIZE);
}

void FontRenderer::prepare(Window context)
{
    
    
    //spdlog::info("context.width: {} context.height: {}",context.width,context.height);

    glm::mat4 projection = glm::ortho<float>(0.,(float)context.width,(float)context.height,0.0f,0.0f,10000.0f);
    glm::mat4 identity(1.0f);

    glm::mat4 mvp = identity * identity * projection;

    //spdlog::info("mvp: \n {} {} {} {}\n {} {} {} {}\n {} {} {} {}\n {} {} {} {}"
    //,mvp[0][0],mvp[0][1],mvp[0][2],mvp[0][3]
    //,mvp[1][0],mvp[1][1],mvp[1][2],mvp[1][3]
    //,mvp[2][0],mvp[2][1],mvp[2][2],mvp[2][3]
    //,mvp[3][0],mvp[3][1],mvp[3][2],mvp[3][3]);//debug

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    
    glBufferData(GL_ARRAY_BUFFER,verticies.size() , verticies.data(),GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const void*)(sizeof(float)*2));
    glEnableVertexAttribArray(1);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    ShaderProgramSource source = ParseShader("./res/shader/basic.glsl");
    shader = CreateShader(source.VertexSource,source.FragmentSource);
    glUseProgram(shader);

    int utexture    =   glGetUniformLocation(shader,"u_Texture");
    int umvp        =   glGetUniformLocation(shader,"u_MVP");
    glUniform1i(utexture,mc->tm.WIDGETS);
    glUniformMatrix4fv(umvp,1,GL_FALSE,glm::value_ptr(mvp));
}

void FontRenderer::addText(std::string text,int x, int y,int charsize,int spacing)
{
    const char* chars = text.c_str();

    for (size_t i = 0; chars[i] != 0; i++)
    {
        int charx = x + (i*charsize) + spacing;
        int chary = y + (i*charsize) + spacing;
        
        verticies.push_back({glm::vec2(charx            ,chary          ),getUVs(i,0)});//Fuck IBOs
        verticies.push_back({glm::vec2(charx+charsize   ,chary          ),getUVs(i,1)});
        verticies.push_back({glm::vec2(charx            ,chary+charsize ),getUVs(i,2)});

        verticies.push_back({glm::vec2(charx            ,chary+charsize ),getUVs(i,2)});
        verticies.push_back({glm::vec2(charx+charsize   ,chary+charsize ),getUVs(i,3)});
        verticies.push_back({glm::vec2(charx            ,chary          ),getUVs(i,0)});

    }
    

    needsupdate = true;
}

void FontRenderer::clear()
{
    
}

void FontRenderer::draw()
{
    
}

void FontRenderer::update()
{
    if(needsupdate){
        glBufferData(GL_ARRAY_BUFFER,verticies.size() , verticies.data(),GL_STATIC_DRAW);
    }
}
