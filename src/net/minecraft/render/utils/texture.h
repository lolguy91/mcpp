#include <stb/stb_image.h>
struct Texture
{
	unsigned int rid;
	int m_Width, m_Height, m_BPP;
	unsigned char* m_LocalBuffer;

	void parse(std::string fname)
	{
		stbi_set_flip_vertically_on_load(1);
		m_LocalBuffer = stbi_load(fname.c_str(), &m_Width, &m_Height, &m_BPP, 4);
		if (!m_LocalBuffer)
		{
			spdlog::error("[Error]can't load texture at: {}\n",fname );

		}
		glGenTextures(1, &rid);
		glBindTexture(GL_TEXTURE_2D, rid); // Bind without slot selection

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//settings
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
		glBindTexture(GL_TEXTURE_2D, 0);//unbind

		if (m_LocalBuffer)
			stbi_image_free(m_LocalBuffer);
	}

	void bind(int slot)
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, rid);
	}

	void unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
};