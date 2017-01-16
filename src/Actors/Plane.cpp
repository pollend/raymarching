//
// Created by michaelpollind on 1/16/17.
//

#include "Plane.h"

Plane::Plane() : Transform(){
    _vertexObject = VertexObject();
    _vertexObject.loadBufferData(_quad);
}

void Plane::Draw(float delta) {
    _vertexObject.Bind();
}

void Plane::Update(float delta) {

}

