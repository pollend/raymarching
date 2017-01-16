//
// Created by michaelpollind on 1/14/17.
//
#ifndef _FRAMEBUFFER_H
#define _FRAMEBUFFER_H

#include <GL/glew.h>

template<int size>
class FrameBuffer {
    private:
        GLuint _frameBuffer[size];
    public:
        FrameBuffer();
        ~FrameBuffer();

        void Bind(int index);

};

#endif
