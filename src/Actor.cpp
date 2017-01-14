//
// Created by michaelpollind on 1/13/17.
//
#include "Actor.h"
#include <boost/qvm/mat_operations.hpp>
#include <boost/qvm/map_vec_mat.hpp>

Actor::Actor() {
    _parent = NULL;
}

void Actor::SetParent(Actor* parent) {
    _parent = parent;
}

boost::qvm::mat<float,4,4> Actor::GetTransform() {
    if(_parent != NULL)
    {
        boost::qvm::mat<float,4,4> transform = boost::qvm::mat<float,4,4>();
        boost::qvm::set_identity(transform);
        transform =  _parent->GetTransform() * Local;
        return  transform;
    }
    return  Local;
}

void Actor::Update(float delta) {

}

void Actor::Draw(float delta) {

}


