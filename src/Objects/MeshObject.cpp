//
// Created by michaelpollind on 1/16/17.
//

#include "MeshObject.h"

void MeshObject::_setup() {

        glGenBuffers(2,_vbo);

}

MeshObject::MeshObject(VertexNormal* vn, int vertex_normal_size,GLushort* indecies, int indices_size) {
    _type = VERTEX_NORMAL;

    glBindBuffer(GL_ARRAY_BUFFER,_vbo[0]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(VertexNormal)*vertex_normal_size,vn,GL_STATIC_DRAW);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_vbo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(ushort)*indices_size,indecies,GL_STATIC_DRAW);
}
/*MeshObject::MeshObject(GLfloat *verts, int vert_size, GLushort* indecies, int indecies_size) {

}*/

MeshObject::~MeshObject() {

}

void MeshObject::ConfigureVertexArrayObject(GLint vao, Program *program) {
    switch (_type)
    {
        case VERTEX_NORMAL:
        {
            GLint posAttrib = program->GetAttrib(POSITION);
            glEnableVertexAttribArray(posAttrib );
            glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE,sizeof(VertexNormal),0);


            GLint normalAttrib = program->GetAttrib(NORMALS);
            glEnableVertexAttribArray(normalAttrib);
            glVertexAttribPointer(normalAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(VertexNormal), (void*)(offsetof(VertexNormal,nx)));


        }
            break;
    }

}