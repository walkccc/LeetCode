class Solution {
  public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
    // dp[i] := max length of any subseq of nums so far that sums to j
    int[] dp = new int[target + 1];

    for (final int num : nums)
      for (int i = target; i >= num; --i)
        if (i == num || dp[i - num] > 0)
          dp[i] = Math.max(dp[i], 1 + dp[i - num]);

    return dp[target] > 0 ? dp[target] : -1;
  }
}
