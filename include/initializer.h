#ifndef OPTIMIZER_INITIALIZER_H
#define OPTIMIZER_INITIALIZER_H

#include <chrono>
#include <cmath>
#include <Eigen/Dense>

using Eigen::MatrixXf;

class Initializer {
 public:
  virtual void FillWeight(MatrixXf& W, float param = 0) { };
};

class ConstantInitializer: public Initializer {
 public:
  ConstantInitializer() { };
  void FillWeight(MatrixXf& W, float param = 0) {
    W.array() = param;
  }
};

class GaussianInitializer: public Initializer {
 public:
  GaussianInitializer(float stddev = 1) {
    generator.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    distribution = std::normal_distribution<>(0, stddev);
  };
  void FillWeight(MatrixXf& W, float param = 0) {
    W = W.unaryExpr((std::ptr_fun(this->GaussianSample)));
  }

 private:
  static std::default_random_engine generator;
  static std::normal_distribution<> distribution;
  static float GaussianSample(float dummy)
  {
    return distribution(generator);
  }
};

class XavierInitializer: public Initializer {
public:
  XavierInitializer() {
    srand(time(NULL));
  };
  void FillWeight(MatrixXf& W, float param = 0) {
    W = MatrixXf::Random(W.rows(), W.cols()) * sqrtf( 6 / (W.rows() + W.cols()) );
  }
};

#endif //OPTIMIZER_INITIALIZER_H
