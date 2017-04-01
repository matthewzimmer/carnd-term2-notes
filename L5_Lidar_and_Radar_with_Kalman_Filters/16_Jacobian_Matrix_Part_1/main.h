//
// Created by Matthew Zimmer on 3/16/17.
//

#ifndef TERM2_NOTES_MAIN_H
#define TERM2_NOTES_MAIN_H

#include <iostream>
#include "Eigen/Dense"
#include <vector>

using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;

MatrixXd CalculateJacobian(const VectorXd& x_state);


#endif //TERM2_NOTES_MAIN_H
