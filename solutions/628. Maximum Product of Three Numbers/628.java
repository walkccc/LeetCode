class Solution {
  public int maximumProduct(int[] nums) {
    final int n = nums.length;
    Arrays.sort(nums);
    return Math.max(nums[n - 1] * nums[0] * nums[1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
  }
}
