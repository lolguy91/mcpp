#include <src/com/mojang/lib3d/pipeline/pipeline.h>

    bool Pipeline::canBeginRecording() {
        return !isRecording && recordingBuffer == processedBuffer;
    }

    bool Pipeline::beginRecording() {
        if (isRecording) {
            __glibcxx_assert(true);
        }
        if (canBeginRecording()) {
            recordingBuffer = (processedBuffer + 1) % renderCalls.size();
            isRecording = true;
            return true;
        }
        return false;
    }

    void Pipeline::recordRenderCall(Call renderCall) {
        if (!isRecording) {
            __glibcxx_assert(true);
        }
        std::queue<Call> callQueue = getRecordingQueue();
        callQueue.push(renderCall);
    }

    void Pipeline::endRecording() {
        if (!isRecording) {
            __glibcxx_assert(true);
        }
        isRecording = false;
    }

    bool Pipeline::canBeginProcessing() {
        return !isProcessing && recordingBuffer != processedBuffer;
    }

    bool Pipeline::beginProcessing() {
        if (isProcessing) {
            __glibcxx_assert(true);
        }
        if (canBeginProcessing()) {
            isProcessing = true;
            return true;
        }
        return false;
    }

    void Pipeline::processRecordedQueue() {
        if (!isProcessing) {
            __glibcxx_assert(true);
        }
    }

    void Pipeline::endProcessing() {
        if (!isProcessing) {
            __glibcxx_assert(true);
        }
        isProcessing = false;
        renderingBuffer = processedBuffer;
        processedBuffer = recordingBuffer;
    }

    std::queue<Call> Pipeline::startRendering() {
        return renderCalls[renderingBuffer];
    }

    std::queue<Call> Pipeline::getRecordingQueue() {
        return renderCalls[recordingBuffer];
    }

    std::queue<Call> Pipeline::getProcessedQueue() {
        return renderCalls[processedBuffer];
    }
    void Call::execute()
    {
        //nothing
    }
    