//
// Created by michaelpollind on 1/13/17.
//
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/math/quaternion.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/qvm/quat.hpp>
#include <boost/qvm/quat_operations.hpp>

#ifndef _ACTOR_H
#define _ACTOR_H

using namespace boost::numeric::ublas;
using namespace boost::math;

class Actor {
private:
    Actor* _parent;
    matrix<float> _transform;
public:
    vector<float> Position;
    vector<float> Scale;
    quaternion Rotation;

    Actor();
    void SetParent(Actor* actor);
    virtual void Update(float delta);
    matrix<float> GetTransform();
    matrix<float> GetLocalTransform();
};


#endif
