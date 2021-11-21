class Solution {
  public void moveZeroes(int[] nums) {
    int i = 0;
    for (final int num : nums)
      if (num != 0)
        nums[i++] = num;

    for (; i < nums.length; ++i)
      nums[i] = 0;
  }
}
