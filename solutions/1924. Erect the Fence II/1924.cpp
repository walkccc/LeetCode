struct Point {
  double x;
  double y;
  Point(double x, double y) : x(x), y(y) {}
};

struct Disk {
  Point center;
  double radius;
  Disk(const Point& center, double radius) : center(center), radius(radius) {}
};

class Solution {
 public:
  vector<double> outerTrees(vector<vector<int>>& trees) {
    vector<Point> points;
    for (int i = 0; i < trees.size(); ++i)
      points.emplace_back(trees[i][0], trees[i][1]);
    Disk disk = welzl(points, 0, {});
    return {disk.center.x, disk.center.y, disk.radius};
  }

 private:
  // Returns the smallest disk that encloses points[i..n).
  // https://en.wikipedia.org/wiki/Smallest-disk_problem#Welzl's_algorithm
  Disk welzl(const vector<Point>& points, int i, vector<Point> planePoints) {
    if (i == points.size() || planePoints.size() == 3)
      return trivial(planePoints);
    Disk disk = welzl(points, i + 1, planePoints);
    if (inside(disk, points[i]))
      return disk;
    return welzl(points, i + 1, addPlanePoint(planePoints, points[i]));
  }

  vector<Point> addPlanePoint(const vector<Point>& planePoints,
                              const Point& point) {
    vector<Point> newPlanePoints(planePoints);
    newPlanePoints.push_back(point);
    return newPlanePoints;
  }
  // Returns the smallest disk that encloses the `planePoints`.
  Disk trivial(const vector<Point>& planePoints) {
    if (planePoints.empty())
      return Disk(Point(0, 0), 0);
    if (planePoints.size() == 1)
      return Disk(Point(planePoints[0].x, planePoints[0].y), 0);
    if (planePoints.size() == 2)
      return getDisk(planePoints[0], planePoints[1]);

    Disk disk01 = getDisk(planePoints[0], planePoints[1]);
    if (inside(disk01, planePoints[2]))
      return disk01;

    Disk disk02 = getDisk(planePoints[0], planePoints[2]);
    if (inside(disk02, planePoints[1]))
      return disk02;

    Disk disk12 = getDisk(planePoints[1], planePoints[2]);
    if (inside(disk12, planePoints[0]))
      return disk12;

    return getDisk(planePoints[0], planePoints[1], planePoints[2]);
  }

  // Returns the smallest disk that encloses the points A and B.
  Disk getDisk(const Point& A, const Point& B) {
    const double x = (A.x + B.x) / 2;
    const double y = (A.y + B.y) / 2;
    return Disk(Point(x, y), distance(A, B) / 2);
  }

  // Returns the smallest disk that encloses the points A, B, and C.
  Disk getDisk(const Point& A, const Point& B, const Point& C) {
    // Calculate midpoints.
    Point mAB((A.x + B.x) / 2, (A.y + B.y) / 2);
    Point mBC((B.x + C.x) / 2, (B.y + C.y) / 2);

    // Calculate the slopes and the perpendicular slopes.
    const double slopeAB = (B.y - A.y) / (B.x - A.x);
    const double slopeBC = (C.y - B.y) / (C.x - B.x);
    const double perpSlopeAB = -1 / slopeAB;
    const double perpSlopeBC = -1 / slopeBC;

    // Calculate the center.
    const double x =
        (perpSlopeBC * mBC.x - perpSlopeAB * mAB.x + mAB.y - mBC.y) /
        (perpSlopeBC - perpSlopeAB);
    const double y = perpSlopeAB * (x - mAB.x) + mAB.y;
    Point center(x, y);
    return Disk(center, distance(center, A));
  }

  // Returns true if the point is inside the disk.
  bool inside(Disk disk, Point point) {
    return disk.radius > 0 && distance(disk.center, point) <= disk.radius;
  }

  double distance(Point A, Point B) {
    const double dx = A.x - B.x;
    const double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
  }
};
