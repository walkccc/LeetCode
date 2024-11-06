class Solution {
  public int minChanges(int[] nums, int k) {
    final int kMax = 1024;
    final int n = nums.length;
    // counts[i] := the counter that maps at the i-th position
    Map<Integer, Integer>[] counts = new Map[k];
    // dp[i][j] := the minimum number of elements to change s.t. XOR(nums[i..k - 1]) is j
    int[][] dp = new int[k][kMax];

    for (int i = 0; i < k; ++i)
      counts[i] = new HashMap<>();

    for (int i = 0; i < n; ++i)
      counts[i % k].merge(nums[i], 1, Integer::sum);

    Arrays.stream(dp).forEach(A -> Arrays.fill(A, n));

    // Initialize the DP array.
    for (int j = 0; j < kMax; ++j)
      dp[k - 1][j] = countAt(n, k, k - 1) - counts[k - 1].getOrDefault(j, 0);

    for (int i = k - 2; i >= 0; --i) {
      // The worst-case scenario is changing all the i-th position numbers to a
      // non-existent value in the current bucket.
      final int changeAll = countAt(n, k, i) + Arrays.stream(dp[i + 1]).min().getAsInt();
      for (int j = 0; j < kMax; ++j) {
        dp[i][j] = changeAll;
        for (Map.Entry<Integer, Integer> entry : counts[i].entrySet()) {
          final int num = entry.getKey();
          final int freq = entry.getValue();
          // the cost to change every number in the i-th position to `num`
          final int cost = countAt(n, k, i) - freq;
          dp[i][j] = Math.min(dp[i][j], dp[i + 1][j ^ num] + cost);
        }
      }
    }

    return dp[0][0];
  }

  private int countAt(int n, int k, int i) {
    return n / k + (n % k > i ? 1 : 0);
  }
}
