class Solution {
  public int threeSumSmaller(int[] nums, int target) {
    if (nums.length < 3)
      return 0;

    int ans = 0;

    Arrays.sort(nums);

    for (int i = 0; i + 2 < nums.length; ++i) {
      int l = i + 1;
      int r = nums.length - 1;
      while (l < r)
        if (nums[i] + nums[l] + nums[r] < target) {
          // (nums[i], nums[l], nums[r])
          // (nums[i], nums[l], nums[r - 1])
          // ...,
          // (nums[i], nums[l], nums[l + 1])
          ans += r - l;
          ++l;
        } else {
          --r;
        }
    }

    return ans;
  }
}
