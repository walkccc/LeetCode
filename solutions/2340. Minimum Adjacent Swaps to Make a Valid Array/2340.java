class Solution {
  public int minimumSwaps(int[] nums) {
    final int minIndex = getLeftmostMinIndex(nums);
    final int maxIndex = getRightmostMaxIndex(nums);
    final int swaps = minIndex + (nums.length - 1 - maxIndex);
    return minIndex <= maxIndex ? swaps : swaps - 1;
  }

  private int getLeftmostMinIndex(int[] nums) {
    int min = nums[0];
    int minIndex = 0;
    for (int i = 1; i < nums.length; ++i)
      if (nums[i] < min) {
        min = nums[i];
        minIndex = i;
      }
    return minIndex;
  }

  int getRightmostMaxIndex(int[] nums) {
    int max = nums[nums.length - 1];
    int maxIndex = nums.length - 1;
    for (int i = nums.length - 2; i >= 0; --i)
      if (nums[i] > max) {
        max = nums[i];
        maxIndex = i;
      }
    return maxIndex;
  }
}
