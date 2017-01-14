//
// Created by michaelpollind on 1/13/17.
//

#include "Actor.h"

Actor::Actor() {
    _transform = matrix<float>(identity_matrix<float>(4));
    _parent = NULL;
}

void Actor::SetParent(Actor* parent) {
    _parent = parent;
}

void Actor::Update(float delta) {

}

matrix<float> Actor::GetTransform() {
    if(_parent != NULL)
    {
       // matrix<float> transform= matrix<float>(identity_matrix<float>(4));
        _transform = prod(_parent->GetTransform(),GetLocalTransform());
        return  _transform;
    }

    return  GetLocalTransform();
}


matrix<float> GetLocalTransform()
{
    Matrix4x4 lscale = Matrix4x4::Scale(Scale);
    Matrix4x4 lposition = Matrix4x4::Translation(Position);
    Matrix4x4 lrotation =Rotation.ConvertToMatrix();
    return lscale  * lrotation * lposition;

}