class Solution {
  public long interchangeableRectangles(int[][] rectangles) {
    long ans = 0;
    Map<Pair<Integer, Integer>, Integer> ratioCount = new HashMap<>();

    for (int[] rectangle : rectangles) {
      final int width = rectangle[0];
      final int height = rectangle[1];
      final int d = gcd(width, height);
      ratioCount.merge(new Pair<>(width / d, height / d), 1, Integer::sum);
    }

    for (final int count : ratioCount.values())
      ans += (long) count * (count - 1) / 2;

    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
