// Author: afrozenator@gmail.com (Afroz Mohiuddin)

# ifndef __PERCEPTRON_LEARNING_ALGORITHM_H__
# define __PERCEPTRON_LEARNING_ALGORITHM_H__

#include <memory>
#include <vector>

#include "base_types.h"
#include "random_points.h"

using std::vector;

namespace learning_from_data {

class Line;

class PerceptronLearningAlgorithm {
 public:
  PerceptronLearningAlgorithm(vector<PointAndLabel> training_instances);
  // Runs PLA, returns number of iterations to converge.
  int PLA();
  Line* hypothesis();

 private:
  void RunHypothesis();
  // If this is true, no misclassified points.
  bool OneIteration();
  void UpdateHypothesis(const Point& p, Label l);

  std::vector<PointAndLabel> training_instances_;
  std::vector<int> mislabeled_points_;
  std::unique_ptr<Line> hypothesis_;
};

}  // namespace learning_from_data

# endif // __PERCEPTRON_LEARNING_ALGORITHM_H__
