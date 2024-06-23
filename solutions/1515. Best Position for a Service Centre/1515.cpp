class Solution {
 public:
  double getMinDistSum(vector<vector<int>>& positions) {
    constexpr double kErr = 1e-6;
    double currX = 50;
    double currY = 50;
    double ans = distSum(positions, currX, currY);
    double step = 1;

    while (step > kErr) {
      bool shouldDecreaseStep = true;
      for (const auto& [dx, dy] : vector<pair<double, double>>{
               {0, step}, {0, -step}, {step, 0}, {-step, 0}}) {
        const double x = currX + dx;
        const double y = currY + dy;
        const double newDistSum = distSum(positions, x, y);
        if (newDistSum < ans) {
          ans = newDistSum;
          currX = x;
          currY = y;
          shouldDecreaseStep = false;
        }
      }
      if (shouldDecreaseStep)
        step /= 10;
    }

    return ans;
  }

 private:
  double distSum(const vector<vector<int>>& positions, double a, double b) {
    double sum = 0;
    for (const vector<int>& p : positions)
      sum += sqrt(pow(a - p[0], 2) + pow(b - p[1], 2));
    return sum;
  }
};
