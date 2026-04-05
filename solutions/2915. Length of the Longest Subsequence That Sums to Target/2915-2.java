class Solution {
  public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
    // dp[i] := the maximum length of any subsequence of numbers so far that
    // sum to j
    int[] dp = new int[target + 1];

    for (final int num : nums)
      for (int i = target; i >= num; --i)
        if (i == num || dp[i - num] > 0)
          dp[i] = Math.max(dp[i], 1 + dp[i - num]);

    return dp[target] > 0 ? dp[target] : -1;
  }
}
