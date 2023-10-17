class Solution {
  public int minimumOperations(List<Integer> nums) {
    // dp[i] := longest non-decreasing subsequence so far with nums in [1..i]
    int[] dp = new int[4];

    for (final int num : nums) {
      ++dp[num];
      dp[2] = Math.max(dp[2], dp[1]);
      dp[3] = Math.max(dp[3], dp[2]);
    }

    return nums.size() - dp[3];
  }
}
