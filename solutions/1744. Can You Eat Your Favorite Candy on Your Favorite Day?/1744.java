class Solution {
  public boolean[] canEat(int[] candiesCount, int[][] queries) {
    final int n = candiesCount.length;
    boolean[] ans = new boolean[queries.length];
    long[] prefix = new long[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = prefix[i] + candiesCount[i];

    for (int i = 0; i < queries.length; ++i) {
      final int type = queries[i][0];
      final long day = (long) queries[i][1];
      final long cap = (long) queries[i][2];
      // the minimum day required to eat
      final long minDay = prefix[type] / cap;
      // the maximum day required to eat
      final long maxDay = prefix[type + 1] - 1;
      ans[i] = minDay <= day && day <= maxDay;
    }

    return ans;
  }
}
