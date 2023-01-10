//!! this file is not getting ported until all the dependencies get ported !!!

#ifndef __TARGET_H__
#define __TARGET_H__
   
#define RED_CHANNEL   0
#define GREEN_CHANNEL 1
#define BLUE_CHANNEL  2
#define ALPHA_CHANNEL 3

class Target {
    public:
    int Width;
    int Height;

    int ViewWidth;
    int ViewHeight;

    bool Depth;

    int FrameBufferId;
    int DepthBufferId;
    int FolorTextureId;

    
    float ClearChannels[] = {1.0, 1.0, 1.0, 0.0};
    int FilterMode;

    Target(bool bl) {
        useDepth = bl;
        frameBufferId = -1;
        colorTextureId = -1;
        depthBufferId = -1;
    }

    //public void resize(int n, int n2, bool bl) {
    //    if (!RenderSystem.isOnRenderThread()) {
    //        RenderSystem.recordRenderCall(() -> _resize(n, n2, bl));
    //    } else {
    //        _resize(n, n2, bl);
    //    }
    //}

    //private void _resize(int n, int n2, bool bl) {
    //    RenderSystem.assertOnRenderThreadOrInit();
    //    GlStateManager._enableDepthTest();
    //    if (frameBufferId >= 0) {
    //        destroyBuffers();
    //    }
    //    createBuffers(n, n2, bl);
    //    GlStateManager._glBindFramebuffer(36160, 0);
    //}

    //void destroyBuffers() {
    //    RenderSystem.assertOnRenderThreadOrInit();
    //    unbindRead();
    //    unbindWrite();
    //    if (depthBufferId > -1) {
    //        TextureUtil.releaseTextureId(depthBufferId);
    //        depthBufferId = -1;
    //    }
    //    if (colorTextureId > -1) {
    //        TextureUtil.releaseTextureId(colorTextureId);
    //        colorTextureId = -1;
    //    }
    //    if (frameBufferId > -1) {
    //        GlStateManager._glBindFramebuffer(36160, 0);
    //        GlStateManager._glDeleteFramebuffers(frameBufferId);
    //        frameBufferId = -1;
    //    }
    //}

    //public void copyDepthFrom(Target Target) {
    //    RenderSystem.assertOnRenderThreadOrInit();
    //    GlStateManager._glBindFramebuffer(36008, Target.frameBufferId);
    //    GlStateManager._glBindFramebuffer(36009, frameBufferId);
    //    GlStateManager._glBlitFrameBuffer(0, 0, Target.width, Target.height, 0, 0, width, height, 256, 9728);
    //    GlStateManager._glBindFramebuffer(36160, 0);
    //}

    //public void createBuffers(int n, int n2, bool bl) {
    //    RenderSystem.assertOnRenderThreadOrInit();
    //    int n3 = RenderSystem.maxSupportedTextureSize();
    //    if (n <= 0 || n > n3 || n2 <= 0 || n2 > n3) {
    //        throw new IllegalArgumentException("Window " + n + "x" + n2 + " size out of bounds (max. size: " + n3 + ")");
    //    }
    //    viewWidth = n;
    //    viewHeight = n2;
    //    width = n;
    //    height = n2;
    //    frameBufferId = GlStateManager.glGenFramebuffers();
    //    colorTextureId = TextureUtil.generateTextureId();
    //    if (useDepth) {
    //        depthBufferId = TextureUtil.generateTextureId();
    //        GlStateManager._bindTexture(depthBufferId);
    //        GlStateManager._texParameter(3553, 10241, 9728);
    //        GlStateManager._texParameter(3553, 10240, 9728);
    //        GlStateManager._texParameter(3553, 34892, 0);
    //        GlStateManager._texParameter(3553, 10242, 33071);
    //        GlStateManager._texParameter(3553, 10243, 33071);
    //        GlStateManager._texImage2D(3553, 0, 6402, width, height, 0, 6402, 5126, null);
    //    }
    //    setFilterMode(9728);
    //    GlStateManager._bindTexture(colorTextureId);
    //    GlStateManager._texParameter(3553, 10242, 33071);
    //    GlStateManager._texParameter(3553, 10243, 33071);
    //    GlStateManager._texImage2D(3553, 0, 32856, width, height, 0, 6408, 5121, null);
    //    GlStateManager._glBindFramebuffer(36160, frameBufferId);
    //    GlStateManager._glFramebufferTexture2D(36160, 36064, 3553, colorTextureId, 0);
    //    if (useDepth) {
    //        GlStateManager._glFramebufferTexture2D(36160, 36096, 3553, depthBufferId, 0);
    //    }
    //    checkStatus();
    //    clear(bl);
    //    unbindRead();
    //}

   // public void setFilterMode(int n) {
   //     RenderSystem.assertOnRenderThreadOrInit();
   //     filterMode = n;
   //     GlStateManager._bindTexture(colorTextureId);
   //     GlStateManager._texParameter(3553, 10241, n);
   //     GlStateManager._texParameter(3553, 10240, n);
   //     GlStateManager._bindTexture(0);
   // }

    //public void checkStatus() {
    //    RenderSystem.assertOnRenderThreadOrInit();
    //    int n = GlStateManager.glCheckFramebufferStatus(36160);
    //    if (n == 36053) {
    //        return;
    //    }
    //    if (n == 36054) {
    //        throw new RuntimeException("GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT");
    //    }
    //    if (n == 36055) {
    //        throw new RuntimeException("GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT");
    //    }
    //    if (n == 36059) {
    //        throw new RuntimeException("GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER");
    //    }
    //    if (n == 36060) {
    //        throw new RuntimeException("GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER");
    //    }
    //    if (n == 36061) {
    //        throw new RuntimeException("GL_FRAMEBUFFER_UNSUPPORTED");
    //    }
    //    if (n == 1285) {
    //        throw new RuntimeException("GL_OUT_OF_MEMORY");
    //    }
    //    throw new RuntimeException("glCheckFramebufferStatus returned unknown status:" + n);
    //}

    //public void bindRead() {
    //    RenderSystem.assertOnRenderThread();
    //    GlStateManager._bindTexture(colorTextureId);
   // }

    //public void unbindRead() {
    //    RenderSystem.assertOnRenderThreadOrInit();
    //    GlStateManager._bindTexture(0);
    //}

    //public void bindWrite(bool bl) {
    //    if (!RenderSystem.isOnRenderThread()) {
    //        RenderSystem.recordRenderCall(() -> _bindWrite(bl));
    //    } else {
    //        _bindWrite(bl);
    //    }
    //}

    //private void _bindWrite(bool bl) {
    //    RenderSystem.assertOnRenderThreadOrInit();
    //    GlStateManager._glBindFramebuffer(36160, frameBufferId);
    //    if (bl) {
    //        GlStateManager._viewport(0, 0, viewWidth, viewHeight);
    //    }
    //}

    //public void unbindWrite() {
    //    if (!RenderSystem.isOnRenderThread()) {
    //        RenderSystem.recordRenderCall(() -> GlStateManager._glBindFramebuffer(36160, 0));
    //    } else {
    //        GlStateManager._glBindFramebuffer(36160, 0);
    //    }
    //}

    //public void setClearColor(float f, float f2, float f3, float f4) {
    //    clearChannels[0] = f;
    //    clearChannels[1] = f2;
    //    clearChannels[2] = f3;
    //    clearChannels[3] = f4;
    //}

    //public void blitToScreen(int n, int n2) {
    //    blitToScreen(n, n2, true);
    //}

    //public void blitToScreen(int n, int n2, bool bl) {
    //    RenderSystem.assertOnGameThreadOrInit();
    //    if (!RenderSystem.isInInitPhase()) {
    //        RenderSystem.recordRenderCall(() -> _blitToScreen(n, n2, bl));
    //    } else {
    //        _blitToScreen(n, n2, bl);
    //    }
    //}

    //private void _blitToScreen(int n, int n2, bool bl) {
    //    RenderSystem.assertOnRenderThread();
    //    GlStateManager._colorMask(true, true, true, false);
    //    GlStateManager._disableDepthTest();
    //    GlStateManager._depthMask(false);
    //    GlStateManager._viewport(0, 0, n, n2);
    //    if (bl) {
    //        GlStateManager._disableBlend();
    //    }
    //    Minecraft minecraft = Minecraft.getInstance();
    //    ShaderInstance shaderInstance = minecraft.gameRenderer.blitShader;
    //    shaderInstance.setSampler("DiffuseSampler", colorTextureId);
    //    Matrix4f matrix4f = Matrix4f.orthographic(n, -n2, 1000.0f, 3000.0f);
    //    RenderSystem.setProjectionMatrix(matrix4f);
    //    if (shaderInstance.MODEL_VIEW_MATRIX != null) {
    //        shaderInstance.MODEL_VIEW_MATRIX.set(Matrix4f.createTranslateMatrix(0.0f, 0.0f, -2000.0f));
    //    }
    //    if (shaderInstance.PROJECTION_MATRIX != null) {
    //        shaderInstance.PROJECTION_MATRIX.set(matrix4f);
    //    }
    //    shaderInstance.apply();
    //    float f = n;
    //    float f2 = n2;
    //    float f3 = (float)viewWidth / (float)width;
    //    float f4 = (float)viewHeight / (float)height;
    //    Tesselator tesselator = RenderSystem.renderThreadTesselator();
    //    BufferBuilder bufferBuilder = tesselator.getBuilder();
    //    bufferBuilder.begin(VertexFormat.Mode.QUADS, DefaultVertexFormat.POSITION_TEX_COLOR);
    //    bufferBuilder.vertex(0.0, f2, 0.0).uv(0.0f, 0.0f).color(255, 255, 255, 255).endVertex();
    //    bufferBuilder.vertex(f, f2, 0.0).uv(f3, 0.0f).color(255, 255, 255, 255).endVertex();
    //    bufferBuilder.vertex(f, 0.0, 0.0).uv(f3, f4).color(255, 255, 255, 255).endVertex();
    //    bufferBuilder.vertex(0.0, 0.0, 0.0).uv(0.0f, f4).color(255, 255, 255, 255).endVertex();
    //    BufferUploader.draw(bufferBuilder.end());
    //    shaderInstance.clear();
    //    GlStateManager._depthMask(true);
    //    GlStateManager._colorMask(true, true, true, true);
    //}

    //public void clear(bool bl) {
    //    RenderSystem.assertOnRenderThreadOrInit();
    //    bindWrite(true);
    //    GlStateManager._clearColor(clearChannels[0], clearChannels[1], clearChannels[2], clearChannels[3]);
    //    int n = 16384;
    //    if (useDepth) {
    //        GlStateManager._clearDepth(1.0);
    //        n |= 0x100;
    //    }
    //    GlStateManager._clear(n, bl);
    //    unbindWrite();
    //}

    int getColorTextureId() {
        return colorTextureId;
    }

    int getDepthTextureId() {
        return depthBufferId;
    }
}


#endif // __TARGET_H__