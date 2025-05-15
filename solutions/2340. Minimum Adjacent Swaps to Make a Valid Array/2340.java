class Solution {
  public int minimumSwaps(int[] nums) {
    final int minIndex = getLeftmostMinIndex(nums);
    final int maxIndex = getRightmostMaxIndex(nums);
    final int swaps = minIndex + (nums.length - 1 - maxIndex);
    return minIndex <= maxIndex ? swaps : swaps - 1;
  }

  private int getLeftmostMinIndex(int[] nums) {
    int mn = nums[0];
    int minIndex = 0;
    for (int i = 1; i < nums.length; ++i)
      if (nums[i] < mn) {
        mn = nums[i];
        minIndex = i;
      }
    return minIndex;
  }

  int getRightmostMaxIndex(int[] nums) {
    int mx = nums[nums.length - 1];
    int maxIndex = nums.length - 1;
    for (int i = nums.length - 2; i >= 0; --i)
      if (nums[i] > mx) {
        mx = nums[i];
        maxIndex = i;
      }
    return maxIndex;
  }
}
