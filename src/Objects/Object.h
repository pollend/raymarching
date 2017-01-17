//
// Created by michaelpollind on 1/16/17.
//

#ifndef _OBJECT_H
#define _OBJECT_H


#include <GL/glew.h>
#include <Shaders/Program.h>

#define POSITION "in_position"
#define TEX_COORDS "in_texcoords"
#define  NORMALS "in_normals"

class Object {
public:
    virtual void  Draw() = 0;
    virtual void ConfigureVertexArrayObject(GLint vao,Program* program) = 0;
};


#endif //ASSIGMENT_3_OBJECT_H
