class Solution {
  public int sumOfSquares(int[] nums) {
    final int n = nums.length;
    int ans = 0;

    for (int i = 0; i < n; ++i)
      if (n % (i + 1) == 0)
        ans += nums[i] * nums[i];

    return ans;
  }
}
