class Solution {
  public void wiggleSort(int[] nums) {
    // 1. if i is even, then nums[i] <= nums[i - 1]
    // 2. if i is odd, then nums[i] >= nums[i - 1]
    for (int i = 1; i < nums.length; ++i)
      if ((i % 2 == 0 && nums[i] > nums[i - 1]) || (i % 2 == 1 && nums[i] < nums[i - 1]))
        swap(nums, i, i - 1);
  }

  private void swap(int[] nums, int i, int j) {
    final int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}
