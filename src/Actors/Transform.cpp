//
// Created by michaelpollind on 1/13/17.
//
#include "Transform.h"
#include <boost/qvm/mat_operations.hpp>
#include <boost/qvm/map_vec_mat.hpp>

Transform::Transform() {
    _parent = NULL;
}

void Transform::SetParent(Transform* parent) {
    _parent = parent;
}

boost::qvm::mat<float,4,4> Transform::GetTransform() {
    if(_parent != NULL)
    {
        boost::qvm::mat<float,4,4> transform = boost::qvm::mat<float,4,4>();
        boost::qvm::set_identity(transform);
        transform =  _parent->GetTransform() * Local;
        return  transform;
    }
    return  Local;
}

void Transform::Update(float delta) {

}

void Transform::Draw(float delta) {

}