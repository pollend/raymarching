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

        virtual void Bind() = 0;
};


#endif //ASSIGMENT_3_VERTEXOBJECT_H
