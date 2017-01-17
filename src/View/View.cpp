//
// Created by michaelpollind on 1/16/17.
//

#include "View.h"

boost::qvm::mat<float,4,4> View::GetView() {
    return _view_matrix;
}