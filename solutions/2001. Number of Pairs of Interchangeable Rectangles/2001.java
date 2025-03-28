class Solution {
  public long interchangeableRectangles(int[][] rectangles) {
    long ans = 0;
    Map<Double, Integer> ratioCount = new HashMap<>();

    for (int[] rectangle : rectangles) {
      final int width = rectangle[0];
      final int height = rectangle[1];
      ratioCount.merge(1.0 * width / height, 1, Integer::sum);
    }

    for (final int count : ratioCount.values())
      ans += 1L * count * (count - 1) / 2;

    return ans;
  }
}
