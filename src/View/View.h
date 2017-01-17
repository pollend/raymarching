//
// Created by michaelpollind on 1/16/17.
//

#ifndef _VIEW_H
#define _VIEW_H


#include <boost/qvm/mat.hpp>

class View {
protected:
    boost::qvm::mat<float,4,4> _view_matrix;
public:
    boost::qvm::mat<float,4,4> GetView();
};


#endif //ASSIGMENT_3_VIEW_H
