class Solution {
  public int visiblePoints(List<List<Integer>> points, int angle, List<Integer> location) {
    final int posX = location.get(0);
    final int posY = location.get(1);
    int maxVisible = 0;
    int same = 0;
    List<Double> pointAngles = new ArrayList<>();

    for (List<Integer> p : points) {
      final int x = p.get(0);
      final int y = p.get(1);
      if (x == posX && y == posY)
        ++same;
      else
        pointAngles.add(getAngle(y - posY, x - posX));
    }

    Collections.sort(pointAngles);

    final int n = pointAngles.size();
    for (int i = 0; i < n; ++i)
      pointAngles.add(pointAngles.get(i) + 360);

    for (int l = 0, r = 0; r < pointAngles.size(); ++r) {
      while (pointAngles.get(r) - pointAngles.get(l) > angle)
        ++l;
      maxVisible = Math.max(maxVisible, r - l + 1);
    }

    return maxVisible + same;
  }

  private double getAngle(int dy, int dx) {
    return Math.atan2(dy, dx) * 180 / Math.PI;
  }
}
