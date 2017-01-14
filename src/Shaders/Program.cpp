//
// Created by michaelpollind on 1/14/17.
//

#include "Program.h"

Program::Program() {
    _shader_program = glCreateProgram();
}

Program::~Program() {
    glDeleteProgram(_shader_program);
}

void Program::_useShader() {
    glUseProgram(_shader_program);
}

void Program::BindShader()
{

}
static void Program::Unbind()
{
    glUseProgram(0);
}

void Program::SetAttrib(int index, const GLchar* attrib)
{
    _useShader();

}

void Program::SetUniform1(const GLchar* UniformID, GLint value)
{

}
void Program::SetUniform1(const GLchar* UniformID,GLint value[])
{

}

void Program::SetUniform1(const GLchar* UniformID, GLfloat value)
{

}
void Program::SetUniform1(const GLchar* UniformID,const GLfloat value[])
{

}

void Program::SetUniform2(const GLchar* UniformID, boost::qvm::vec<float,2> value)
{

}
void Program::SetUniform2(const GLchar* UniformID, boost::qvm::vec<float,2> value[])
{
    GLfloat lvalue[sizeof(value) *3];
    for(int x = 0; x < sizeof(value) ; x++)
    {
        lvalue[(x*4)] = value[x].a[0];
        lvalue[(x*4)+1] = value[x].a[1];
        lvalue[(x*4)+2] = value[x].a[2];
        lvalue[(x*4)+4] = value[x].a[3];
    }

    glUniform4fv(glGetUniformLocation(_shader_program,UniformID),sizeof(value), lvalue);
}

void Program::SetUniform3(const GLchar* UniformID, boost::qvm::vec<float,3> value)
{
    GLfloat lvalue[sizeof(value) *3];
    for(int x = 0; x < sizeof(value) ; x++)
    {
        lvalue[(x*4)] = value[x].a[0];
        lvalue[(x*4)+1] = value[x].a[1];
        lvalue[(x*4)+2] = value[x].a[2];
        lvalue[(x*4)+4] = value[x].a[3];
    }

    glUniform4fv(glGetUniformLocation(_shader_program,UniformID),sizeof(value), lvalue);
}
void Program::SetUniform3(const GLchar* UniformID, boost::qvm::vec<float,3> value[])
{
    GLfloat lvalue[sizeof(value) *4];
    for(int x = 0; x < sizeof(value) ; x++)
    {
        lvalue[(x*4)] = value[x].a[0];
        lvalue[(x*4)+1] = value[x].a[1];
        lvalue[(x*4)+2] = value[x].a[2];
        lvalue[(x*4)+4] = value[x].a[3];
    }

    glUniform4fv(glGetUniformLocation(_shader_program,UniformID),sizeof(value), lvalue);
}

void Program::SetUniform4(const GLchar* UniformID, boost::qvm::vec<float,4> value)
{

    glUniform4fv(glGetUniformLocation(_shader_program,UniformID),1, value.a);
}
void Program::SetUniform4(const GLchar* UniformID, boost::qvm::vec<float,4>value[])
{
    GLfloat lvalue[sizeof(value) *4];
    for(int x = 0; x < sizeof(value) ; x++)
    {
        lvalue[(x*4)] = value[x].a[0];
        lvalue[(x*4)+1] = value[x].a[1];
        lvalue[(x*4)+2] = value[x].a[2];
        lvalue[(x*4)+4] = value[x].a[3];
    }

    glUniform4fv(glGetUniformLocation(_shader_program,UniformID),sizeof(value), lvalue);
}

void Program::SetMatrix4x4(const GLchar* UniformID,boost::qvm::mat<float,4,4> m)
{
    GLfloat lvalue[16];
    lvalue[0] = m.a[0][0];
    lvalue[1] = m.a[1][0];
    lvalue[2] = m.a[2][0];
    lvalue[3] = m.a[3][0];

    lvalue[0] = m.a[0][1];
    lvalue[1] = m.a[1][1];
    lvalue[2] = m.a[2][1];
    lvalue[3] = m.a[3][1];

    lvalue[0] = m.a[0][2];
    lvalue[1] = m.a[1][2];
    lvalue[2] = m.a[2][2];
    lvalue[3] = m.a[3][2];

    lvalue[0] = m.a[0][3];
    lvalue[1] = m.a[1][3];
    lvalue[2] = m.a[2][3];
    lvalue[3] = m.a[3][3];

    glUniformMatrix4fv(glGetUniformLocation(_shader_program,UniformID),1,false,lvalue);
}
void Program::SetMatrix4x4(const GLchar* UniformID,boost::qvm::mat<float,4,4> m[])
{
    GLfloat lvalue[sizeof(m) *16];
    for(int x = 0; x < sizeof(m) ; x++)
    {

        lvalue[(x*16)] = m[x].a[0][0];
        lvalue[(x*16)+1] = m[x].a[1][0];
        lvalue[(x*16)+2] = m[x].a[2][0];
        lvalue[(x*16)+3] = m[x].a[3][0];

        lvalue[(x*16)+4] = m[x].a[0][1];
        lvalue[(x*16)+5] = m[x].a[1][1];
        lvalue[(x*16)+6] = m[x].a[2][1];
        lvalue[(x*16)+7] = m[x].a[3][1];

        lvalue[(x*16)+8] = m[x].a[0][2];
        lvalue[(x*16)+9] = m[x].a[1][2];
        lvalue[(x*16)+10] = m[x].a[2][2];
        lvalue[(x*16)+11] = m[x].a[3][2];

        lvalue[(x*16)+12] = m[x].a[0][3];
        lvalue[(x*16)+13] = m[x].a[1][3];
        lvalue[(x*16)+14] = m[x].a[2][3];
        lvalue[(x*16)+15] = m[x].a[3][3];
    }

    glUniform4fv(glGetUniformLocation(_shader_program,UniformID),sizeof(m),lvalue);

}
