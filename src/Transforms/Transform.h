//
// Created by michaelpollind on 1/13/17.
//
#include <boost/qvm/quat.hpp>
#include <boost/qvm/vec.hpp>
#include <boost/qvm/mat.hpp>
#include <Objects/Object.h>
#include <Shaders/Program.h>
#include <View/View.h>

#ifndef _TRANSFORM_H
#define _TRANSFORM_H


class Transform {
private:
    Transform* _parent;
    Program* _program;
    GLint vao;
    Object* _object;
public:
    boost::qvm::mat<float,4,4> Local;

    Transform(Object* object,Program* program);

    void SetParent(Transform* actor);
    boost::qvm::mat<float,4,4> GetTransform();

    virtual void Update(float delta);
    virtual void Draw(float delta,View* view);
};


#endif
