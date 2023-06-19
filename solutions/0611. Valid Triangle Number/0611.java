class Solution {
  public int triangleNumber(int[] nums) {
    if (nums.length < 3)
      return 0;

    int ans = 0;

    Arrays.sort(nums);

    for (int k = nums.length - 1; k > 1; --k) {
      int i = 0;
      int j = k - 1;
      while (i < j)
        if (nums[i] + nums[j] > nums[k]) {
          // (nums[i], nums[j], nums[k])
          // (nums[i + 1], nums[j], nums[k])
          // ...
          // (nums[j - 1], nums[j], nums[k])
          ans += j - i;
          --j;
        } else {
          ++i;
        }
    }

    return ans;
  }
}
