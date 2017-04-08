//
// Created by cx2 on 4/8/17.
//

#include <iostream>
#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

int main() {


  MatrixXd X;
  X = MatrixXd::Zero(2, 3);
  X << 1, 2, 3, 4, 5, 6;

  MatrixXd y;
  y = MatrixXd::Zero(1, 3);
  y << 7, 8, 9;

  cout << X << endl;
  cout << "--------------" << endl;
  cout << y << endl;
  cout << "--------------" << endl;
  X.rowwise() += y.row(0);
  cout << X << endl;

  return 0;
}
