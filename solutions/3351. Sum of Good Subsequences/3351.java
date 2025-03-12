class Solution {
  public int sumOfGoodSubsequences(int[] nums) {
    final int MOD = 1000000007;
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    // endsIn[i] := the number of good subsequences ending in i
    long[] endsIn = new long[maxNum + 3];
    // dp[i] := the sum of good subsequences ending in i
    long[] dp = new long[maxNum + 3];

    for (final int num : nums) {
      final long seqsToAppend = 1 + endsIn[num] + endsIn[num + 2];
      dp[num + 1] = (seqsToAppend * num + (dp[num + 1] + dp[num] + dp[num + 2])) % MOD;
      endsIn[num + 1] = (endsIn[num + 1] + seqsToAppend) % MOD;
    }

    int ans = 0;
    for (final long d : dp)
      ans = (int) (ans + d) % MOD;
    return ans;
  }
}
