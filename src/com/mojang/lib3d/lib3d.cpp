    #include <src/com/mojang/lib3d/lib3d.h>
    #include <memory.h>
    #include <GLFW/glfw3.h>

    //void lib3d::process(RenderPipeline renderPipeline, float f) {
    //    ConcurrentLinkedQueue<RenderCall> concurrentLinkedQueue = renderPipeline.getRecordingQueue();
    //}
    //void lib3d::render(RenderPipeline renderPipeline, float f) {
    //    ConcurrentLinkedQueue<RenderCall> concurrentLinkedQueue = renderPipeline.getProcessedQueue();
    //}

    void lib3D::IntentionalCrash()
    {
        memset(0, 0, 1L);
    }

    double lib3D::getTime()
    {
        return glfwGetTime();
    }
    
    