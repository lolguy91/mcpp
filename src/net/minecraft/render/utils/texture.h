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
			std::cout << "[Error]can't load texture at: " << fname << std::endl;

		}
		GLCall(glGenTextures(1, &rid));
		GLCall(glBindTexture(GL_TEXTURE_2D, rid)); // Bind without slot selection

		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));//settings
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer));
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));//unbind

		if (m_LocalBuffer)
			stbi_image_free(m_LocalBuffer);
	}

	void bind(int slot)
	{
		GLCall(glActiveTexture(GL_TEXTURE0 + slot));
		GLCall(glBindTexture(GL_TEXTURE_2D, rid));
	}

	void unbind(int slot)
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	}
};