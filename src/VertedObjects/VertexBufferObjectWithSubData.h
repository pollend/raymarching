//
// Created by michaelpollind on 1/14/17.
//

#include <boost/qvm/vec.hpp>
#include "VertexObject.h"
#include <boost/array.hpp>
#include <boost/numeric/ublas/vector.hpp>

#ifndef _VERTEXBUFFEROBJECTWITHSUBDATA_H
#define _VERTEXBUFFEROBJECTWITHSUBDATA_H

class VertexBufferObjectWithSubData : public VertexObject
{
public:
    class SubData
    {
    private:
        int _vectorType;
        GLfloat * _data;
        GLsizeiptr _size;
        const char* _listedType;
    public:
        /**
        *
        **/
        SubData(GLfloat data[],int size,int vectorType);
        SubData(boost::qvm::vec<float,2> data[],int size);
        SubData(boost::qvm::vec<float,3> data[],int size);
        SubData(boost::qvm::vec<float,4> data[],int size);

        SubData(GLfloat data[],int size,int vectorType,const char* listed);
        SubData(boost::qvm::vec<float,2> data[],int size,const char*  listed);
        SubData(boost::qvm::vec<float,3> data[],int size,const char*  listed);
        SubData(boost::qvm::vec<float,4> data[],int size,const char*  listed);

        ~SubData();

        GLfloat* GetData();

        /**
        *returns the vector type
        **/
        int GetVectorType();
        /**
         *get the total size
         **/

        /**
         *Get the size of data sotred in the sub-data element
         **/
        GLsizeiptr GetSize();

        /**
         *get the stored size of the subdata element
         ***/
        void SetListed(const char* type);

        /**
         *get what the subdata is listed as
         **/
        const char* GetListedType();

    };

private:
    std::vector<SubData*> _data;
    int subdataSize;

public:


    VertexBufferObjectWithSubData(void);
    ~VertexBufferObjectWithSubData(void);

    /**
     *adds a subdata element
     **/
    void AddSubData(SubData* subData);

    /**
     *retrieves the size of the entire set
     **/
    unsigned long GetSize();

    /**
     *retrieves the index of the subdata location
     **/
    SubData* operator [] (const int index);

    /**
     *intalize the buffer object
     **/
    void IntalizeBuffer();

    /**
     *binds the buffer object
     **/
    virtual void Bind();
};


#endif //ASSIGMENT_3_VERTEXBUFFEROBJECTWITHSUBDATA_H
