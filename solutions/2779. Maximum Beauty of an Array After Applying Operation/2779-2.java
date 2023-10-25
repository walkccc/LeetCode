class Solution {
  public int maximumBeauty(int[] nums, int k) {
    // l and r track max window instead of valid window.
    int l = 0;
    int r = 0;

    Arrays.sort(nums);

    for (r = 0; r < nums.length; ++r)
      if (nums[r] - nums[l] > 2 * k)
        ++l;

    return r - l;
  }
}
