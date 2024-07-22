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

  private int firstGreaterEqual(List<Integer> indices, int target) {
    final int i = Collections.binarySearch(indices, target);
    return i < 0 ? -i - 1 : i;
  }
}
