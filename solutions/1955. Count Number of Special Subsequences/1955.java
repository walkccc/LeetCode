class Solution {
  public int countSpecialSubsequences(int[] nums) {
    // dp[i][j] := # of special subseqs of nums[i:] and prev + 1 = j
    dp = new int[nums.length][4];
    Arrays.stream(dp).forEach(row -> Arrays.fill(row, -1));
    return countSpecialSubsequences(nums, 0, -1);
  }

  private static final int kMod = 1_000_000_007;
  private int[][] dp;

  int countSpecialSubsequences(int[] nums, int i, int prev) {
    if (i == nums.length)
      return prev == 2 ? 1 : 0;
    if (dp[i][prev + 1] != -1)
      return dp[i][prev + 1];

    long ans = 0;

    // not include nums[i]
    ans += countSpecialSubsequences(nums, i + 1, prev);

    // include nums[i]
    if (nums[i] == prev)
      ans += countSpecialSubsequences(nums, i + 1, prev);
    if (prev == -1 && nums[i] == 0)
      ans += countSpecialSubsequences(nums, i + 1, 0);
    if (prev == 0 && nums[i] == 1)
      ans += countSpecialSubsequences(nums, i + 1, 1);
    if (prev == 1 && nums[i] == 2)
      ans += countSpecialSubsequences(nums, i + 1, 2);

    ans %= kMod;
    return dp[i][prev + 1] = (int) ans;
  }
}
