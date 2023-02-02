/*
import com.google.common.base.Charsets;
import com.mojang.blaze3d.systems.RenderSystem;
import com.mojang.math.Matrix4f;
import com.mojang.math.Vector3f;
import com.mojang.math.Vector4f;
import net.minecraft.Util;
*/
#include <src/com/mojang/math/Matrix4f.h>
#include <src/com/mojang/math/Vector3f.h>
#include <src/com/mojang/math/Vector4f.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
	struct Viewport{
        int x;
        int y;
        int width;
        int height;
    }

	struct TextureState {
        bool enable;
        int binding;
    }

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

    int _glGetProgrami(int n, int n2) {
        //RenderSystem.assertOnRenderThread();
        return glGetProgrami((int)n, (int)n2);
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

    /*
     * WARNING - Removed try catching itself - possible behaviour change.
     */
    void _glShaderSource(int n, std::string source) {
        //RenderSystem.assertOnRenderThread();
            glShaderSource(n,1, source.c_str(), source.size);
        
    }

    void _glCompileShader(int n) {
        //RenderSystem.assertOnRenderThread();
        glCompileShader((int)n);
    }

    int _glGetShaderi(int n, int n2) {
        //RenderSystem.assertOnRenderThread();
        return glGetShaderi((int)n, (int)n2);
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

    int _glGetUniformLocation(int n, CharSequence charSequence) {
        //RenderSystem.assertOnRenderThread();
        return glGetUniformLocation((int)n, (CharSequence)charSequence);
    }

    void _glUniform1(int n, IntBuffer intBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform1iv((int)n, (IntBuffer)intBuffer);
    }

    void _glUniform1i(int n, int n2) {
        //RenderSystem.assertOnRenderThread();
        glUniform1i((int)n, (int)n2);
    }

    void _glUniform1(int n, FloatBuffer floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform1fv((int)n, (FloatBuffer)floatBuffer);
    }

    void _glUniform2(int n, IntBuffer intBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform2iv((int)n, (IntBuffer)intBuffer);
    }

    void _glUniform2(int n, FloatBuffer floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform2fv((int)n, (FloatBuffer)floatBuffer);
    }

    void _glUniform3(int n, IntBuffer intBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform3iv((int)n, (IntBuffer)intBuffer);
    }

    void _glUniform3(int n, FloatBuffer floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform3fv((int)n, (FloatBuffer)floatBuffer);
    }

    void _glUniform4(int n, IntBuffer intBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform4iv((int)n, (IntBuffer)intBuffer);
    }

    void _glUniform4(int n, FloatBuffer floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniform4fv((int)n, (FloatBuffer)floatBuffer);
    }

    void _glUniformMatrix2(int n, bool bl, FloatBuffer floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniformMatrix2fv((int)n, (bool)bl, (FloatBuffer)floatBuffer);
    }

    void _glUniformMatrix3(int n, bool bl, FloatBuffer floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniformMatrix3fv((int)n, (bool)bl, (FloatBuffer)floatBuffer);
    }

    void _glUniformMatrix4(int n, bool bl, FloatBuffer floatBuffer) {
        //RenderSystem.assertOnRenderThread();
        glUniformMatrix4fv((int)n, (bool)bl, (FloatBuffer)floatBuffer);
    }

    int _glGetAttribLocation(int n, CharSequence charSequence) {
        //RenderSystem.assertOnRenderThread();
        return glGetAttribLocation((int)n, (CharSequence)charSequence);
    }

    void _glBindAttribLocation(int n, int n2, CharSequence charSequence) {
        //RenderSystem.assertOnRenderThread();
        glBindAttribLocation((int)n, (int)n2, (CharSequence)charSequence);
    }

    int _glGenBuffers() {
        //RenderSystem.assertOnRenderThreadOrInit();
        return GL15.glGenBuffers();
    }

    int _glGenVertexArrays() {
        //RenderSystem.assertOnRenderThreadOrInit();
        return GL30.glGenVertexArrays();
    }

    void _glBindBuffer(int n, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL15.glBindBuffer((int)n, (int)n2);
    }

    void _glBindVertexArray(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL30.glBindVertexArray((int)n);
    }

    void _glBufferData(int n, ByteBuffer byteBuffer, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL15.glBufferData((int)n, (ByteBuffer)byteBuffer, (int)n2);
    }

    void _glBufferData(int n, long l, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL15.glBufferData((int)n, (long)l, (int)n2);
    }

    @Nullable
    ByteBuffer _glMapBuffer(int n, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        return GL15.glMapBuffer((int)n, (int)n2);
    }

    void _glUnmapBuffer(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL15.glUnmapBuffer((int)n);
    }

    void _glDeleteBuffers(int n) {
        //RenderSystem.assertOnRenderThread();
        if (ON_LINUX) {
            GL32C.glBindBuffer((int)34962, (int)n);
            GL32C.glBufferData((int)34962, (long)0L, (int)35048);
            GL32C.glBindBuffer((int)34962, (int)0);
        }
        GL15.glDeleteBuffers((int)n);
    }

    void _glCopyTexSubImage2D(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glCopyTexSubImage2D((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, (int)n7, (int)n8);
    }

    void _glDeleteVertexArrays(int n) {
        //RenderSystem.assertOnRenderThread();
        GL30.glDeleteVertexArrays((int)n);
    }

    void _glBindFramebuffer(int n, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL30.glBindFramebuffer((int)n, (int)n2);
    }

    void _glBlitFrameBuffer(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL30.glBlitFramebuffer((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, (int)n7, (int)n8, (int)n9, (int)n10);
    }

    void _glBindRenderbuffer(int n, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL30.glBindRenderbuffer((int)n, (int)n2);
    }

    void _glDeleteRenderbuffers(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL30.glDeleteRenderbuffers((int)n);
    }

    void _glDeleteFramebuffers(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL30.glDeleteFramebuffers((int)n);
    }

    int _glGenFramebuffers() {
        //RenderSystem.assertOnRenderThreadOrInit();
        return GL30.glGenFramebuffers();
    }

    int _glGenRenderbuffers() {
        //RenderSystem.assertOnRenderThreadOrInit();
        return GL30.glGenRenderbuffers();
    }

    void _glRenderbufferStorage(int n, int n2, int n3, int n4) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL30.glRenderbufferStorage((int)n, (int)n2, (int)n3, (int)n4);
    }

    void _glFramebufferRenderbuffer(int n, int n2, int n3, int n4) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL30.glFramebufferRenderbuffer((int)n, (int)n2, (int)n3, (int)n4);
    }

    int _glCheckFramebufferStatus(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        return GL30.glCheckFramebufferStatus((int)n);
    }

    void _glFramebufferTexture2D(int n, int n2, int n3, int n4, int n5) {
        //RenderSystem.assertOnRenderThreadOrInit();
        GL30.glFramebufferTexture2D((int)n, (int)n2, (int)n3, (int)n4, (int)n5);
    }

    int _getBoundFramebuffer() {
        //RenderSystem.assertOnRenderThread();
        return _gl_getInteger(36006);
    }

    void _glActiveTexture(int n) {
        //RenderSystem.assertOnRenderThread();
        GL13.glActiveTexture((int)n);
    }

    String _glGetShaderInfoLog(int n, int n2) {
        //RenderSystem.assertOnRenderThread();
        return glGetShaderInfoLog((int)n, (int)n2);
    }

    String _glGetProgramInfoLog(int n, int n2) {
        //RenderSystem.assertOnRenderThread();
        return glGetProgramInfoLog((int)n, (int)n2);
    }

    void _setupLevelDiffuseLighting(Vector3f vector3f, Vector3f vector3f2, Matrix4f matrix4f) {
        //RenderSystem.assertOnRenderThread();
        Vector4f vector4f = new Vector4f(vector3f);
        vector4f.transform(matrix4f);
        Vector4f vector4f2 = new Vector4f(vector3f2);
        vector4f2.transform(matrix4f);
        RenderSystem.setShaderLights(new Vector3f(vector4f), new Vector3f(vector4f2));
    }

    void _setupGuiFlatDiffuseLighting(Vector3f vector3f, Vector3f vector3f2) {
        //RenderSystem.assertOnRenderThread();
        Matrix4f matrix4f = new Matrix4f();
        matrix4f.setIdentity();
        matrix4f.multiply(Matrix4f.createScaleMatrix(1.0f, -1.0f, 1.0f));
        matrix4f.multiply(Vector3f.YP.rotationDegrees(-22.5f));
        matrix4f.multiply(Vector3f.XP.rotationDegrees(135.0f));
        _glsetupLevelDiffuseLighting(vector3f, vector3f2, matrix4f);
    }

    void _setupGui3DDiffuseLighting(Vector3f vector3f, Vector3f vector3f2) {
        //RenderSystem.assertOnRenderThread();
        Matrix4f matrix4f = new Matrix4f();
        matrix4f.setIdentity();
        matrix4f.multiply(Vector3f.YP.rotationDegrees(62.0f));
        matrix4f.multiply(Vector3f.XP.rotationDegrees(185.5f));
        matrix4f.multiply(Vector3f.YP.rotationDegrees(-22.5f));
        matrix4f.multiply(Vector3f.XP.rotationDegrees(135.0f));
        _glsetupLevelDiffuseLighting(vector3f, vector3f2, matrix4f);
    }

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
        _glPOLY_OFFSET.fill.enable();
    }

    void _disablePolygonOffset() {
        //RenderSystem.assertOnRenderThread();
        _glPOLY_OFFSET.fill.disable();
    }

    void _polygonOffset(float f, float f2) {
        //RenderSystem.assertOnRenderThread();
        if (f != _glPOLY_OFFSET.factor || f2 != _glPOLY_OFFSET.units) {
            _glPOLY_OFFSET.factor = f;
            _glPOLY_OFFSET.units = f2;
            glPolygonOffset((float)f, (float)f2);
        }
    }

    void _enableColorLogicOp() {
        //RenderSystem.assertOnRenderThread();
        glEnable(3058);//idk wtf is dat shit
    }

    void _disableColorLogicOp() {
        //RenderSystem.assertOnRenderThread();
        glDisable(3058);//idk wtf is dat shit
    }

    void _logicOp(int n) {
        //RenderSystem.assertOnRenderThread();
        if (n != _glCOLOR_LOGIC.op) {
            _glCOLOR_LOGIC.op = n;
            glLogicOp((int)n);
        }
    }

    void _activeTexture(int n) {
        //RenderSystem.assertOnRenderThread();
        if (activeTexture != n - 33984) {
            activeTexture = n - 33984;
            _glglActiveTexture(n);
        }
    }

    void _enableTexture() {
        //RenderSystem.assertOnRenderThreadOrInit();
        _glTEXTURES[_glactiveTexture].enable = true;
    }

    void _disableTexture() {
        //RenderSystem.assertOnRenderThread();
        _glTEXTURES[_glactiveTexture].enable = false;
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
        RenderSystem.assertInInitPhase();
        return glGetTexLevelParameteri((int)n, (int)n2, (int)n3);
    }

    int _genTexture() {
        //RenderSystem.assertOnRenderThreadOrInit();
        return glGenTextures();
    }

    void _genTextures(int[] arrn) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glGenTextures((int[])arrn);
    }

    void _deleteTexture(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glDeleteTextures((int)n);
        for (TextureState textureState : TEXTURES) {
            if (textureState.binding != n) continue;
            textureState.binding = -1;
        }
    }

    void _deleteTextures(int[] arrn) {
        //RenderSystem.assertOnRenderThreadOrInit();
        for (TextureState textureState : TEXTURES) {
            for (int n : arrn) {
                if (textureState.binding != n) continue;
                textureState.binding = -1;
            }
        }
        glDeleteTextures((int[])arrn);
    }

    void _bindTexture(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        if (n != _glTEXTURES[_glactiveTexture].binding) {
            _glTEXTURES[_glactiveTexture].binding = n;
            glBindTexture((int)3553, (int)n);
        }
    }

    int _getTextureId(int n) {
        if (n >= 0 && n < 12 && _glTEXTURES[n].enable) {
            return _glTEXTURES[n].binding;
        }
        return 0;
    }

    int _getActiveTexture() {
        return activeTexture + 33984;
    }

    void _texImage2D(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, @Nullable IntBuffer intBuffer) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glTexImage2D((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, (int)n7, (int)n8, (IntBuffer)intBuffer);
    }

    void _texSubImage2D(int n, int n2, int n3, int n4, int n5, int n6, int n7, int n8, long l) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glTexSubImage2D((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, (int)n7, (int)n8, (long)l);
    }

    void _getTexImage(int n, int n2, int n3, int n4, long l) {
        //RenderSystem.assertOnRenderThread();
        glGetTexImage((int)n, (int)n2, (int)n3, (int)n4, (long)l);
    }

    void _viewport(int n, int n2, int n3, int n4) {
        //RenderSystem.assertOnRenderThreadOrInit();
        Viewport.INSTANCE.x = n;
        Viewport.INSTANCE.y = n2;
        Viewport.INSTANCE.width = n3;
        Viewport.INSTANCE.height = n4;
        glViewport((int)n, (int)n2, (int)n3, (int)n4);
    }

    void _colorMask(bool bl, bool bl2, bool bl3, bool bl4) {
        //RenderSystem.assertOnRenderThread();
        if (bl != _glCOLOR_MASK.red || bl2 != _glCOLOR_MASK.green || bl3 != _glCOLOR_MASK.blue || bl4 != _glCOLOR_MASK.alpha) {
            _glCOLOR_MASK.red = bl;
            _glCOLOR_MASK.green = bl2;
            _glCOLOR_MASK.blue = bl3;
            _glCOLOR_MASK.alpha = bl4;
            glColorMask((bool)bl, (bool)bl2, (bool)bl3, (bool)bl4);
        }
    }

    void _stencilFunc(int n, int n2, int n3) {
        //RenderSystem.assertOnRenderThread();
        if (n != _glSTENCIL.func.func || n != _glSTENCIL.func.ref || n != _glSTENCIL.func.mask) {
            _glSTENCIL.func.func = n;
            _glSTENCIL.func.ref = n2;
            _glSTENCIL.func.mask = n3;
            glStencilFunc((int)n, (int)n2, (int)n3);
        }
    }

    void _stencilMask(int n) {
        //RenderSystem.assertOnRenderThread();
        if (n != _glSTENCIL.mask) {
            _glSTENCIL.mask = n;
            glStencilMask((int)n);
        }
    }

    void _stencilOp(int n, int n2, int n3) {
        //RenderSystem.assertOnRenderThread();
        if (n != _glSTENCIL.fail || n2 != _glSTENCIL.zfail || n3 != _glSTENCIL.zpass) {
            _glSTENCIL.fail = n;
            _glSTENCIL.zfail = n2;
            _glSTENCIL.zpass = n3;
            glStencilOp((int)n, (int)n2, (int)n3);
        }
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
            _gl_getError();
        }
    }

    void _glDrawPixels(int n, int n2, int n3, int n4, long l) {
        //RenderSystem.assertOnRenderThread();
        glDrawPixels((int)n, (int)n2, (int)n3, (int)n4, (long)l);
    }

    void _vertexAttribPointer(int n, int n2, int n3, bool bl, int n4, long l) {
        //RenderSystem.assertOnRenderThread();
        glVertexAttribPointer((int)n, (int)n2, (int)n3, (bool)bl, (int)n4, (long)l);
    }

    void _vertexAttribIPointer(int n, int n2, int n3, int n4, long l) {
        //RenderSystem.assertOnRenderThread();
        GL30.glVertexAttribIPointer((int)n, (int)n2, (int)n3, (int)n4, (long)l);
    }

    void _enableVertexAttribArray(int n) {
        //RenderSystem.assertOnRenderThread();
        glEnableVertexAttribArray((int)n);
    }

    void _disableVertexAttribArray(int n) {
        //RenderSystem.assertOnRenderThread();
        glDisableVertexAttribArray((int)n);
    }

    void _drawElements(int n, int n2, int n3, long l) {
        //RenderSystem.assertOnRenderThread();
        glDrawElements((int)n, (int)n2, (int)n3, (long)l);
    }

    void _pixelStore(int n, int n2) {
        //RenderSystem.assertOnRenderThreadOrInit();
        glPixelStorei((int)n, (int)n2);
    }

    void _readPixels(int n, int n2, int n3, int n4, int n5, int n6, ByteBuffer byteBuffer) {
        //RenderSystem.assertOnRenderThread();
        glReadPixels((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, (ByteBuffer)byteBuffer);
    }

    void _readPixels(int n, int n2, int n3, int n4, int n5, int n6, long l) {
        //RenderSystem.assertOnRenderThread();
        glReadPixels((int)n, (int)n2, (int)n3, (int)n4, (int)n5, (int)n6, (long)l);
    }

    int _getError() {
        //RenderSystem.assertOnRenderThread();
        return glGetError();
    }

    String _getString(int n) {
        //RenderSystem.assertOnRenderThread();
        return glGetString((int)n);
    }

    int _getInteger(int n) {
        //RenderSystem.assertOnRenderThreadOrInit();
        return glGetInteger((int)n);
    }

    {
        TEXTURES = (TextureState[])IntStream.range(0, 12).mapToObj(n -> new TextureState()).toArray(TextureState[]::new);
        COLOR_MASK = new ColorMask();
    }

    class ColorMask {
        bool red = true;
        bool green = true;
        bool blue = true;
        bool alpha = true;

        ColorMask() {
        }
    }

    class StencilState {
        StencilFunc func = new StencilFunc();
        int mask = -1;
        int fail = 7680;
        int zfail = 7680;
        int zpass = 7680;

        StencilState() {
        }
    }

    class StencilFunc {
        int func = 519;
        int ref;
        int mask = -1;

        StencilFunc() {
        }
    }

    @DontObfuscate
    class DestFactor
    extends Enum<DestFactor> {
        final /* enum */ DestFactor CONSTANT_ALPHA = new DestFactor(32771);
        final /* enum */ DestFactor CONSTANT_COLOR = new DestFactor(32769);
        final /* enum */ DestFactor DST_ALPHA = new DestFactor(772);
        final /* enum */ DestFactor DST_COLOR = new DestFactor(774);
        final /* enum */ DestFactor ONE = new DestFactor(1);
        final /* enum */ DestFactor ONE_MINUS_CONSTANT_ALPHA = new DestFactor(32772);
        final /* enum */ DestFactor ONE_MINUS_CONSTANT_COLOR = new DestFactor(32770);
        final /* enum */ DestFactor ONE_MINUS_DST_ALPHA = new DestFactor(773);
        final /* enum */ DestFactor ONE_MINUS_DST_COLOR = new DestFactor(775);
        final /* enum */ DestFactor ONE_MINUS_SRC_ALPHA = new DestFactor(771);
        final /* enum */ DestFactor ONE_MINUS_SRC_COLOR = new DestFactor(769);
        final /* enum */ DestFactor SRC_ALPHA = new DestFactor(770);
        final /* enum */ DestFactor SRC_COLOR = new DestFactor(768);
        final /* enum */ DestFactor ZERO = new DestFactor(0);
        int value;
        final /* synthetic */ DestFactor[] $VALUES;

        DestFactor[] values() {
            return (DestFactor[])$VALUES.clone();
        }

        DestFactor valueOf(String string) {
            return Enum.valueOf(DestFactor.class, string);
        }

        DestFactor(int n2) {
            this.value = n2;
        }

        /* synthetic */ DestFactor[] $values() {
            return new DestFactor[]{CONSTANT_ALPHA, CONSTANT_COLOR, DST_ALPHA, DST_COLOR, ONE, ONE_MINUS_CONSTANT_ALPHA, ONE_MINUS_CONSTANT_COLOR, ONE_MINUS_DST_ALPHA, ONE_MINUS_DST_COLOR, ONE_MINUS_SRC_ALPHA, ONE_MINUS_SRC_COLOR, SRC_ALPHA, SRC_COLOR, ZERO};
        }

        {
            $VALUES = DestFactor.$values();
        }
    }

    @DontObfuscate
    class SourceFactor
    extends Enum<SourceFactor> {
        final /* enum */ SourceFactor CONSTANT_ALPHA = new SourceFactor(32771);
        final /* enum */ SourceFactor CONSTANT_COLOR = new SourceFactor(32769);
        final /* enum */ SourceFactor DST_ALPHA = new SourceFactor(772);
        final /* enum */ SourceFactor DST_COLOR = new SourceFactor(774);
        final /* enum */ SourceFactor ONE = new SourceFactor(1);
        final /* enum */ SourceFactor ONE_MINUS_CONSTANT_ALPHA = new SourceFactor(32772);
        final /* enum */ SourceFactor ONE_MINUS_CONSTANT_COLOR = new SourceFactor(32770);
        final /* enum */ SourceFactor ONE_MINUS_DST_ALPHA = new SourceFactor(773);
        final /* enum */ SourceFactor ONE_MINUS_DST_COLOR = new SourceFactor(775);
        final /* enum */ SourceFactor ONE_MINUS_SRC_ALPHA = new SourceFactor(771);
        final /* enum */ SourceFactor ONE_MINUS_SRC_COLOR = new SourceFactor(769);
        final /* enum */ SourceFactor SRC_ALPHA = new SourceFactor(770);
        final /* enum */ SourceFactor SRC_ALPHA_SATURATE = new SourceFactor(776);
        final /* enum */ SourceFactor SRC_COLOR = new SourceFactor(768);
        final /* enum */ SourceFactor ZERO = new SourceFactor(0);
        int value;
        final /* synthetic */ SourceFactor[] $VALUES;

        SourceFactor[] values() {
            return (SourceFactor[])$VALUES.clone();
        }

        SourceFactor valueOf(String string) {
            return Enum.valueOf(SourceFactor.class, string);
        }

        SourceFactor(int n2) {
            this.value = n2;
        }

        /* synthetic */ SourceFactor[] $values() {
            return new SourceFactor[]{CONSTANT_ALPHA, CONSTANT_COLOR, DST_ALPHA, DST_COLOR, ONE, ONE_MINUS_CONSTANT_ALPHA, ONE_MINUS_CONSTANT_COLOR, ONE_MINUS_DST_ALPHA, ONE_MINUS_DST_COLOR, ONE_MINUS_SRC_ALPHA, ONE_MINUS_SRC_COLOR, SRC_ALPHA, SRC_ALPHA_SATURATE, SRC_COLOR, ZERO};
        }

        {
            $VALUES = SourceFactor.$values();
        }
    }

    class LogicOp
    extends Enum<LogicOp> {
        final /* enum */ LogicOp AND = new LogicOp(5377);
        final /* enum */ LogicOp AND_INVERTED = new LogicOp(5380);
        final /* enum */ LogicOp AND_REVERSE = new LogicOp(5378);
        final /* enum */ LogicOp CLEAR = new LogicOp(5376);
        final /* enum */ LogicOp COPY = new LogicOp(5379);
        final /* enum */ LogicOp COPY_INVERTED = new LogicOp(5388);
        final /* enum */ LogicOp EQUIV = new LogicOp(5385);
        final /* enum */ LogicOp INVERT = new LogicOp(5386);
        final /* enum */ LogicOp NAND = new LogicOp(5390);
        final /* enum */ LogicOp NOOP = new LogicOp(5381);
        final /* enum */ LogicOp NOR = new LogicOp(5384);
        final /* enum */ LogicOp OR = new LogicOp(5383);
        final /* enum */ LogicOp OR_INVERTED = new LogicOp(5389);
        final /* enum */ LogicOp OR_REVERSE = new LogicOp(5387);
        final /* enum */ LogicOp SET = new LogicOp(5391);
        final /* enum */ LogicOp XOR = new LogicOp(5382);
        int value;
        final /* synthetic */ LogicOp[] $VALUES;

        LogicOp[] values() {
            return (LogicOp[])$VALUES.clone();
        }

        LogicOp valueOf(String string) {
            return Enum.valueOf(LogicOp.class, string);
        }

        LogicOp(int n2) {
            this.value = n2;
        }

        /* synthetic */ LogicOp[] $values() {
            return new LogicOp[]{AND, AND_INVERTED, AND_REVERSE, CLEAR, COPY, COPY_INVERTED, EQUIV, INVERT, NAND, NOOP, NOR, OR, OR_INVERTED, OR_REVERSE, SET, XOR};
        }

        {
            $VALUES = LogicOp.$values();
        }
    }