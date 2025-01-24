class Solution {
  public long maximumBeauty(int[] flowers, long newFlowers, int target, int full, int partial) {
    final int n = flowers.length;

    // If a garden is already complete, clamp it to the target.
    for (int i = 0; i < n; ++i)
      flowers[i] = Math.min(flowers[i], target);
    Arrays.sort(flowers);

    // All gardens are complete, so nothing we can do.
    if (flowers[0] == target)
      return (long) n * full;

    // Having many new flowers maximizes the beauty value.
    if (newFlowers >= (long) n * target - Arrays.stream(flowers).asLongStream().sum())
      return Math.max((long) n * full, (n - 1L) * full + (target - 1L) * partial);

    long ans = 0;
    long leftFlowers = newFlowers;
    // cost[i] := the cost to make flowers[0..i] the same
    long[] cost = new long[flowers.length];

    for (int i = 1; i < flowers.length; ++i)
      // Plant (flowers[i] - flowers[i - 1]) flowers for flowers[0..i - 1].
      cost[i] = cost[i - 1] + i * (flowers[i] - flowers[i - 1]);

    int i = flowers.length - 1; // flowers' index (flowers[i + 1..n) are complete)
    while (flowers[i] == target)
      --i;

    for (; leftFlowers >= 0; --i) {
      // To maximize the minimum number of incomplete flowers, we find the first
      // index j that we can't make flowers[0..j] equal to flowers[j], then we
      // know we can make flowers[0..j - 1] equal to flowers[j - 1]. In the
      // meantime, evenly increase each of them to seek a bigger minimum value.
      final int j = firstGreater(cost, i, leftFlowers);
      final long minIncomplete = flowers[j - 1] + (leftFlowers - cost[j - 1]) / j;
      ans = Math.max(ans, (n - 1L - i) * full + (long) minIncomplete * partial);
      leftFlowers -= Math.max(0, target - flowers[i]);
    }

    return ans;
  }

  private int firstGreater(long[] A, int maxIndex, long target) {
    final int i = Arrays.binarySearch(A, 0, maxIndex + 1, target + 1);
    return i < 0 ? -i - 1 : i;
  }
}
