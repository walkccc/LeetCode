class Solution {
  public long maximumOr(int[] nums, int k) {
    final int n = nums.length;
    long ans = 0;
    // prefix[i] := nums[0] | nums[1] | ... | nums[i - 1]
    long[] prefix = new long[n];
    // suffix[i] := nums[i + 1] | nums[i + 2] | ... nums[n - 1]
    long[] suffix = new long[n];

    for (int i = 1; i < n; ++i)
      prefix[i] = prefix[i - 1] | nums[i - 1];

    for (int i = n - 2; i >= 0; --i)
      suffix[i] = suffix[i + 1] | nums[i + 1];

    // For each num, greedily shift it left by k bits. The bitwise or value is
    // prefix[i] | nums[i] << k | suffix[i]
    for (int i = 0; i < n; ++i)
      ans = Math.max(ans, prefix[i] | (long) nums[i] << k | suffix[i]);

    return ans;
  }
}
