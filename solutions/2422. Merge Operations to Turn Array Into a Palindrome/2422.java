class Solution {
  public int minimumOperations(int[] nums) {
    int ans = 0;
    int l = 0;
    int r = nums.length - 1;
    long leftSum = nums[l];
    long rightSum = nums[r];

    while (l < r)
      if (leftSum < rightSum) {
        leftSum += nums[++l];
        ++ans;
      } else if (leftSum > rightSum) {
        rightSum += nums[--r];
        ++ans;
      } else { // LeftSum == rightSum
        leftSum = nums[++l];
        rightSum = nums[--r];
      }

    return ans;
  }
}
