// Author: afrozenator@gmail.com (Afroz Mohiuddin)

#include "perceptron_learning_algorithm.h"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

#include "line.h"

namespace learning_from_data {

PerceptronLearningAlgorithm::PerceptronLearningAlgorithm(vector<PointAndLabel> data)
  : training_instances_(data),
    hypothesis_(Line::ZeroLine()) {
}

void PerceptronLearningAlgorithm::RunHypothesis() {
  mislabeled_points_.clear();
  for (size_t i = 0; i < training_instances_.size(); ++i) {
    const Point& p = training_instances_[i].first;
    Label label = training_instances_[i].second;
    if (label != hypothesis_->PosnRelToLineNormalized(p)) {
      mislabeled_points_.push_back(i);
    }
  }
}

bool PerceptronLearningAlgorithm::OneIteration() {
  // Run the hypothesis to get the misclassified points.
  RunHypothesis();
  if (mislabeled_points_.empty()) {
    // std::cout << "PLA Iteration, num_misclassified_points: " << 0 << std::endl;
    // std::cout << "PLA Iteration, final hypothesis: " << hypothesis_->ToString() << std::endl;
    return true;
  }
  int num_misclassified_points = mislabeled_points_.size();
  // std::cout << "PLA Iteration, num_misclassified_points: " << num_misclassified_points << std::endl;
  // Pick one misclassified point at random.
  int random_misclassified_point = rand() % num_misclassified_points;
  const PointAndLabel& pl =
      training_instances_[mislabeled_points_[random_misclassified_point]];
  const Point& p = pl.first;
  Label correct_label = pl.second;
  UpdateHypothesis(p, correct_label);
  // std::cout << "PLA Iteration, hypothesis: " << hypothesis_->ToString() << std::endl;
}

Line* PerceptronLearningAlgorithm::hypothesis() {
  return hypothesis_.get();
}

void PerceptronLearningAlgorithm::UpdateHypothesis(const Point& p, Label l) {
  if (l > 0) {
    hypothesis_->Increment(p.first, p.second, 1);
  } else {
    hypothesis_->Increment(-p.first, -p.second, -1);
  }
}

int PerceptronLearningAlgorithm::PLA() {
  int num = 0;
  std::cout << "PLA initial hypothesis: " << hypothesis_->ToString() << std::endl;
  while (!OneIteration()) {
    ++num;
  }
  std::cout << "PLA final hypothesis: " << hypothesis_->ToString() << std::endl;
  return num;
}

} // namespace learning_from_data
