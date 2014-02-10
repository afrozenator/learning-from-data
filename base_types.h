// Author: afrozenator@gmail.com (Afroz Mohiuddin)

# ifndef __BASE_TYPES_H__
# define __BASE_TYPES_H__

#include <utility>

namespace learning_from_data {

typedef int Label;
typedef std::pair<double, double> Point;
typedef std::pair<Point, Label> PointAndLabel;

} // namespace learning_from_data

# endif // __BASE_TYPES_H__
