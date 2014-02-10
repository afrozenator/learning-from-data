// Author: afrozenator@gmail.com (Afroz Mohiuddin)

# ifndef __LINE_H__
# define __LINE_H__

#include <string>

#include "base_types.h"
#include "random_points.h"

namespace learning_from_data {

// ax + by + c = 0
class Line {
 public:
  static Line* LineFromTwoPoints(const Point& p1, const Point& p2);
  static Line* RandomLine();
  static Line* ZeroLine();
  static double MeasureDisagreement(Line* l1, Line* l2);
  // -ve means below the line, +ve above the line, zero on the line.
  double PosnRelToLine(const Point& p) const;
  // -1, 0, +1
  Label PosnRelToLineNormalized(const Point& p) const;
  // Get N random points with labels.
  void RandomPointsLabelled(size_t n, std::vector<PointAndLabel>* points);
  // Add a, b, c to a_, b_ & c_.
  void Increment(double a, double b, double c);
  // Human readable.
  std::string ToString();

 private:
  Line(double a, double b, double c) : a_(a), b_(b), c_(c) {}

  double a_;
  double b_;
  double c_;
  RandomPoints r_;
};

}  // namespace learning_from_data

# endif // __LINE_H__
