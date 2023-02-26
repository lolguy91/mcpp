#include "TextureManager.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include <stb/stb_image.h>

TextureManager::TextureManager(/* args */)
{

    {
        int m_Width, m_Height, m_BPP;
        unsigned char* m_LocalBuffer;

        stbi_set_flip_vertically_on_load(1);
        m_LocalBuffer = stbi_load("res/mc/assets/minecraft/textures/font/ascii.png", &m_Width, &m_Height, &m_BPP, 4);
        if (!m_LocalBuffer)
        {
            spdlog::error("Can't load Font");
        }
        glGenTextures(1, &FONT_ASCII);
        glBindTexture(GL_TEXTURE_2D, FONT_ASCII); // Bind without slot selection
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//settings
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
        glBindTexture(GL_TEXTURE_2D, 0);//unbind
        if (m_LocalBuffer)
            stbi_image_free(m_LocalBuffer);
    }
}

TextureManager::~TextureManager()
{
}