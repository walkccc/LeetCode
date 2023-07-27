class Solution {
  public int minFlipsMonoIncr(String s) {
    int[] dp = new int[2];

    for (final char c : s.toCharArray()) {
      final int temp = dp[0] + (c == '1' ? 1 : 0);
      dp[1] = Math.min(dp[0], dp[1]) + (c == '0' ? 1 : 0);
      dp[0] = temp;
    }

    return Math.min(dp[0], dp[1]);
  }
}
