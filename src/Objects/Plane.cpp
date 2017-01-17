//
// Created by michaelpollind on 1/16/17.
//

#include "Plane.h"

Plane::Plane() {
    glGenBuffers(1, &vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_quad), _quad, GL_STATIC_DRAW);

}

Plane::~Plane() {
    glDeleteBuffers(1,&vbo);
}

void Plane::Draw(float delta) {
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Plane::ConfigureVertexArrayObject(GLint vao,Program* program) {
    glBindVertexArray(vao);

    GLint posAttrib = program->GetAttrib(POSITION);
    glEnableVertexAttribArray(posAttrib );
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);


    GLint texAttrib = program->GetAttrib(TEX_COORDS);
    glEnableVertexAttribArray(texAttrib);
    glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));


}

void Plane::Update(float delta) {

}

