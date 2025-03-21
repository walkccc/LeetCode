class Solution {
  public long countSubarrays(int[] nums, int minK, int maxK) {
    long ans = 0;
    int j = -1;
    int prevMinKIndex = -1;
    int prevMaxKIndex = -1;

    for (int i = 0; i < nums.length; ++i) {
      if (nums[i] < minK || nums[i] > maxK)
        j = i;
      if (nums[i] == minK)
        prevMinKIndex = i;
      if (nums[i] == maxK)
        prevMaxKIndex = i;
      // Any index k in [j + 1, min(prevMinKIndex, prevMaxKIndex)] can be the
      // start of the subarray s.t. nums[k..i] satisfies the conditions.
      ans += Math.max(0, Math.min(prevMinKIndex, prevMaxKIndex) - j);
    }

    return ans;
  }
}
