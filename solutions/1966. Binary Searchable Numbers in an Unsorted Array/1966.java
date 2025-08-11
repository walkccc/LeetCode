class Solution {
  public int binarySearchableNumbers(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    // prefixMaxs[i] := Math.max(nums[0..i))
    int[] prefixMaxs = new int[n];
    // suffixMins[i] := Math.min(nums[i + 1..n))
    int[] suffixMins = new int[n];

    // Fill in `prefixMaxs`.
    prefixMaxs[0] = Integer.MIN_VALUE;
    for (int i = 1; i < n; ++i)
      prefixMaxs[i] = Math.max(prefixMaxs[i - 1], nums[i - 1]);

    // Fill in `suffixMins`.
    suffixMins[n - 1] = Integer.MAX_VALUE;
    for (int i = n - 2; i >= 0; --i)
      suffixMins[i] = Math.min(suffixMins[i + 1], nums[i + 1]);

    for (int i = 0; i < n; ++i)
      if (prefixMaxs[i] < nums[i] && nums[i] < suffixMins[i])
        ++ans;

    return ans;
  }
}
