class Point {
  public double x;
  public double y;
  public Point(double x, double y) {
    this.x = x;
    this.y = y;
  }
}

class Disk {
  public Point center;
  public double radius;
  public Disk(Point center, double radius) {
    this.center = center;
    this.radius = radius;
  }
}

class Solution {
  public double[] outerTrees(int[][] trees) {
    Point[] points = new Point[trees.length];
    for (int i = 0; i < trees.length; ++i)
      points[i] = new Point(trees[i][0], trees[i][1]);
    Disk disk = welzl(points, 0, new ArrayList<>());
    return new double[] {disk.center.x, disk.center.y, disk.radius};
  }

  // Returns the smallest disk that encloses points[i..n).
  // https://en.wikipedia.org/wiki/Smallest-disk_problem#Welzl's_algorithm
  private Disk welzl(Point[] points, int i, List<Point> planePoints) {
    if (i == points.length || planePoints.size() == 3)
      return trivial(planePoints);
    Disk disk = welzl(points, i + 1, planePoints);
    if (inside(disk, points[i]))
      return disk;
    return welzl(points, i + 1, addPlanePoints(planePoints, points[i]));
  }

  private List<Point> addPlanePoints(List<Point> planePoints, Point point) {
    List<Point> newPlanePoints = new ArrayList<>(planePoints);
    newPlanePoints.add(point);
    return newPlanePoints;
  }

  // Returns the smallest disk that encloses `planePoints`.
  private Disk trivial(List<Point> planePoints) {
    if (planePoints.isEmpty())
      return null;
    if (planePoints.size() == 1)
      return new Disk(new Point(planePoints.get(0).x, planePoints.get(0).y), 0);
    if (planePoints.size() == 2)
      return getDisk(planePoints.get(0), planePoints.get(1));

    Disk disk01 = getDisk(planePoints.get(0), planePoints.get(1));
    if (inside(disk01, planePoints.get(2)))
      return disk01;

    Disk disk02 = getDisk(planePoints.get(0), planePoints.get(2));
    if (inside(disk02, planePoints.get(1)))
      return disk02;

    Disk disk12 = getDisk(planePoints.get(1), planePoints.get(2));
    if (inside(disk12, planePoints.get(0)))
      return disk12;

    return getDisk(planePoints.get(0), planePoints.get(1), planePoints.get(2));
  }

  // Returns the smallest disk that encloses the points A and B.
  private Disk getDisk(Point A, Point B) {
    final double x = (A.x + B.x) / 2;
    final double y = (A.y + B.y) / 2;
    return new Disk(new Point(x, y), distance(A, B) / 2);
  }

  // Returns the smallest disk that encloses the points A, B, and C.
  private Disk getDisk(Point A, Point B, Point C) {
    // Calculate midpoints.
    Point mAB = new Point((A.x + B.x) / 2, (A.y + B.y) / 2);
    Point mBC = new Point((B.x + C.x) / 2, (B.y + C.y) / 2);

    // Calculate the slopes and the perpendicular slopes.
    final double slopeAB = (B.y - A.y) / (B.x - A.x);
    final double slopeBC = (C.y - B.y) / (C.x - B.x);
    final double perpSlopeAB = -1 / slopeAB;
    final double perpSlopeBC = -1 / slopeBC;

    // Calculate the center.
    final double x =
        (perpSlopeBC * mBC.x - perpSlopeAB * mAB.x + mAB.y - mBC.y) / (perpSlopeBC - perpSlopeAB);
    final double y = perpSlopeAB * (x - mAB.x) + mAB.y;
    Point center = new Point(x, y);
    return new Disk(center, distance(center, A));
  }

  // Returns true if the point is inside the disk.
  private boolean inside(Disk disk, Point point) {
    return disk != null && distance(disk.center, point) <= disk.radius;
  }

  private double distance(Point A, Point B) {
    final double dx = A.x - B.x;
    final double dy = A.y - B.y;
    return Math.sqrt(dx * dx + dy * dy);
  }
}
