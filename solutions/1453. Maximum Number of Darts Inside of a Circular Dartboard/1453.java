class Point {
  public double x = 0;
  public double y = 0;
  public Point(double x, double y) {
    this.x = x;
    this.y = y;
  }
}

class Solution {
  public int numPoints(int[][] darts, int r) {
    int ans = 1;
    List<Point> points = convertToPoints(darts);

    for (int i = 0; i < points.size(); ++i)
      for (int j = i + 1; j < points.size(); ++j)
        for (Point c : getCircles(points.get(i), points.get(j), r)) {
          int count = 0;
          for (Point point : points)
            if (dist(c, point) - r <= kErr)
              ++count;
          ans = Math.max(ans, count);
        }

    return ans;
  }

  private static final double kErr = 1e-6;

  private List<Point> convertToPoints(int[][] darts) {
    List<Point> points = new ArrayList<>();
    for (int[] dart : darts)
      points.add(new Point(dart[0], dart[1]));
    return points;
  }

  private Point[] getCircles(Point p, Point q, int r) {
    if (dist(p, q) - 2.0 * r > kErr)
      return new Point[] {};
    Point m = new Point((p.x + q.x) / 2, (p.y + q.y) / 2);
    final double distCM = Math.sqrt(Math.pow(r, 2) - Math.pow(dist(p, q) / 2, 2));
    final double alpha = Math.atan2(p.y - q.y, q.x - p.x);
    return new Point[] {new Point(m.x - distCM * Math.sin(alpha), m.y - distCM * Math.cos(alpha)),
                        new Point(m.x + distCM * Math.sin(alpha), m.y + distCM * Math.cos(alpha))};
  }

  private double dist(Point p, Point q) {
    return Math.sqrt(Math.pow(p.x - q.x, 2) + Math.pow(p.y - q.y, 2));
  }
}
