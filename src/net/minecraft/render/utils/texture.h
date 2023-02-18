
struct Texture
{
	unsigned int rid;
	int m_Width, m_Height, m_BPP;
	unsigned char* m_LocalBuffer;

	void parse(std::string fname);
	void bind(int slot);
	void unbind();
};