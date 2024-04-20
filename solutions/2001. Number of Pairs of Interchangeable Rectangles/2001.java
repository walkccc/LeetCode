class Solution {
  public long interchangeableRectangles(int[][] rectangles) {
    long ans = 0;
    Map<Double, Integer> ratioCount = new HashMap<>();

    for (int[] r : rectangles)
      ratioCount.merge((double) r[0] / r[1], 1, Integer::sum);

    for (final int count : ratioCount.values())
      ans += (long) count * (count - 1) / 2;

    return ans;
  }
}
