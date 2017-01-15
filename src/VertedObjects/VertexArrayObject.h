//
// Created by michaelpollind on 1/14/17.
//

#include "VertexObject.h"

#ifndef _VERTEXARRAYOBJECT_H
#define _VERTEXARRAYOBJECT_H


class VertexArrayObject  : public VertexObject{
    private:
        int _numberOfIndecies;
    public:

        /**
        *declares a vertex array of indecies
        *
        **/
        VertexArrayObject(const GLushort data[], int size) ;
        ~VertexArrayObject(void);

        /**
        *binders the vertex array Object
        **/
        virtual void Bind();

        /**
        *returns the number of indecies
        **/
        int GetNumberOfIndecies();
};


#endif //ASSIGMENT_3_VERTEXARRAYOBJECT_H
