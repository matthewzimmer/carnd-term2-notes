//
// Created by Matthew Zimmer on 4/1/17.
//

#include <iostream>
#include "Eigen/Dense"
#include <vector>
#include "ukf.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
using namespace std;
using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::vector;

int main() {

  //Create a UKF instance
  UKF ukf;

/*******************************************************************************
* Programming assignment calls
*******************************************************************************/

  VectorXd x_pred = VectorXd(5);
  MatrixXd P_pred = MatrixXd(5, 5);
  ukf.PredictMeanAndCovariance(&x_pred, &P_pred);

  return 0;
}
#pragma clang diagnostic pop