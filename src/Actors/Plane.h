//
// Created by michaelpollind on 1/16/17.
//


#include <GL/glew.h>
#include <VertedObjects/VertexObject.h>
#include "Actors/Transform.h"
#include <boost/qvm/vec.hpp>


#ifndef _PLANE_H
#define _PLANE_H

class Plane : public Transform{
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
    VertexObject _vertexObject;

public:
    Plane();

    void Draw(float delta);
    void Update(float delta);
};


#endif //ASSIGMENT_3_PLANE_H
