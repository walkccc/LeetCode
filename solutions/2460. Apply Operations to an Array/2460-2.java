class Solution {
  public int[] applyOperations(int[] nums) {
    for (int i = 0, j = 0; i < nums.length; ++i) {
      if (i + 1 < nums.length && nums[i] == nums[i + 1]) {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }
      if (nums[i] > 0) {
        swap(nums, i, j++);
      }
    }
    return nums;
  }

  private void swap(int[] nums, int i, int j) {
    final int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}
