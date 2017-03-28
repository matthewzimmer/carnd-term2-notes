#include <iostream>
#include "ukf.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "IncompatibleTypes"
UKF::UKF() {
  //TODO Auto-generated constructor stub
  Init();
}

UKF::~UKF() {
  //TODO Auto-generated destructor stub
}

void UKF::Init() {

}

/*******************************************************************************
* Programming assignment functions: 
*******************************************************************************/


void UKF::GenerateSigmaPoints(MatrixXd* Xsig_out) {

  //set state dimension
  int n_x = 5;

  //define spreading parameter
  double lambda = 3 - n_x;
  double alpha = sqrt(lambda + n_x);

  //set example state
  VectorXd x = VectorXd(n_x);
  // The first sigma point (i.e., xk|k)
  x <<   5.7441,
          1.3800,
          2.2049,
          0.5015,
          0.3528;

  std::cout << std::endl << "x= " << std::endl << x << std::endl;

  //set example covariance matrix
  MatrixXd P = MatrixXd(n_x, n_x);
  P <<     0.0043,   -0.0013,    0.0030,   -0.0022,   -0.0020,
          -0.0013,    0.0077,    0.0011,    0.0071,    0.0060,
          0.0030,    0.0011,    0.0054,    0.0007,    0.0008,
          -0.0022,    0.0071,    0.0007,    0.0098,    0.0100,
          -0.0020,    0.0060,    0.0008,    0.0100,    0.0123;

  //create sigma point matrix
  MatrixXd Xsig = MatrixXd(n_x, 1 + 2 * n_x);

  //calculate square root of P
  MatrixXd A = P.llt().matrixL();
  std::cout << std::endl << "A= " << std::endl << A << std::endl;

/*******************************************************************************
 * Student part begin
 ******************************************************************************/

  //calculate sigma points ...
  //set sigma points as columns of matrix Xsig

  MatrixXd B = alpha * A;
  std::cout << std::endl << "alpha * A= " << std::endl << B << std::endl;

  // mean state sigma point (xk|k read "x sub k pipe k")
  Xsig(0, 0) = x(0);
  Xsig(1, 0) = x(1);
  Xsig(2, 0) = x(2);
  Xsig(3, 0) = x(3);
  Xsig(4, 0) = x(4);

  // next sigma points are "x + sqrt((lambda + n_x) * Pk|k)"
  MatrixXd next_sigma_points = B.colwise()+x; // through broadcasting

  Xsig.col(1) = next_sigma_points.col(0);
  Xsig.col(2) = next_sigma_points.col(1);
  Xsig.col(3) = next_sigma_points.col(2);
  Xsig.col(4) = next_sigma_points.col(3);
  Xsig.col(5) = next_sigma_points.col(4);

  next_sigma_points = -1*(B.colwise()-x);
  Xsig.col(6) = next_sigma_points.col(0);
  Xsig.col(7) = next_sigma_points.col(1);
  Xsig.col(8) = next_sigma_points.col(2);
  Xsig.col(9) = next_sigma_points.col(3);
  Xsig.col(10) = next_sigma_points.col(4);

/*******************************************************************************
 * Student part end
 ******************************************************************************/

  //print result
//  std::cout << "Xsig = " << std::endl << Xsig << std::endl;

  //write result
  *Xsig_out = Xsig;

/* expected result:
   Xsig =
    5.7441  5.85768   5.7441   5.7441   5.7441   5.7441  5.63052   5.7441   5.7441   5.7441   5.7441
      1.38  1.34566  1.52806     1.38     1.38     1.38  1.41434  1.23194     1.38     1.38     1.38
    2.2049  2.28414  2.24557  2.29582   2.2049   2.2049  2.12566  2.16423  2.11398   2.2049   2.2049
    0.5015  0.44339 0.631886 0.516923 0.595227   0.5015  0.55961 0.371114 0.486077 0.407773   0.5015
    0.3528 0.299973 0.462123 0.376339  0.48417 0.418721 0.405627 0.243477 0.329261  0.22143 0.286879
*/

}
#pragma clang diagnostic pop