    #include <src/com/mojang/lib3d/lib3d.h>
    #include <memory.h>
    #include <glfw3.h>

    //void lib3d::process(RenderPipeline renderPipeline, float f) {
    //    ConcurrentLinkedQueue<RenderCall> concurrentLinkedQueue = renderPipeline.getRecordingQueue();
    //}
    //void lib3d::render(RenderPipeline renderPipeline, float f) {
    //    ConcurrentLinkedQueue<RenderCall> concurrentLinkedQueue = renderPipeline.getProcessedQueue();
    //}

    void lib3D::IntentionalCrash()
    {
        memset((long)0L, (int)0, (long)1L);
    }

    double lib3D::getTime()
    {
        return glfwGetTime();
    }
    
    