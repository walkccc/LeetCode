class Solution {
  public int maximumBeauty(int[] nums, int k) {
    int ans = 0;

    Arrays.sort(nums);

    for (int l = 0, r = 0; r < nums.length; ++r) {
      while (nums[r] - nums[l] > 2 * k)
        ++l;
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}
