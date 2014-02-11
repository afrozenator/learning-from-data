// Author: afrozenator@gmail.com (Afroz Mohiuddin)

#include <cstdlib>
#include <memory>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "line.h"
#include "random_points.h"
#include "perceptron_learning_algorithm.h"

using std::make_pair;
using std::string;
using std::vector;

using learning_from_data::RandomPoints;
using learning_from_data::Line;
using learning_from_data::PointAndLabel;
using learning_from_data::PerceptronLearningAlgorithm;

int main(int argc, char **argv) {

  RandomPoints r;

  int num_iterations = 0;
  int num_trials = 1000;
  double probab_disagreement = 0.0;
  for (size_t i = 0; i < num_trials; ++i) {
    // Take a random line.
    std::unique_ptr<Line> line(Line::RandomLine());
    std::cout << "@@@ Canonical line: " << line->ToString() << std::endl;
    // Make 10 examples from it.
    vector<PointAndLabel> pnl;
    line->RandomPointsLabelled(100, &pnl);
    // Show those examples.

    /*
    for (const auto& p : pnl) {
      std::cout << "[" << p.first.first << ", " << p.first.second << "] \t "
                << p.second << std::endl;
    }
    */

    // Learn a perceptron on them, note number of iterations for convergence.
    PerceptronLearningAlgorithm pla(pnl);
    int num = pla.PLA();
    std::cout << "@@@ Perceptron line: " << pla.hypothesis()->ToString() << std::endl;
    std::cout << "Num Iterations: " << num << std::endl;
    num_iterations += num;
    // What is the probability of agreement.
    double disagreement = Line::MeasureDisagreement(line.get(), pla.hypothesis());
    std::cout << "Disagreement : " << disagreement << std::endl;
    probab_disagreement += disagreement;
  }

  double average_iterations_to_converge = static_cast<double>(num_iterations / num_trials);
  double average_probab_disagreement = probab_disagreement / num_trials;

  std::cout << "Average Iterations: " << average_iterations_to_converge << std::endl;
  std::cout << "Average Disagreement: " << average_probab_disagreement << std::endl;


  /*
  std::unique_ptr<Line> line(
      Line::LineFromTwoPoints(
          make_pair(0, 0), make_pair(1, 1)));
  std::pair<double, double> random_2d_point = r.GetRandom2DPoint();
  for (size_t i = 0; i < 100; ++i) {
    double p = line->PosnRelToLine(random_2d_point);
    string posn = "On";
    if (p > 0) {
      posn = "Above";
    } else if (p < 0) {
      posn = "Below";
    }
    std::cout << random_2d_point.first << "\t" << random_2d_point.second << "\t" << posn << std::endl;
    random_2d_point = r.GetRandom2DPoint();
  }
  */

  return EXIT_SUCCESS;
}
