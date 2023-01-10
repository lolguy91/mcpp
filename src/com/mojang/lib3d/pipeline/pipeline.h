#ifndef __PIPELINE_H__
#define __PIPELINE_H__
#include <queue>
#include <array>

class Call{
    void execute();
};

class Pipeline {
    std::array<std::queue<Call>,4> renderCalls;
    bool isRecording;
    int recordingBuffer = processedBuffer = renderingBuffer + 1;
    bool isProcessing;
    int processedBuffer;
    int renderingBuffer;

    bool canBeginRecording();

    bool beginRecording();

    void recordRenderCall(Call renderCall);

    void endRecording();

    bool canBeginProcessing();

    bool beginProcessing();

    void processRecordedQueue();

    void endProcessing();

    std::queue<Call> startRendering();

    std::queue<Call> getRecordingQueue();

    std::queue<Call> getProcessedQueue();
};


#endif // __PIPELINE_H__