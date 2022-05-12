class Solution {
  public int maximumTop(int[] nums, int k) {
    final int n = nums.length;
    // after taking k elements, if we're left something, then we return nums[k]; otherwise return -1
    if (k == 0 || k == 1)
      return n == k ? -1 : nums[k];
    // (remove then add) even times
    if (n == 1)
      return k % 2 == 0 ? nums[0] : -1;
    // take min(n, k - 1) elements and put back the largest one
    final int max = firstKMax(nums, k - 1);
    if (k >= n)
      return max;
    return Math.max(max, nums[k]);
  }

  private int firstKMax(int[] nums, int k) {
    int max = 0;
    for (int i = 0; i < nums.length && i < k; ++i)
      max = Math.max(max, nums[i]);
    return max;
  }
}
