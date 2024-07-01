class Solution {
  public int[] leftRigthDifference(int[] nums) {
    int[] ans = new int[nums.length];
    int leftSum = 0;
    int rightSum = Arrays.stream(nums).sum();

    for (int i = 0; i < nums.length; ++i) {
      rightSum -= nums[i];
      ans[i] = Math.abs(leftSum - rightSum);
      leftSum += nums[i];
    }

    return ans;
  }
}
