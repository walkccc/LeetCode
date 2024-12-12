struct Point {
  double x;
  double y;
  Point(double x, double y) : x(x), y(y) {}
};

class Solution {
 public:
  int numPoints(vector<vector<int>>& darts, int r) {
    int ans = 1;
    vector<Point> points = convertToPoints(darts);

    for (int i = 0; i < points.size(); ++i)
      for (int j = i + 1; j < points.size(); ++j)
        for (const Point& c : getCircles(points[i], points[j], r)) {
          int count = 0;
          for (const Point& point : points)
            if (dist(c, point) - r <= kErr)
              ++count;
          ans = max(ans, count);
        }

    return ans;
  }

 private:
  static constexpr double kErr = 1e-6;

  vector<Point> convertToPoints(const vector<vector<int>>& darts) {
    vector<Point> points;
    for (const vector<int>& dart : darts)
      points.emplace_back(dart[0], dart[1]);
    return points;
  }

  vector<Point> getCircles(const Point& p, const Point& q, int r) {
    if (dist(p, q) - 2.0 * r > kErr)
      return {};
    const Point m{(p.x + q.x) / 2, (p.y + q.y) / 2};
    const double distCM = sqrt(pow(r, 2) - pow(dist(p, q) / 2, 2));
    const double alpha = atan2(p.y - q.y, q.x - p.x);
    return {Point{m.x - distCM * sin(alpha), m.y - distCM * cos(alpha)},
            Point{m.x + distCM * sin(alpha), m.y + distCM * cos(alpha)}};
  }

  double dist(const Point& p, const Point& q) {
    return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
  }
};
