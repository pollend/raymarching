//
// Created by michaelpollind on 1/16/17.
//


#include <GL/glew.h>
#include "Transforms/Transform.h"
#include "Object.h"
#include <boost/qvm/vec.hpp>


#ifndef _PLANE_H
#define _PLANE_H

class Plane : public Object{
public:

    const GLfloat _quad[24] = {
            // x   // y    //u  //v
            -1.0f,  1.0f,  0.0f, 1.0f,
            1.0f,  1.0f,  1.0f, 1.0f,
            1.0f, -1.0f,  1.0f, 0.0f,

            1.0f, -1.0f,  1.0f, 0.0f,
            -1.0f, -1.0f,  0.0f, 0.0f,
            -1.0f,  1.0f,  0.0f, 1.0f
    };
private:
    GLuint vbo;

public:
    Plane();
    ~Plane();

    void Draw(float delta);
    void Update(float delta);

    void ConfigureVertexArrayObject(GLint vao,Program* program);
};


#endif //ASSIGMENT_3_PLANE_H
