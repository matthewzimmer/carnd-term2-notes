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
  float px = x_state(0);
  float py = x_state(1);
  float vx = x_state(2);
  float vy = x_state(3);

  //TODO: YOUR CODE HERE

  //check division by zero
  if(px+py == 0) {
    cout << "CalculateJacobian () - Error - Division by Zero" << endl;
    return Hj;
  }

  //compute the Jacobian matrix
  float px_py_sqrd_prod = pow(px, 2.0) + pow(py, 2.0);
  float sqrt_px_py_sqrd_prod = sqrt(px_py_sqrd_prod);
  float pow_px_py_sqrd_prod = pow(px_py_sqrd_prod, 3.0/2.0);

  Hj(0, 0) = px/sqrt_px_py_sqrd_prod; // dh(row)/px
  Hj(0, 1) = py/sqrt_px_py_sqrd_prod; // dh(row)/py
  Hj(0, 2) = 0; // dh(row)/vx
  Hj(0, 3) = 0; // dh(row)/vy

  Hj(1, 0) = -py/px_py_sqrd_prod; // dh(phi)/xpx
  Hj(1, 1) = px/px_py_sqrd_prod; // dh(phi)/xpy
  Hj(1, 2) = 0; // dh(phi)/vx = d/dvx*arctan(py/px)
  Hj(1, 3) = 0; // dh(phi)/vy = d/dvy*arctan(py/px)

  Hj(2, 0) = (py*(vx*py-vy*px))/pow_px_py_sqrd_prod; // dh(rho_dot)/px
  Hj(2, 1) = (px*(vy*px-vx*py))/pow_px_py_sqrd_prod; // dh(rho_dot)/py
  Hj(2, 2) = px/sqrt_px_py_sqrd_prod; // dh(rho_dot)/vx
  Hj(2, 3) = py/sqrt_px_py_sqrd_prod; // dh(rho_dot)/vy

  return Hj;
}