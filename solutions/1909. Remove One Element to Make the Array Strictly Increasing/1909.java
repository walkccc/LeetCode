class Solution {
  public boolean canBeIncreasing(int[] nums) {
    boolean removed = false;

    for (int i = 1; i < nums.length; ++i)
      if (nums[i - 1] >= nums[i]) {
        if (removed)
          return false;
        removed = true; // Remove nums[i - 1].
        if (i > 1 && nums[i - 2] >= nums[i])
          nums[i] = nums[i - 1]; // Remove nums[i] instead.
      }

    return true;
  }
}
