//
// Created by michaelpollind on 1/14/17.
//

#ifndef _VERTEXOBJECT_H
#define _VERTEXOBJECT_H

#include <GL/glew.h>

class VertexObject {
    protected:

            GLuint* _id;
    public:
        VertexObject(void);
        virtual ~VertexObject(void);

        virtual void Bind();

        void  loadBufferData(GLfloat* data,int size);
        void  loadBufferData(const GLfloat* data);
};


#endif //ASSIGMENT_3_VERTEXOBJECT_H
