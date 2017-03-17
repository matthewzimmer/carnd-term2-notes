//
// Created by Matthew Zimmer on 3/16/17.
//

#ifndef TERM2_NOTES_MAIN_H
#define TERM2_NOTES_MAIN_H

#include <iostream>
#include "../../lib/Eigen/Dense"
#include <vector>
#include <cmath>

using namespace std;
//using Eigen::MatrixXd;
//using Eigen::VectorXd;

Eigen::VectorXd CalculateRMSE(const vector<Eigen::VectorXd> &estimations,
                              const vector<Eigen::VectorXd> &ground_truth);

void PrintVectorTests();

#endif //TERM2_NOTES_MAIN_H
