class Solution {
  public int minMaxGame(int[] nums) {
    if (nums.length == 1)
      return nums[0];

    int[] nextNums = new int[nums.length / 2];
    for (int i = 0; i < nextNums.length; ++i)
      nextNums[i] = (i & 1) == 1 ? Math.max(nums[2 * i], nums[2 * i + 1])
                                 : Math.min(nums[2 * i], nums[2 * i + 1]);
    return minMaxGame(nextNums);
  }
}
