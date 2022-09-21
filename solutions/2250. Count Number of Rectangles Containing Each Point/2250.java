class Solution {
  public int[] countRectangles(int[][] rectangles, int[][] points) {
    int[] ans = new int[points.length];
    List<Integer>[] yToXs = new List[101];

    for (int i = 0; i < 101; ++i)
      yToXs[i] = new ArrayList<>();

    for (int[] r : rectangles)
      yToXs[r[1]].add(r[0]);

    for (List<Integer> xs : yToXs)
      Collections.sort(xs);

    for (int i = 0; i < points.length; ++i) {
      int count = 0;
      for (int y = points[i][1]; y < 101; ++y) {
        List<Integer> xs = yToXs[y];
        count += xs.size() - firstGreaterEqual(xs, points[i][0]);
      }
      ans[i] = count;
    }

    return ans;
  }

  // find the first index l s.t A.get(l) >= target
  // return A.size() if can't find
  private int firstGreaterEqual(List<Integer> A, int target) {
    int l = 0;
    int r = A.size();
    while (l < r) {
      final int m = (l + r) / 2;
      if (A.get(m) >= target)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
