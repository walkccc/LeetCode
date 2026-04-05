class Solution {
  public int[] sortedSquares(int[] nums) {
    final int n = nums.length;
    int[] ans = new int[n];
    int i = n - 1;

    for (int l = 0, r = n - 1; l <= r;)
      if (Math.abs(nums[l]) > Math.abs(nums[r]))
        ans[i--] = nums[l] * nums[l++];
      else
        ans[i--] = nums[r] * nums[r--];

    return ans;
  }
}
