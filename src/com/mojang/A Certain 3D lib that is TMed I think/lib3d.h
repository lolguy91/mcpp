#ifndef __3DLIB_H__
#define __3DLIB_H__
#include <memory.h>

class lib3D {
    //void process(RenderPipeline renderPipeline, float f) {
    //    ConcurrentLinkedQueue<RenderCall> concurrentLinkedQueue = renderPipeline.getRecordingQueue();
    //}
    //void render(RenderPipeline renderPipeline, float f) {
    //    ConcurrentLinkedQueue<RenderCall> concurrentLinkedQueue = renderPipeline.getProcessedQueue();
    //}

    void IntentionalCrash() {
        memset((long)0L, (int)0, (long)1L);
    }

    double getTime() {
    //    return GLFW.glfwGetTime();
    }
};
#endif // __3DLIB_H__