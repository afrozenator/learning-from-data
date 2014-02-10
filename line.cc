// Author: afrozenator@gmail.com (Afroz Mohiuddin)

#include "line.h"

#include <iostream>
#include <string>

using std::string;

namespace learning_from_data {

Line* Line::RandomLine() {
  RandomPoints r;
  return LineFromTwoPoints(r.GetRandom2DPoint(), r.GetRandom2DPoint());
}

Line* Line::LineFromTwoPoints(const Point& p1, const Point& p2) {
  double alpha = p1.second - p2.second;
  double beta  = p1.first  - p2.first;
  return new Line(-alpha, beta, (alpha * p1.first) - (beta * p1.second));
}

Line* Line::ZeroLine() {
  return new Line(0, 0, 0);
}

double Line::PosnRelToLine(const Point& p) const {
  return (a_ * p.first) + (b_ * p.second) + c_;
}

Label Line::PosnRelToLineNormalized(const Point& p) const {
  double d = PosnRelToLine(p);
  if (d < 0) {
    return -1;
  } else if (d > 0) {
    return 1;
  }
  return 0;
}

void Line::RandomPointsLabelled(size_t n, std::vector<PointAndLabel>* points) {
  points->clear();
  while (points->size() < n) {
    Point p = r_.GetRandom2DPoint();
    double l = PosnRelToLine(p);
    if (l > 0) {
      points->push_back(make_pair(p, 1));
    } else if (l < 0) {
      points->push_back(make_pair(p, -1));
    } else {
      // Just loop back again.
    }
  }
}

void Line::Increment(double a, double b, double c) {
  a_ += a;
  b_ += b;
  c_ += c;
}

double Line::MeasureDisagreement(Line* l1, Line* l2) {
  // Find the fraction of points that the two lines don't agree on.
  RandomPoints r;
  size_t num = 0;
  size_t n = 10000;
  for (size_t i = 0; i < n; ++i) {
    const Point& p = r.GetRandom2DPoint();
    Label label1 = l1->PosnRelToLineNormalized(p);
    Label label2 = l2->PosnRelToLineNormalized(p);
    if (label1 != label2) ++num;
  }
  double disagreement = static_cast<double>(num) / static_cast<double>(n);
  return disagreement;
}

string Line::ToString() {
  return std::to_string(a_) + ", " + std::to_string(b_) + ", " + std::to_string(c_);
}

}  // namespace learning_from_data
