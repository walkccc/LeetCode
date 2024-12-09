class Solution {
  // Similar to 53. Maximum Subarray
  public int maximumSum(int[] arr) {
    // dp[0][i] := the maximum sum subarray ending in i (no deletion)
    // dp[1][i] := the maximum sum subarray ending in i (at most 1 deletion)
    int[][] dp = new int[2][arr.length];

    dp[0][0] = arr[0];
    dp[1][0] = arr[0];
    for (int i = 1; i < arr.length; ++i) {
      dp[0][i] = Math.max(arr[i], dp[0][i - 1] + arr[i]);
      dp[1][i] = Math.max(arr[i], Math.max(dp[1][i - 1] + arr[i], dp[0][i - 1] /*delete arr[i]*/));
    }

    return Arrays.stream(dp[1]).max().getAsInt();
  }
}
