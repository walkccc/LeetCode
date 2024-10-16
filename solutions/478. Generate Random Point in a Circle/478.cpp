class Solution {
 public:
  Solution(double radius, double x_center, double y_center)
      : radius(radius), x_center(x_center), y_center(y_center) {}

  vector<double> randPoint() {
    const double length = sqrt(distribution(generator)) * radius;
    const double degree = distribution(generator) * 2 * M_PI;
    const double x = x_center + length * cos(degree);
    const double y = y_center + length * sin(degree);
    return {x, y};
  }

 private:
  const double radius;
  const double x_center;
  const double y_center;
  default_random_engine generator;
  uniform_real_distribution<double> distribution =
      uniform_real_distribution<double>(0.0, 1.0);
};
