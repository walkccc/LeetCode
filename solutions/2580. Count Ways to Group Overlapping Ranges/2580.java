class Solution {
  public int countWays(int[][] ranges) {
    final int MOD = 1_000_000_007;
    int ans = 1;
    int prevEnd = -1;

    Arrays.sort(ranges, Comparator.comparingInt(range -> range[0]));

    for (int[] range : ranges) {
      final int start = range[0];
      final int end = range[1];
      if (start > prevEnd)
        ans = ans * 2 % MOD;
      prevEnd = Math.max(prevEnd, end);
    }

    return ans;
  }
}
