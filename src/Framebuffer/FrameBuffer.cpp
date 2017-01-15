//
// Created by michaelpollind on 1/14/17.
//

#include "FrameBuffer.h"

template<int size>
FrameBuffer<size>::FrameBuffer() {
    glGenFramebuffers(size,_frameBuffer);
}


template<int size>
FrameBuffer<size>::~FrameBuffer() {
    glDeleteFramebuffers(size, _frameBuffer);
}



template<int size>
void FrameBuffer<size>::Bind(int index) {
    glBindFramebuffer(GL_FRAMEBUFFER, _frameBuffer[index]);
}

