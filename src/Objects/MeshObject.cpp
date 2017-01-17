//
// Created by michaelpollind on 1/16/17.
//

#include "MeshObject.h"


MeshObject::MeshObject(VertexNormal* vn, int vertex_normal_size,GLushort* indecies, int indices_size) {
    glGenBuffers(2,_vbo);

    _type = VERTEX_NORMAL;
    _number_indices = indices_size;

    int x  = _vbo[0];

    glBindBuffer(GL_ARRAY_BUFFER,_vbo[0]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(VertexNormal)*vertex_normal_size,vn,GL_STATIC_DRAW);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_vbo[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLushort)*indices_size,indecies,GL_STATIC_DRAW);
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

void MeshObject::Draw() {

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,_vbo[1]);
    //glDrawArrays(GL_TRIANGLES, 0, _number_indices);
    glDrawElements(GL_TRIANGLES,_number_indices,GL_UNSIGNED_SHORT,0);

}