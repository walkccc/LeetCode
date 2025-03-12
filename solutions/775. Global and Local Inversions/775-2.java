class Solution {
  public boolean isIdealPermutation(int[] nums) {
    for (int i = 0; i < nums.length; ++i)
      if (Math.abs(nums[i] - i) > 1)
        return false;
    return true;
  }
}
