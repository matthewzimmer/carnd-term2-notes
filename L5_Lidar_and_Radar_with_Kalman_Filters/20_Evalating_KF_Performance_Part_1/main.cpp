//
// Created by Matthew Zimmer on 3/16/17.
//
// Classroom: https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/3612b91d-9c33-47ad-8067-a572a6c93837/concepts/257edb7a-b99f-4942-85ef-5aee48dcd5e2
//

#include "main.h"

int main() {
//  PrintVectorTests();

  /*
 * Compute RMSE
 */
  vector<Eigen::VectorXd> estimations;
  vector<Eigen::VectorXd> ground_truth;

  //the input list of estimations
  Eigen::VectorXd e(4);
  e << 1, 1, 0.2, 0.1;
  estimations.push_back(e);
  e << 2, 2, 0.3, 0.2;
  estimations.push_back(e);
  e << 3, 3, 0.4, 0.3;
  estimations.push_back(e);

  //the corresponding list of ground truth values
  Eigen::VectorXd g(4);
  g << 1.1, 1.1, 0.3, 0.2;
  ground_truth.push_back(g);
  g << 2.1, 2.1, 0.4, 0.3;
  ground_truth.push_back(g);
  g << 3.1, 3.1, 0.5, 0.4;
  ground_truth.push_back(g);

  //call the CalculateRMSE and print out the result
  cout << CalculateRMSE(estimations, ground_truth) << endl;


  return 0;
}

Eigen::VectorXd CalculateRMSE(const vector<Eigen::VectorXd> &estimations,
                              const vector<Eigen::VectorXd> &ground_truth) {
  Eigen::VectorXd rmse(4);
  rmse << 0, 0, 0, 0;

  // TODO: YOUR CODE HERE
  int n1 = estimations.size();
  int n2 = ground_truth.size();

  // check the validity of the following inputs:
  //  * the estimation vector size should not be zero
  //  * the estimation vector size should equal ground truth vector size
  // ... your code here
  if((n1+n2 == 0) || (n1 != n2)) {
    cout << "estimations and ground truth vectors must not be empty and of equal dimensions." << endl;
    return rmse;
  }


  //accumulate squared residuals
  // Eigen::VectorXd sum;
  Eigen::VectorXd residual;
  for (int i = 0; i < n1; ++i) {
    // ... your code here
    residual = estimations[i]-ground_truth[i];
    residual = residual.array()*residual.array();
    rmse += residual;
  }

  //calculate the mean
  // ... your code here
  rmse = rmse.array()/n1;

  //calculate the squared root
  // ... your code here
  rmse = rmse.array().sqrt();

  //return the result
  return rmse;
}

void PrintVectorTests() {
  // 1. Substract two vectors
  Eigen::VectorXd a(4);
  a << 1.1, 1.1, 0.3, 0.2;
  Eigen::VectorXd b(4);
  b << 1, 1, 0.1, 0.1;
  Eigen::VectorXd c = a - b;
  cout << "a-b= " << c << endl;

  // 2. Coefficient-wise multiplication
  c = a.array() * b.array();
  cout << "a*b= " << c << endl;


  // 3. Compute vector-element square root
  c = c.array().sqrt();
  cout << "sqrt(a*b)= " << c << endl;
}