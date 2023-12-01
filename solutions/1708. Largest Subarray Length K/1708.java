class Solution {
  public int[] largestSubarray(int[] nums, int k) {
    int maxIndex = 0;
    for (int i = 1; i <= nums.length - k; ++i)
      if (nums[i] > nums[maxIndex])
        maxIndex = i;
    return Arrays.copyOfRange(nums, maxIndex, maxIndex + k);
  }
}
