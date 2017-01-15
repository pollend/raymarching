//
// Created by michaelpollind on 1/14/17.
//

#include "VertexObject.h"

VertexObject::VertexObject(void)
{
    _id = new GLuint();
    glGenBuffers(1,_id);
}

VertexObject::~VertexObject(void)
{
    glDeleteBuffers(1,_id);
    delete(_id);
}