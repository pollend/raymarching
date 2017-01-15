//
// Created by michaelpollind on 1/14/17.
//

#include "VertexBufferObjectWithSubData.h"
#include <boost/log/trivial.hpp>

VertexBufferObjectWithSubData::SubData::SubData(GLfloat data[],int size,int vectorType)
{
    _data = new GLfloat[size];
    for(int x =0; x < size; x++)
    {
        _data[x] = data[x];
    }

    _size = size * sizeof(GLfloat);
    _vectorType = vectorType;
    _listedType ="";
}
VertexBufferObjectWithSubData::SubData::SubData(boost::qvm::vec<float,2> data[],int size)
{
    _data = new GLfloat[size* 2];
    for(int x =0; x < size; x++)
    {
        _data[(x * 2)+ 0] = data[x].a[0];
        _data[(x * 2)+ 1] = data[x].a[1];
    }
    _size = size * 2* sizeof(GLfloat);
    _vectorType = 2;
    _listedType ="";
}
VertexBufferObjectWithSubData::SubData::SubData(boost::qvm::vec<float,3> data[],int size)
{
    _data = new GLfloat[size* 3];
    for(int x =0; x < size; x++)
    {
        _data[(x * 3)+ 0] = data[x].a[0];
        _data[(x * 3)+ 1] = data[x].a[1];
        _data[(x * 3)+ 2] = data[x].a[2];
    }
    _size = size * 3* sizeof(GLfloat);
    _vectorType = 3;
    _listedType ="";
}
VertexBufferObjectWithSubData::SubData::SubData(boost::qvm::vec<float,4> data[],int size)
{
    _data = new GLfloat[size* 4];
    for(int x =0; x < size; x++)
    {
        _data[(x * 4)+ 0] = data[x].a[0];
        _data[(x * 4)+ 1] = data[x].a[1];
        _data[(x * 4)+ 2] = data[x].a[2];
        _data[(x * 4)+ 3] = data[x].a[3];
    }
    _size = size * 4* sizeof(GLfloat);
    _vectorType = 4;
    _listedType ="";
}

VertexBufferObjectWithSubData::SubData::SubData(GLfloat data[],int size,int vectorType,const char* listed)
{
    _data = new GLfloat[size];
    for(int x =0; x < size; x++)
    {
        _data[x] = data[x];
    }

    _size = size * sizeof(GLfloat);
    _vectorType = vectorType;

    _listedType = listed;
}
VertexBufferObjectWithSubData::SubData::SubData(boost::qvm::vec<float,2> data[],int size,const char*  listed)
{
    _data = new GLfloat[size* 2];
    for(int x =0; x < size; x++)
    {
        _data[(x * 2)+ 0] = data[x].a[0];
        _data[(x * 2)+ 1] = data[x].a[1];
    }
    _size = size * 2* sizeof(GLfloat);
    _vectorType = 2;

    _listedType = listed;
}
VertexBufferObjectWithSubData::SubData::SubData(boost::qvm::vec<float,3> data[],int size,const char*  listed)
{
    _data = new GLfloat[size* 3];
    for(int x =0; x < size; x++)
    {
        _data[(x * 3)+ 0] = data[x].a[0];
        _data[(x * 3)+ 1] = data[x].a[1];
        _data[(x * 3)+ 2] = data[x].a[2];
    }
    _size = size * 3* sizeof(GLfloat);
    _vectorType = 3;
    _listedType = listed;
}
VertexBufferObjectWithSubData::SubData::SubData(boost::qvm::vec<float,4> data[],int size,const char*  listed)
{
    _data = new GLfloat[size* 4];
    for(int x =0; x < size; x++)
    {
        _data[(x * 4)+ 0] = data[x].a[0];
        _data[(x * 4)+ 1] = data[x].a[1];
        _data[(x * 4)+ 2] = data[x].a[2];
        _data[(x * 4)+ 3] = data[x].a[3];
    }
    _size = size * 4* sizeof(GLfloat);
    _vectorType = 4;
    _listedType = listed;
}

VertexBufferObjectWithSubData::SubData::~SubData() {
    delete[] _data;
}

GLfloat* VertexBufferObjectWithSubData::SubData::GetData() {
    return _data;
}

int VertexBufferObjectWithSubData::SubData::GetVectorType() {
    return  _vectorType;
}

GLsizeiptr VertexBufferObjectWithSubData::SubData::GetSize() {
    return _size;
}

void VertexBufferObjectWithSubData::SubData::SetListed(const char *type) {
    _listedType = type;
}

const char* VertexBufferObjectWithSubData::SubData::GetListedType() {
    return _listedType;
}



VertexBufferObjectWithSubData::VertexBufferObjectWithSubData(void) : VertexObject()
{
    _data = std::vector<SubData*>();
}


VertexBufferObjectWithSubData::~VertexBufferObjectWithSubData(void)
{
    for(int i = 0; i < _data.size(); i++)
    {
        delete(_data[i]);
    }
}

void VertexBufferObjectWithSubData::IntalizeBuffer()
{

    BOOST_LOG_TRIVIAL(trace) << "initializing Buffer: ";

    GLsizeiptr lsize = 0;
    for(int x =0; x < _data.size(); x++)
    {
        BOOST_LOG_TRIVIAL(trace) << "initializing Buffer " << x << "/" << _data.size() << " with subdata size of:" << _data[x]->GetSize();
        lsize += _data[x]->GetSize();
    };
    glBindBuffer(GL_ARRAY_BUFFER,*_id);
    glBufferData(GL_ARRAY_BUFFER,lsize,NULL, GL_STATIC_DRAW );

    GLsizeiptr loffset = 0;
    for(int x =0; x < _data.size(); x++)
    {
        glBufferSubData(GL_ARRAY_BUFFER,loffset,_data[x]->GetSize(),_data[x]->GetData());
        loffset += _data[x]->GetSize();

    }
}

void VertexBufferObjectWithSubData::AddSubData(SubData* subData)
{
    _data.push_back(subData);
}

void VertexBufferObjectWithSubData::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER,*_id);
    GLsizeiptr loffset = 0;
    for(int x =0; x < _data.size(); x++)
    {
        glEnableVertexAttribArray(x);
        glVertexAttribPointer(x,_data[x]->GetVectorType(),GL_FLOAT,GL_FALSE,0,(void*)loffset);
        loffset += _data[x]->GetSize();
    }

}

unsigned long VertexBufferObjectWithSubData::GetSize()
{
    return _data.size();
}

VertexBufferObjectWithSubData::SubData* VertexBufferObjectWithSubData::operator [] (const int index)
{
    return _data[index];
}