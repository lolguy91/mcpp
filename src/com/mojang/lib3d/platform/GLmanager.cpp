#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <src/com/mojang/lib3d/platform/GLmanager.h>

    //bool ON_LINUX = Util.getPlatform() == Util.OS.LINUX;
    int TEXTURE_COUNT = 12;
    int activeTexture;
    TextureState TEXTURES[12];
    ColorMask COLOR_MASK;

    void _disableScissorTest() {
        //RenderSystem.assertOnRenderThreadOrInit();
        glDisable(GL_SCISSOR_TEST);
    }

    void _enableScissorTest() {
        //RenderSystem.assertOnRenderThreadOrInit();
        glEnable(GL_SCISSOR_TEST);
    }

    void _scissorBox(int n, int n2, int n3, int n4) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glScissor((int)n, (int)n2, (int)n3, (int)n4);
    }

    void _disableDepthTest() {
        //RenderSystem.assertOnRenderThreadOrInit();
        glDisable(GL_DEPTH_TEST);
    }

    void _enableDepthTest() {
        //RenderSystem.assertOnRenderThreadOrInit();
        glEnable(GL_DEPTH_TEST);
    }

    void _depthFunc(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
            glDepthFunc((int)n);
    }

    void _depthMask(bool bl) {
            glDepthMask((bool)bl);
    }

    void _disableBlend() {
        //RenderSystem.assertOnRenderThread();
        glDisable(GL_BLEND);
    }

    void _enableBlend() {
        //RenderSystem.assertOnRenderThread();
        glEnable(GL_BLEND);
    }

    void _blendFunc(int srcRgb, int dstRgb) {
        //RenderSystem.assertOnRenderThread();
        glBlendFunc((int)srcRgb, (int)dstRgb);
    }

    void _blendFuncSeparate(int srcRgb, int dstRgb, int srcAlpha, int dstAlpha) {
        //RenderSystem.assertOnRenderThread();
        glBlendFuncSeparate(srcRgb, dstRgb, srcAlpha, dstAlpha);
    }

    void _blendEquation(int n) {
        //RenderSystem.assertOnRenderThread();
        glBlendEquation((int)n);
    }

    int _glGetProgrami(int program, int pname) {
        //RenderSystem.assertOnRenderThread();
        int params;
        glGetProgramiv(program,pname,&params);
        return params;
    }

    void _glAttachShader(int n, int n2) {
        //RenderSystem.assertOnRenderThread();
        glAttachShader((int)n, (int)n2);
    }

    void _glDeleteShader(int n) {
        //RenderSystem.assertOnRenderThread();
        glDeleteShader((int)n);
    }

    int _glCreateShader(int n) {
        //RenderSystem.assertOnRenderThread();
        return glCreateShader((int)n);
    }

    void _glShaderSource(int n, std::string source) {
        //RenderSystem.assertOnRenderThread();
        glShaderSource(n,1, (const GLchar*const*)source.c_str(), (const GLint*)source.size());
        
    }

    void _glCompileShader(int n) {
        //RenderSystem.assertOnRenderThread();
        glCompileShader((int)n);
    }

    int _glGetShaderiv(int shader, int pname) {
        //RenderSystem.assertOnRenderThread();
        int params;
        glGetShaderiv(shader,pname,&params);
        return params;
    }

    void _glUseProgram(int n) {
        //RenderSystem.assertOnRenderThread();
        glUseProgram((int)n);
    }

    int _glCreateProgram() {
        //RenderSystem.assertOnRenderThread();
        return glCreateProgram();
    }

    void _glDeleteProgram(int n) {
        //RenderSystem.assertOnRenderThread();
        glDeleteProgram((int)n);
    }

    void _glLinkProgram(int n) {
        //RenderSystem.assertOnRenderThread();
        glLinkProgram((int)n);
    }

    int _glGetUniformLocation(int n, char* charSequence) {
        //RenderSystem.assertOnRenderThread();
        return glGetUniformLocation((int)n, (char*)charSequence);
    }

    void _glUniform1(int n, int* intBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform1iv((int)n,1, (int*)intBuffer);
    }

    void _glUniform1i(int n, int n2) {
        //RenderSystem.assertOnRenderThread();
        glUniform1i((int)n, (int)n2);
    }

    void _glUniform1(int n, float* floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform1fv((int)n,1, (float*)floatBuffer);
    }

    void _glUniform2(int n, int* intBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform2iv((int)n,1, (int*)intBuffer);
    }

    void _glUniform2(int n, float* floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform2fv((int)n,1, (float*)floatBuffer);
    }

    void _glUniform3(int n, int* intBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform3iv((int)n,1, (int*)intBuffer);
    }

    void _glUniform3(int n, float* floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform3fv((int)n,1, (float*)floatBuffer);
    }

    void _glUniform4(int n, int* intBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform4iv((int)n,1, (int*)intBuffer);
    }

    void _glUniform4(int n, float* floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform4fv((int)n,1, (float*)floatBuffer);
    }

    void _glUniformMatrix2(int n, bool bl, float* floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniformMatrix2fv((int)n,1, (bool)bl, (float*)floatBuffer);
    }

    void _glUniformMatrix3(int n, bool bl, float* floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniformMatrix3fv((int)n,1, (bool)bl, (float*)floatBuffer);
    }

    void _glUniformMatrix4(int n, bool bl, float* floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniformMatrix4fv((int)n,1, (bool)bl, (float*)floatBuffer);
    }

    int _glGetAttribLocation(int n, char* charSequence) {
        //RenderSystem.assertOnRenderThread();
        return glGetAttribLocation((int)n, (char*)charSequence);
    }

    void _glBindAttribLocation(int n, int n2, char* charSequence) {
        //RenderSystem.assertOnRenderThread();
        glBindAttribLocation((int)n, (int)n2, (char*)charSequence);
    }

    unsigned int _glGenBuffers() {
        //RenderSystem.assertOnRenderThreadOrInit();
        unsigned int vbo = 0;
        glGenBuffers(1, &vbo);
        return vbo;
    }

    unsigned int _glGenVertexArrays() {
        //RenderSystem.assertOnRenderThreadOrInit();
        unsigned int vao = 0;
        glGenVertexArrays(1, &vao);
        return vao;
    }

    void _glBindBuffer(int n, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glBindBuffer((int)n, (int)n2);
    }

    void _glBindVertexArray(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glBindVertexArray((int)n);
    }

    void _glBufferData(int buffer, void* data, int size, int usage) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glBufferData(buffer,size, data, usage);
    }

    void _glBufferData(int buffer, void* data,int size, int usage) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glBufferData(buffer,size,data,usage);
    }

    void* _glMapBuffer(int n, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        return glMapBuffer((int)n, (int)n2);
    }

    void _glUnmapBuffer(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glUnmapBuffer((int)n);
    }

    void _glDeleteBuffers(int n) {
        //RenderSystem.assertOnRenderThread();
        //if (ON_LINUX) {
        //    glBindBuffer((int)34962, (int)n);
        //    glBufferData((int)34962, (long)0L, (int)35048);
        //    glBindBuffer((int)34962, (int)0);
        //}
        glDeleteBuffers(1,(const GLuint*)n);
    }

    void _glCopyTexSubImage2D(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glCopyTexSubImage2D((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, (int)n7, (int)n8);
    }

    void _glDeleteVertexArrays(int n) {
        //RenderSystem.assertOnRenderThread();
        glDeleteVertexArrays(1,(const GLuint*)n);
    }

    void _glBindFramebuffer(int n, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glBindFramebuffer((int)n, (int)n2);
    }

    void _glBlitFrameBuffer(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glBlitFramebuffer((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, (int)n7, (int)n8, (int)n9, (int)n10);
    }

    void _glBindRenderbuffer(int n, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glBindRenderbuffer((int)n, (int)n2);
    }

    void _glDeleteRenderbuffers(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glDeleteRenderbuffers(1,(const GLuint*)n);
    }

    void _glDeleteFramebuffers(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glDeleteFramebuffers(1,(const GLuint*)n);
    }

    unsigned int _glGenFramebuffers() {
        //RenderSystem.assertOnRenderThreadOrInit();
        unsigned int fbo;
        glGenFramebuffers(1,&fbo);
        return fbo;
    }

    unsigned int _glGenRenderbuffers() {
        //RenderSystem.assertOnRenderThreadOrInit();
        unsigned int rbo;
        glGenRenderbuffers(1,&rbo);
        return rbo;
    }

    void _glRenderbufferStorage(int n, int n2, int n3, int n4) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glRenderbufferStorage((int)n, (int)n2, (int)n3, (int)n4);
    }

    void _glFramebufferRenderbuffer(int n, int n2, int n3, int n4) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glFramebufferRenderbuffer((int)n, (int)n2, (int)n3, (int)n4);
    }

    int _glCheckFramebufferStatus(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        return glCheckFramebufferStatus((int)n);
    }

    void _glFramebufferTexture2D(int n, int n2, int n3, int n4, int n5) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glFramebufferTexture2D((int)n, (int)n2, (int)n3, (int)n4, (int)n5);
    }

    int _getBoundFramebuffer() {
        //RenderSystem.assertOnRenderThread();
        int data;
        glGetIntegerv(36006,&data);
        return data;
    }

    void _glActiveTexture(int n) {
        //RenderSystem.assertOnRenderThread();
        glActiveTexture((int)n);
    }

    std::string _glGetShaderInfoLog(int n, int n2) {
        //RenderSystem.assertOnRenderThread();
        GLsizei length;
        GLchar* string;
        glGetShaderInfoLog((int)n, (int)n2,&length,string);
        return std::string(string,length);
    }

    std::string _glGetProgramInfoLog(int n, int n2) {
        //RenderSystem.assertOnRenderThread();
        GLsizei length;
        GLchar* string;
        glGetProgramInfoLog((int)n, (int)n2,&length,string);
        return std::string(string,length);
    }

    //void _setupLevelDiffuseLighting(Vector3f vector3f, Vector3f vector3f2, Matrix4f matrix4f) {
    //    //RenderSystem.assertOnRenderThread();
    //    Vector4f vector4f = Vector4f(vector3f);
    //    vector4f.transform(matrix4f);
    //    Vector4f vector4f2 = Vector4f(vector3f2);
    //    vector4f2.transform(matrix4f);
    //    RenderSystem.setShaderLights(Vector3f(vector4f), Vector3f(vector4f2));
    //}
//
    //void _setupGuiFlatDiffuseLighting(Vector3f vector3f, Vector3f vector3f2) {
    //    //RenderSystem.assertOnRenderThread();
    //    Matrix4f matrix4f = Matrix4f();
    //    matrix4f.setIdentity();
    //    matrix4f.multiply(Matrix4f.createScaleMatrix(1.0f, -1.0f, 1.0f));
    //    matrix4f.multiply(Vector3f.YP.rotationDegrees(-22.5f));
    //    matrix4f.multiply(Vector3f.XP.rotationDegrees(135.0f));
    //    _glsetupLevelDiffuseLighting(vector3f, vector3f2, matrix4f);
    //}
//
    //void _setupGui3DDiffuseLighting(Vector3f vector3f, Vector3f vector3f2) {
    //    //RenderSystem.assertOnRenderThread();
    //    Matrix4f matrix4f = Matrix4f();
    //    matrix4f.setIdentity();
    //    matrix4f.multiply(Vector3f.YP.rotationDegrees(62.0f));
    //    matrix4f.multiply(Vector3f.XP.rotationDegrees(185.5f));
    //    matrix4f.multiply(Vector3f.YP.rotationDegrees(-22.5f));
    //    matrix4f.multiply(Vector3f.XP.rotationDegrees(135.0f));
    //    _glsetupLevelDiffuseLighting(vector3f, vector3f2, matrix4f);
    //}

    void _enableCull() {
        //RenderSystem.assertOnRenderThread();
        glEnable(GL_CULL_FACE);
    }

    void _disableCull() {
        //RenderSystem.assertOnRenderThread();
        glDisable(GL_CULL_FACE);
    }

    void _polygonMode(int n, int n2) {
        //RenderSystem.assertOnRenderThread();
        glPolygonMode((int)n, (int)n2);
    }

    void _enablePolygonOffset() {
        //RenderSystem.assertOnRenderThread();
        glEnable(GL_POLYGON_OFFSET_FILL);
    }

    void _disablePolygonOffset() {
        //RenderSystem.assertOnRenderThread();
        glDisable(GL_POLYGON_OFFSET_FILL);
    }

    void _polygonOffset(float f, float f2) {
        //RenderSystem.assertOnRenderThread();
        glPolygonOffset((float)f, (float)f2);
    }

    void _enableColorLogicOp() {
        //RenderSystem.assertOnRenderThread();
        glEnable(GL_COLOR_LOGIC_OP);//idk wtf is dat shit
    }

    void _disableColorLogicOp() {
        //RenderSystem.assertOnRenderThread();
        glDisable(GL_COLOR_LOGIC_OP);
    }

    void _logicOp(int n) {
        //RenderSystem.assertOnRenderThread();
        glLogicOp((int)n);
    }

    void _activeTexture(int n) {
        //RenderSystem.assertOnRenderThread();
        if (activeTexture != n - 33984) {
            activeTexture = n - 33984;
            glActiveTexture(n);
        }
    }

    void _enableTexture() {
        //RenderSystem.assertOnRenderThreadOrInit();
        TEXTURES[activeTexture].enable = true;
    }

    void _disableTexture() {
        //RenderSystem.assertOnRenderThread();
        TEXTURES[activeTexture].enable = false;
    }

    void _texParameter(int n, int n2, float f) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glTexParameterf((int)n, (int)n2, (float)f);
    }

    void _texParameter(int n, int n2, int n3) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glTexParameteri((int)n, (int)n2, (int)n3);
    }

    int _getTexLevelParameter(int n, int n2, int n3) {
        //RenderSystem.assertInInitPhase();
        int params;
        glGetTexLevelParameteriv((int)n, (int)n2, (int)n3,&params);
        return params;
    }

    unsigned int _genTexture() {
        //RenderSystem.assertOnRenderThreadOrInit();
        unsigned int tex;
        glGenTextures(1,&tex);
        return tex;
    }

    void _genTextures(unsigned int* arrn) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glGenTextures(1,arrn);
    }

    void _deleteTexture(unsigned int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glDeleteTextures(1,&n);
        for (TextureState textureState : TEXTURES) {
            if (textureState.binding != n) continue;
            textureState.binding = -1;
        }
    }

    void _deleteTextures(std::vector<unsigned int> arrn) {
        //RenderSystem.assertOnRenderThreadOrInit();
        for (TextureState textureState : TEXTURES) {
            for (int n : arrn) {
                if (textureState.binding != n) continue;
                textureState.binding = -1;
            }
        }
        glDeleteTextures(arrn.size(),arrn.data());
    }

    void _bindTexture(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        if (n != TEXTURES[activeTexture].binding) {
            TEXTURES[activeTexture].binding = n;
            glBindTexture((int)3553, (int)n);
        }
    }

    int _getTextureId(int n) {
        if (n >= 0 && n < 12 && TEXTURES[n].enable) {
            return TEXTURES[n].binding;
        }
        return 0;
    }

    int _getActiveTexture() {
        return activeTexture + 33984;
    }

    void _texImage2D(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int* intBuffer) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glTexImage2D((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, (int)n7, (int)n8, (int*)intBuffer);
    }

    void _texSubImage2D(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, void* l) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glTexSubImage2D((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, (int)n7, (int)n8,l);
    }

    void _getTexImage(int n, int n2, int n3, int n4, void* l) {
        //RenderSystem.assertOnRenderThread();
        glGetTexImage((int)n, (int)n2, (int)n3, (int)n4,l);
    }

    void _viewport(int n, int n2, int n3, int n4) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glViewport((int)n, (int)n2, (int)n3, (int)n4);
    }

    void _colorMask(bool bl, bool bl2, bool bl3, bool bl4) {
        //RenderSystem.assertOnRenderThread();
        glColorMask((bool)bl, (bool)bl2, (bool)bl3, (bool)bl4);
    }

    void _stencilFunc(int n, int n2, int n3) {
        //RenderSystem.assertOnRenderThread();
        glStencilFunc((int)n, (int)n2, (int)n3);
    }

    void _stencilMask(int n) {
        //RenderSystem.assertOnRenderThread();
            glStencilMask((int)n);
    }

    void _stencilOp(int n, int n2, int n3) {
        //RenderSystem.assertOnRenderThread();
            glStencilOp((int)n, (int)n2, (int)n3);
    }

    void _clearDepth(double d) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glClearDepth((double)d);
    }

    void _clearColor(float f, float f2, float f3, float f4) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glClearColor((float)f, (float)f2, (float)f3, (float)f4);
    }

    void _clearStencil(int n) {
        //RenderSystem.assertOnRenderThread();
        glClearStencil((int)n);
    }

    void _clear(int n, bool bl) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glClear((int)n);
        if (bl) {
            glGetError();
        }
    }

    void _glDrawPixels(int n, int n2, int n3, int n4, void* l) {
        //RenderSystem.assertOnRenderThread();
        glDrawPixels((int)n, (int)n2, (int)n3, (int)n4,l);
    }

    void _vertexAttribPointer(int n, int n2, int n3, bool bl, int n4, const void* l) {
        //RenderSystem.assertOnRenderThread();
        glVertexAttribPointer((int)n, (int)n2, (int)n3, (bool)bl, (int)n4,l);
    }

    void _vertexAttribIPointer(int n, int n2, int n3, int n4, const void* l) {
        //RenderSystem.assertOnRenderThread();
        glVertexAttribIPointer((int)n, (int)n2, (int)n3, (int)n4, l);
    }

    void _enableVertexAttribArray(int n) {
        //RenderSystem.assertOnRenderThread();
        glEnableVertexAttribArray((int)n);
    }

    void _disableVertexAttribArray(int n) {
        //RenderSystem.assertOnRenderThread();
        glDisableVertexAttribArray((int)n);
    }

    void _drawElements(int n, int n2, int n3, void* l) {
        //RenderSystem.assertOnRenderThread();
        glDrawElements((int)n, (int)n2, (int)n3,l);
    }

    void _pixelStore(int n, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glPixelStorei((int)n, (int)n2);
    }

    void _readPixels(int n, int n2, int n3, int n4, int n5, int n6, void* byteBuffer) {
        //RenderSystem.assertOnRenderThread();
        glReadPixels((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, byteBuffer);
    }

    void _readPixels(int n, int n2, int n3, int n4, int n5, int n6, void* l) {
        //RenderSystem.assertOnRenderThread();
        glReadPixels((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, l);
    }

    int _getError() {
        //RenderSystem.assertOnRenderThread();
        return glGetError();
    }

    std::string _getString(int n) {
        //RenderSystem.assertOnRenderThread();
        return std::string((char*)glGetString((n)));
    }

    int _getInteger(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        int n2;
        glGetIntegerv(n,&n2);
        return n2;
    }

    void init()
    {
        COLOR_MASK = ColorMask();
    }