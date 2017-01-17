//
// Created by michaelpollind on 1/17/17.
//

#include "PerspectiveView.h"
#include "math.h"
#include <boost/qvm/mat_access.hpp>

PerspectiveView::PerspectiveView(float fov, float aspect, float zNear, float zFar) {
    _view_matrix = boost::qvm::mat<float,4,4>();
    float lh = 1.0f/tan(fov/2.0f);

    boost::qvm::A<0,0>(_view_matrix) = lh/aspect;
    boost::qvm::A<1,1>(_view_matrix) = lh;
    boost::qvm::A<2,2>(_view_matrix) = (zFar+zNear)/(zNear-zFar);
    boost::qvm::A<2,3>(_view_matrix) =((2.0f*zFar*zNear)/( zNear-zFar ));
    boost::qvm::A<3,2>(_view_matrix) = -1;

}