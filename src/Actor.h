//
// Created by michaelpollind on 1/13/17.
//
#include <boost/qvm/quat.hpp>
#include <boost/qvm/vec.hpp>
#include <boost/qvm/mat.hpp>

#ifndef _ACTOR_H
#define _ACTOR_H

class Actor {
private:
    Actor* _parent;
public:
    boost::qvm::mat<float,4,4> Local;
    Actor();
    void SetParent(Actor* actor);
    boost::qvm::mat<float,4,4> GetTransform();

    virtual void Update(float delta);
    virtual  void Draw(float delta);
};


#endif
