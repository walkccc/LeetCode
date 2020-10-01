class Solution {
  public int findUnsortedSubarray(int[] nums) {
    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;
    boolean flag = false;

    for (int i = 1; i < nums.length; ++i) {
      if (nums[i] < nums[i - 1])
        flag = true;
      if (flag)
        min = Math.min(min, nums[i]);
    }

    flag = false;

    for (int i = nums.length - 2; i >= 0; --i) {
      if (nums[i] > nums[i + 1])
        flag = true;
      if (flag)
        max = Math.max(max, nums[i]);
    }

    int l = 0;
    for (l = 0; l < nums.length; ++l)
      if (nums[l] > min)
        break;

    int r = 0;
    for (r = nums.length - 1; r >= 0; --r)
      if (nums[r] < max)
        break;

    return l > r ? 0 : r - l + 1;
  }
}