class Solution {
  // Same as 3176. Find the Maximum Length of a Good Subsequence I
  public int maximumLength(int[] nums, int k) {
    // dp[count][num] := the maximum length of a good subsequence with at most
    // `count` indices where seq[i] != seq[i + 1] and it ends in `num`.
    Map<Integer, Integer>[] dp = new HashMap[k + 1];
    // maxLen[count] := the maximum length of a good subsequence with `count`
    // indices where seq[i] != seq[i + 1]
    int[] maxLen = new int[k + 1];

    for (int i = 0; i <= k; ++i)
      dp[i] = new HashMap<>();

    for (final int num : nums)
      for (int count = k; count >= 0; --count) {
        // Append `num` to the subsequence.
        dp[count].merge(num, 1, Integer::sum);
        if (count > 0)
          dp[count].merge(num, maxLen[count - 1] + 1, Math::max);
        maxLen[count] = Math.max(maxLen[count], dp[count].get(num));
      }

    return maxLen[k];
  }
}
