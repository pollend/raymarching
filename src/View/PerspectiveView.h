//
// Created by michaelpollind on 1/17/17.
//

#ifndef ASSIGMENT_3_PERSPECTIVEVIEW_H
#define ASSIGMENT_3_PERSPECTIVEVIEW_H


#include "View.h"

class PerspectiveView : public View{
public:
    PerspectiveView(float fov,float aspect, float zNear, float zFar);

};


#endif //ASSIGMENT_3_PERSPECTIVEVIEW_H
