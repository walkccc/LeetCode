class Solution {
  public int maxEnvelopes(int[][] envelopes) {
    Arrays.sort(envelopes, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);

    // Same as 300. Longest Increasing Subsequence
    int ans = 0;
    int[] dp = new int[envelopes.length];

    for (int[] e : envelopes) {
      int i = Arrays.binarySearch(dp, 0, ans, e[1]);
      if (i < 0)
        i = -(i + 1);
      dp[i] = e[1];
      if (i == ans)
        ++ans;
    }

    return ans;
  }
}
