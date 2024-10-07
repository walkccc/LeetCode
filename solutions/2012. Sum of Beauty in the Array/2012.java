class Solution {
  public int sumOfBeauties(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    int[] minOfRight = new int[n];
    minOfRight[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 2; --i)
      minOfRight[i] = Math.min(nums[i], minOfRight[i + 1]);

    int maxOfLeft = nums[0];

    for (int i = 1; i <= n - 2; ++i) {
      if (maxOfLeft < nums[i] && nums[i] < minOfRight[i + 1])
        ans += 2;
      else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
        ans += 1;
      maxOfLeft = Math.max(maxOfLeft, nums[i]);
    }

    return ans;
  }
}
