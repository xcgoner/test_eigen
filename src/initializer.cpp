#include <random>
#include "initializer.h"

std::default_random_engine GaussianInitializer::generator;
std::normal_distribution<> GaussianInitializer::distribution;

