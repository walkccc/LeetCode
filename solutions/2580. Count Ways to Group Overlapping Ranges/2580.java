class Solution {
  public int countWays(int[][] ranges) {
    final int kMod = 1_000_000_007;
    int ans = 1;
    int prevEnd = -1;

    Arrays.sort(ranges, (a, b) -> a[0] - b[0]);

    for (int[] range : ranges) {
      final int start = range[0];
      final int end = range[1];
      if (start > prevEnd)
        ans = ans * 2 % kMod;
      prevEnd = Math.max(prevEnd, end);
    }

    return ans;
  }
}
