//
// Created by michaelpollind on 1/16/17.
//

#ifndef ASSIGMENT_3_MESHOBJECT_H
#define ASSIGMENT_3_MESHOBJECT_H


#include <GL/glew.h>
#include "Object.h"

struct VertexNormal{
    GLfloat vx;
    GLfloat vy;
    GLfloat vz;
    GLfloat nx;
    GLfloat ny;
    GLfloat nz;
};

enum mesh_type{
    VERTEX_NORMAL
};

class MeshObject : public Object{
private:
    GLuint _vbo[2];
    enum mesh_type _type;
    int _number_indices;

public:
    ~MeshObject();
    MeshObject(VertexNormal* vn, int vertex_normal_size,GLushort* indecies, int indices_siz);
    //MeshObject(GLfloat* verts,int vert_size,GLfloat texcoords,int tex_coord_size,GLushort* indecies, int indecies_size);

    void ConfigureVertexArrayObject(GLint vao, Program *program);

    void Draw();
};


#endif //ASSIGMENT_3_MESHOBJECT_H
