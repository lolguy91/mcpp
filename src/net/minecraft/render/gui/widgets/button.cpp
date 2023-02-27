#include "button.h"
#include "../../../input/Input.h"

#include <spdlog/spdlog.h>

#include <net/minecraft/render/utils/shader.h>
#include <net/minecraft/render/utils/texture.h>


glm::vec2 unpresseduvs[6] = {
    glm::vec2(0.784   ,0.742  ),//hard coded UVs lol
    glm::vec2(0.784   ,0.664  ),
    glm::vec2(0       ,0.664  ),
    glm::vec2(0       ,0.664  ),
    glm::vec2(0       ,0.742  ),
    glm::vec2(0.784   ,0.742  )
};
glm::vec2 hoveruvs[6]   = {
    glm::vec2(0.784   ,0.664  ),//hard coded UVs lol
    glm::vec2(0.784   ,0.586  ),
    glm::vec2(0       ,0.586  ),
    glm::vec2(0       ,0.586  ),
    glm::vec2(0       ,0.664   ),
    glm::vec2(0.784   ,0.664  )
};
glm::vec2 grayuvs[6]   = {
    glm::vec2(0.784   ,0.742  ),//hard coded UVs lol
    glm::vec2(0.784   ,0.820  ),
    glm::vec2(0       ,0.820  ),
    glm::vec2(0       ,0.820  ),
    glm::vec2(0       ,0.742  ),
    glm::vec2(0.784   ,0.742  )
};

void button::applyUV(glm::vec2* uv){
    for (size_t i = 0; i < 6; i++)
    {
        verts[i] = {verts[i].position,uv[i]};
    }
}

button::button(int _x,int _y,int _width,int _height,bool _gray)
{
    x = _x;
    y = _y;
    width  = _width;
    height = _height;
    gray = _gray;

    Vertex vertss[6]{
        {glm::vec2(x+ width ,        y ),glm::vec2(  0.784   ,0.742  )},//hard coded UVs lol
        {glm::vec2(x+ width ,y+ height ),glm::vec2(  0.784   ,0.664  )},
        {glm::vec2(x        ,y+ height ),glm::vec2(  0       ,0.664  )},

        {glm::vec2(x        ,y + height),glm::vec2(0       ,0.664  )},
        {glm::vec2(x        ,y         ),glm::vec2(0       ,0.742  )},
        {glm::vec2(x+ width ,         y),glm::vec2(0.784   ,0.742  )}
    };

    for (size_t i = 0; i < 6; i++)
    {
        verts[i] = vertss[i];
    }
    
}


void button::prepare(Window context){

    
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
    
    glBufferData(GL_ARRAY_BUFFER,sizeof(verts),verts,GL_STATIC_DRAW);
    
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
void button::draw(){
    glUseProgram(shader);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES,0,12);
}
void button::update(){
    int mousex = Input::mouseX;
    int mousey = Input::mouseY;

    bool _hovered = (mousex >= x) && (mousex <= (x + width)) && 
                    (mousey >= y) && (mousey <= (y + height));

    if(hovered != _hovered){
        hovered = _hovered;
        needsupdate = true;
    }else if(Input::isMouseButtonDown(GLFW_MOUSE_BUTTON_1) && _hovered && !gray){
        spdlog::info("A button was clicked");
    } 

    if(needsupdate){
        if(gray){
            applyUV(grayuvs);
        }else{
            if(hovered){
                applyUV(hoveruvs); 
            }else{
                applyUV(unpresseduvs);    
            }
        }
    needsupdate = false;
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(verts),verts,GL_STATIC_DRAW);
    }
    
}