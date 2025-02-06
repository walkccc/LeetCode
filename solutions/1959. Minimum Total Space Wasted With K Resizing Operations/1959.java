class Solution {
  public int minSpaceWastedKResizing(int[] nums, int k) {
    Integer[][] mem = new Integer[nums.length][k + 1];
    return minSpaceWasted(nums, 0, k, mem);
  }

  private static final int kMax = 200_000_000;

  // Returns the minimum space wasted for nums[i..n) if you can resize k times.
  private int minSpaceWasted(int[] nums, int i, int k, Integer[][] mem) {
    if (i == nums.length)
      return 0;
    if (k == -1)
      return kMax;
    if (mem[i][k] != null)
      return mem[i][k];

    int res = kMax;
    int sum = 0;
    int maxNum = nums[i];

    for (int j = i; j < nums.length; ++j) {
      sum += nums[j];
      maxNum = Math.max(maxNum, nums[j]);
      final int wasted = maxNum * (j - i + 1) - sum;
      res = Math.min(res, minSpaceWasted(nums, j + 1, k - 1, mem) + wasted);
    }

    return mem[i][k] = res;
  }
}
