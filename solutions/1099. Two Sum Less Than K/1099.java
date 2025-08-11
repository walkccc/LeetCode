class Solution {
  public int twoSumLessThanK(int[] nums, int k) {
    if (nums.length < 2)
      return -1;

    int ans = -1; // Note the constraint that nums[i] > 0.
    int l = 0;
    int r = nums.length - 1;

    Arrays.sort(nums);

    while (l < r)
      if (nums[l] + nums[r] < k) {
        ans = Math.max(ans, nums[l] + nums[r]);
        ++l;
      } else {
        --r;
      }

    return ans;
  }
}
