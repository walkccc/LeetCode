class Solution {
  public void moveZeroes(int[] nums) {
    int i = 0;
    for (final int num : nums)
      if (num != 0)
        nums[i++] = num;

    while (i < nums.length)
      nums[i++] = 0;
  }
}
