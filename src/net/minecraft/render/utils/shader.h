#include <fstream>
#include <sstream>
#include <string>



struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

enum ShaderType
{
	NONE = -1, VERTEX = 0, FRAGMENT = 1
};

struct ShaderProgramSource ParseShader(const std::string& filepath);
unsigned int CompileShader(unsigned int type, const std::string& source);
unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);