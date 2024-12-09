class Solution {
  public int countSubMultisets(List<Integer> nums, int l, int r) {
    final int kMod = 1_000_000_007;
    // dp[i] := the number of submultisets of `nums` with sum i
    long[] dp = new long[r + 1];
    dp[0] = 1;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int num : nums)
      count.merge(num, 1, Integer::sum);

    final int zeros = count.containsKey(0) ? count.remove(0) : 0;

    for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
      final int num = entry.getKey();
      final int freq = entry.getValue();
      // stride[i] := dp[i] + dp[i - num] + dp[i - 2 * num] + ...
      long[] stride = dp.clone();
      for (int i = num; i <= r; ++i)
        stride[i] += stride[i - num];
      for (int i = r; i > 0; --i)
        if (i >= num * (freq + 1))
          // dp[i] + dp[i - num] + dp[i - freq * num]
          dp[i] = (stride[i] - stride[i - num * (freq + 1)]) % kMod;
        else
          dp[i] = stride[i] % kMod;
    }

    long ans = 0;
    for (int i = l; i <= r; ++i)
      ans = (ans + dp[i]) % kMod;
    return (int) (((zeros + 1) * ans) % kMod);
  }
}
