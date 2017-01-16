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

void VertexObject::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, _id[0]);
}

void VertexObject::loadBufferData(GLfloat* data,int size) {
    Bind();
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

void  VertexObject::loadBufferData(const GLfloat* data)
{
    Bind();
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}