//
// Created by Matthew Zimmer on 3/16/17.
//

#include "main.h"

int main() {

  /*
   * Compute the Jacobian Matrix
   */

  //predicted state  example
  //px = 1, py = 2, vx = 0.2, vy = 0.4
  VectorXd x_predicted(4);
  x_predicted << 1, 2, 0.2, 0.4;
  cout << x_predicted << endl;

  MatrixXd Hj = CalculateJacobian(x_predicted);

  cout << "Hj:" << endl << Hj << endl;

  return 0;
}

MatrixXd CalculateJacobian(const VectorXd& x_state) {

  MatrixXd Hj(3,4);
  //recover state parameters
  double px = x_state(0);
  double py = x_state(1);
  double vx = x_state(2);
  double vy = x_state(3);

  //TODO: YOUR CODE HERE

  //check division by zero
  if(px+py == 0) {
    cout << "CalculateJacobian () - Error - Division by Zero" << endl;
    return Hj;
  }

  //compute the Jacobian matrix
  double px_py_sqrd_sum = (px*px + py*py);
  double rho = sqrt(px_py_sqrd_sum);
  double phi = atan(py/px);
  double rho_dot = (px*vx+py*vy)/rho;
  double pow_px_py_sqrd_sum = pow(px_py_sqrd_sum, 3.0/2.0);

  Hj(0, 0) = px/rho; // dh(rho)/dpx == "derivative of rho with respect to px"
  Hj(0, 1) = py/rho; // dh(rho)/py == "derivative of rho with respect to py"
  Hj(0, 2) = 0; // dh(rho)/dvx == "derivative of rho with respect to vx"
  Hj(0, 3) = 0; // dh(rho)/dvy == "derivative of rho with respect to vy"

  Hj(1, 0) = -py/px_py_sqrd_sum; // dh(phi)/dpx == "derivative of phi with respect to px"
  Hj(1, 1) = px/px_py_sqrd_sum; // dh(phi)/dpy == "derivative of phi with respect to py"
  Hj(1, 2) = 0; // dh(phi)/vx = dh(phi)/dvx*arctan(py/px) == "derivative of rho with respect to px"
  Hj(1, 3) = 0; // dh(phi)/vy = dh(phi)/dvy*arctan(py/px)

  Hj(2, 0) = (py*(vx*py-vy*px))/pow_px_py_sqrd_sum; // dh(rho_dot)/px
  Hj(2, 1) = (px*(vy*px-vx*py))/pow_px_py_sqrd_sum; // dh(rho_dot)/py
  Hj(2, 2) = px/rho; // dh(rho_dot)/vx
  Hj(2, 3) = py/rho; // dh(rho_dot)/vy

  return Hj;
}