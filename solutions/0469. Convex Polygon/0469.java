class Solution {
  public boolean isConvex(List<List<Integer>> points) {
    final int n = points.size();
    long sign = 0;

    for (int i = 0; i < n; ++i) {
      final int cross = getCross(points.get(i), points.get((i + 1) % n), points.get((i + 2) % n));
      if (cross == 0) // p, q, r are collinear
        continue;
      if (sign == 0) // find first cross that's not 0
        sign = cross;
      else if (cross * sign < 0)
        return false;
    }

    return true;
  }

  private int getCross(List<Integer> p, List<Integer> q, List<Integer> r) {
    return (q.get(0) - p.get(0)) * (r.get(1) - p.get(1)) -
        (q.get(1) - p.get(1)) * (r.get(0) - p.get(0));
  }
}
