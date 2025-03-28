class Solution {
  public long minOperations(int[][] queries) {
    long ans = 0;
    for (int[] query : queries) {
      final int l = query[0];
      final int r = query[1];
      ans += (getOperations(r) - getOperations(l - 1) + 1) / 2;
    }
    return ans;
  }

  // Returns the number of operations required for [1, n].
  private long getOperations(int n) {
    long res = 0;
    int ops = 0;
    for (int powerOfFour = 1; powerOfFour <= n; powerOfFour *= 4) {
      final int l = powerOfFour;
      final int r = Math.min(n, powerOfFour * 4 - 1);
      res += (long) (r - l + 1) * ++ops;
    }
    return res;
  }
}
