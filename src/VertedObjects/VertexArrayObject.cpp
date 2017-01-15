//
// Created by michaelpollind on 1/14/17.
//

#include "VertexArrayObject.h"


VertexArrayObject::VertexArrayObject(const GLushort data[], int size) : VertexObject()
{

    _numberOfIndecies = size;
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,*_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLushort) * size,data,GL_STATIC_DRAW);
}


void VertexArrayObject::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,*_id);
}

int VertexArrayObject::GetNumberOfIndecies()
{
    return _numberOfIndecies;
}

VertexArrayObject::~VertexArrayObject(void)
{
}
