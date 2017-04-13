//
// Created by cx2 on 4/8/17.
//

#define EIGEN_RUNTIME_NO_MALLOC

#include <iostream>
#include <chrono>
#include <Eigen/Dense>

#include "initializer.h"

using namespace std;
using Eigen::MatrixXf;

static std::default_random_engine generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());
static std::normal_distribution<> distribution;

float gaussian_sample(float dummy)
{
  return distribution(generator);
}

int main() {


  MatrixXf X;
  X = MatrixXf::Zero(2, 3);
  X << 1, 2, 3, 4, 5, 6;

  MatrixXf y;
  y = MatrixXf::Zero(1, 3);
  y << 7, 8, 9;

  cout << X << endl;
  cout << "--------------" << endl;
  cout << y << endl;
  cout << "--------------" << endl;
  X.rowwise() += y.row(0);
  cout << X << endl;

  // test gaussian
  cout << "--------------" << endl;
//  static std::default_random_engine generator;
  distribution = std::normal_distribution<>(100, 1);
  Eigen::internal::set_is_malloc_allowed(false);
  X = X.unaryExpr((ptr_fun(gaussian_sample)));
  Eigen::internal::set_is_malloc_allowed(true);
  cout << X << endl;

  // test assign
  cout << "--------------" << endl;
  X.array() = 3;
  cout << X << endl;

  // test initialization
  cout << "--------------" << endl;
  Initializer *initializer = new XavierInitializer();
  initializer->FillWeight(X);
  cout << X << endl;


  return 0;
}
