class Solution {
  public int[] rearrangeArray(int[] nums) {
    Arrays.sort(nums);
    for (int i = 1; i < nums.length; i += 2) {
      final int temp = nums[i];
      nums[i] = nums[i - 1];
      nums[i - 1] = temp;
    }
    return nums;
  }
}
