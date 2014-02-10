// Author: afrozenator@gmail.com (Afroz Mohiuddin)

#include "random_points.h"

#include <stdlib.h>
#include <time.h>

namespace learning_from_data {

RandomPoints::RandomPoints() : generator_(random_device_()), distribution_(-1.0, 1.0) {}

RandomPoints::~RandomPoints() {}

double RandomPoints::GetRandomNumber() {
  return distribution_(generator_);
}

std::pair<double, double> RandomPoints::GetRandom2DPoint() {
  return std::make_pair(GetRandomNumber(), GetRandomNumber());
}

}  // namespace learning_from_data
