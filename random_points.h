// Author: afrozenator@gmail.com (Afroz Mohiuddin)

// This class gives a random number between -1 and 1.
// And therefore has utility functions that you can call to get a 2D or a 3D
// random point.

# ifndef __RANDOM_POINTS_H__
# define __RANDOM_POINTS_H__

#include <random>
#include <utility>

namespace learning_from_data {

class RandomPoints {
 public:
  RandomPoints();
  ~RandomPoints();
  double GetRandomNumber();
  std::pair<double, double> GetRandom2DPoint();
 private:
  std::random_device random_device_;
  std::default_random_engine generator_;
  std::uniform_real_distribution<double> distribution_;
};

}  // namespace learning_from_data

# endif // __RANDOM_POINTS_H__
