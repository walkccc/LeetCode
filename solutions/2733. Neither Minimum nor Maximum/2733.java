class Solution {
  public int findNonMinOrMax(int[] nums) {
    if (nums.length < 3)
      return -1;
    Arrays.sort(nums, 0, 3);
    return nums[1];
  }
}
