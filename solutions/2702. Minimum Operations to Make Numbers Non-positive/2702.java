class Solution {
  public int minOperations(int[] nums, int x, int y) {
    int l = 0;
    int r = Arrays.stream(nums).max().getAsInt();

    while (l < r) {
      final int m = (l + r) / 2;
      if (isPossible(nums, x, y, m))
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private boolean isPossible(int[] nums, int x, int y, int m) {
    long additionalOps = 0;
    for (final int num : nums)
      additionalOps += Math.max(0L, (num - 1L * y * m + x - y - 1) / (x - y));
    return additionalOps <= m;
  }
}
