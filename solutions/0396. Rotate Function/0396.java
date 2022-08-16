class Solution {
  public int maxRotateFunction(int[] nums) {
    final int sum = Arrays.stream(nums).sum();
    int f = 0;

    // calculate F(0) first
    for (int i = 0; i < nums.length; ++i)
      f += i * nums[i];

    int ans = f;

    for (int i = nums.length - 1; i >= 0; --i) {
      f += sum - nums.length * nums[i];
      ans = Math.max(ans, f);
    }

    return ans;
  }
}
