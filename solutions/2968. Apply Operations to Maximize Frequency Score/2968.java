class Solution {
  public int maxFrequencyScore(int[] nums, long k) {
    int ans = 0;
    long cost = 0;

    Arrays.sort(nums);

    // For a window [l, r], the best choice to make the numbers in the range
    // equal is to make them all equal to the median in this range.
    for (int l = 0, r = 0; r < nums.length; ++r) {
      cost += nums[r] - nums[(l + r) / 2];
      while (cost > k)
        cost -= nums[(l + r + 1) / 2] - nums[l++];
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
