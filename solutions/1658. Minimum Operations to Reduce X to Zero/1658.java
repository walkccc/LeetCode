class Solution {
  public int minOperations(int[] nums, int x) {
    final int targetSum = Arrays.stream(nums).sum() - x;
    if (targetSum == 0)
      return nums.length;
    final int maxLen = maxSubArrayLen(nums, targetSum);
    return maxLen == -1 ? -1 : nums.length - maxLen;
  }

  // Same as 325. Maximum Size Subarray Sum Equals k
  private int maxSubArrayLen(int[] nums, int k) {
    int res = -1;
    int prefix = 0;
    Map<Integer, Integer> prefixToIndex = new HashMap<>();
    prefixToIndex.put(0, -1);

    for (int i = 0; i < nums.length; ++i) {
      prefix += nums[i];
      final int target = prefix - k;
      if (prefixToIndex.containsKey(target))
        res = Math.max(res, i - prefixToIndex.get(target));
      // No need to check the existence of the prefix since it's unique.
      prefixToIndex.put(prefix, i);
    }

    return res;
  }
}
