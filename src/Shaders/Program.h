//
// Created by michaelpollind on 1/14/17.
//

#include <GL/glew.h>
#include <boost/qvm/vec.hpp>
#include <boost/qvm/mat.hpp>
#include "Source.h"

#ifndef _PROGRAM_H
#define _PROGRAM_H

class Program {
private:
    GLuint _shader_program;
    void _useShader();


public:
    static int ActiveProgram;

    Program(void);
    ~Program(void);

    //void AttachSource(Source* source);

    void BindShader();
    static void Unbind();

    void SetAttrib(int index, const GLchar* attrib);

    void SetUniform1(const GLchar* UniformID, GLint value);
    void SetUniform1(const GLchar* UniformID,GLint value[],int size);

    void SetUniform1(const GLchar* UniformID, GLfloat value);
    void SetUniform1(const GLchar* UniformID,const GLfloat value[],int size);

    void SetUniform2(const GLchar* UniformID, boost::qvm::vec<float,2> value);
    void SetUniform2(const GLchar* UniformID, boost::qvm::vec<float,2> value[],int size);

    void SetUniform3(const GLchar* UniformID, boost::qvm::vec<float,3> value);
    void SetUniform3(const GLchar* UniformID, boost::qvm::vec<float,3> value[],int size);

    void SetUniform4(const GLchar* UniformID, boost::qvm::vec<float,4> value);
    void SetUniform4(const GLchar* UniformID, boost::qvm::vec<float,4>value[],int size);

    void SetMatrix4x4(const GLchar* UniformID,boost::qvm::mat<float,4,4> m);
    void SetMatrix4x4(const GLchar* UniformID,boost::qvm::mat<float,4,4> m[],int size);

    void AttachSource(Source* source);

    //void SetTexture(const GLchar* UniformID,Texture* texture,int index);
};


#endif //ASSIGMENT_3_PROGRAM_H
