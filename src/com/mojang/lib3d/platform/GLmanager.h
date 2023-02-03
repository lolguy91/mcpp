#ifndef __GLMANAGER_H__
#define __GLMANAGER_H__
#include <string>
#include <vector>
#include <src/com/mojang/math/Matrix4f.h>
#include <src/com/mojang/math/Vector3f.h>
#include <src/com/mojang/math/Vector4f.h>

	struct TextureState {
        bool enable;
        int binding;
    };

    struct ColorMask {
        bool red = true;
        bool green = true;
        bool blue = true;
        bool alpha = true;

    };
    struct StencilFunc {
        int func = 519;
        int ref;
        int mask = -1;
    };

    struct StencilState {
        StencilFunc func = StencilFunc();
        int mask = -1;
        int fail = 7680;
        int zfail = 7680;
        int zpass = 7680;

    };

    void _disableScissorTest();

    void _enableScissorTest();

    void _scissorBox(int n, int n2, int n3, int n4);

    void _disableDepthTest();

    void _enableDepthTest();

    void _depthFunc(int n);

    void _depthMask(bool bl);

    void _disableBlend();

    void _enableBlend();

    void _blendFunc(int srcRgb, int dstRgb);

    void _blendFuncSeparate(int srcRgb, int dstRgb, int srcAlpha, int dstAlpha);

    void _blendEquation(int n);

    int _glGetProgrami(int program, int pname);

    void _glAttachShader(int n, int n2);

    void _glDeleteShader(int n);

    int _glCreateShader(int n);

    void _glShaderSource(int n, std::string source);

    void _glCompileShader(int n);

    int _glGetShaderiv(int shader, int pname);

    void _glUseProgram(int n);
    

    int _glCreateProgram();
    void _glDeleteProgram(int n);

    void _glLinkProgram(int n);

    int _glGetUniformLocation(int n, char* charSequence);

    void _glUniform1(int n, int* intBuffer);

    void _glUniform1i(int n, int n2);

    void _glUniform1(int n, float* floatBuffer);

    void _glUniform2(int n, int* intBuffer);
    void _glUniform2(int n, float* floatBuffer);

    void _glUniform3(int n, int* intBuffer);

    void _glUniform3(int n, float* floatBuffer);

    void _glUniform4(int n, int* intBuffer);

    void _glUniform4(int n, float* floatBuffer);

    void _glUniformMatrix2(int n, bool bl, float* floatBuffer);

    void _glUniformMatrix3(int n, bool bl, float* floatBuffer);

    void _glUniformMatrix4(int n, bool bl, float* floatBuffer);

    int _glGetAttribLocation(int n, char* charSequence);

    void _glBindAttribLocation(int n, int n2, char* charSequence);

    unsigned int _glGenBuffers();

    unsigned int _glGenVertexArrays();

    void _glBindBuffer(int n, int n2);

    void _glBindVertexArray(int n);

    void _glBufferData(int buffer, void* data, int size, int usage);
    void _glBufferData(int buffer, void* data,int size, int usage);

    void* _glMapBuffer(int n, int n2);

    void _glUnmapBuffer(int n);

    void _glDeleteBuffers(int n);

    void _glCopyTexSubImage2D(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8);

    void _glDeleteVertexArrays(int n);

    void _glBindFramebuffer(int n, int n2);
    void _glBlitFrameBuffer(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10);

    void _glBindRenderbuffer(int n, int n2);

    void _glDeleteRenderbuffers(int n);

    void _glDeleteFramebuffers(int n);

    unsigned int _glGenFramebuffers();

    unsigned int _glGenRenderbuffers();

    void _glRenderbufferStorage(int n, int n2, int n3, int n4);
    void _glFramebufferRenderbuffer(int n, int n2, int n3, int n4);

    int _glCheckFramebufferStatus(int n);

    void _glFramebufferTexture2D(int n, int n2, int n3, int n4, int n5);

    int _getBoundFramebuffer();

    void _glActiveTexture(int n);

    std::string _glGetShaderInfoLog(int n, int n2);

    std::string _glGetProgramInfoLog(int n, int n2);

    //void _setupLevelDiffuseLighting(Vector3f vector3f, Vector3f vector3f2, Matrix4f matrix4f);

    //void _setupGuiFlatDiffuseLighting(Vector3f vector3f, Vector3f vector3f2);

    //void _setupGui3DDiffuseLighting(Vector3f vector3f, Vector3f vector3f2);

    void _enableCull();

    void _disableCull();
    void _polygonMode(int n, int n2);

    void _enablePolygonOffset();

    void _disablePolygonOffset();

    void _polygonOffset(float f, float f2);

    void _enableColorLogicOp();
    void _disableColorLogicOp();

    void _logicOp(int n);

    void _activeTexture(int n);

    void _enableTexture();

    void _disableTexture();

    void _texParameter(int n, int n2, float f);

    void _texParameter(int n, int n2, int n3);

    int _getTexLevelParameter(int n, int n2, int n3);

    unsigned int _genTexture();

    void _genTextures(unsigned int* arrn);

    void _deleteTexture(unsigned int n);

    void _deleteTextures(std::vector<unsigned int> arrn);

    void _bindTexture(int n);

    int _getTextureId(int n);

    int _getActiveTexture();

    void _texImage2D(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int* intBuffer);

    void _texSubImage2D(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, void* l);

    void _getTexImage(int n, int n2, int n3, int n4, void* l);

    void _viewport(int n, int n2, int n3, int n4);
    void _colorMask(bool bl, bool bl2, bool bl3, bool bl4);

    void _stencilFunc(int n, int n2, int n3);

    void _stencilMask(int n);

    void _stencilOp(int n, int n2, int n3);

    void _clearDepth(double d);

    void _clearColor(float f, float f2, float f3, float f4);

    void _clearStencil(int n);

    void _clear(int n, bool bl);

    void _glDrawPixels(int n, int n2, int n3, int n4, void* l);

    void _vertexAttribPointer(int n, int n2, int n3, bool bl, int n4, const void* l);

    void _vertexAttribIPointer(int n, int n2, int n3, int n4, const void* l);
    void _enableVertexAttribArray(int n);

    void _disableVertexAttribArray(int n);

    void _drawElements(int n, int n2, int n3, void* l);

    void _pixelStore(int n, int n2);

    void _readPixels(int n, int n2, int n3, int n4, int n5, int n6, void* byteBuffer);

    void _readPixels(int n, int n2, int n3, int n4, int n5, int n6, void* l);
    int _getError();

    std::string _getString(int n);

    int _getInteger(int n);

    void init();
    #endif // __GLMANAGER_H__