class Solution {
  public int minCost(int[] nums) {
    final int n = nums.length;
    Integer[][] mem = new Integer[n + 1][n + 1];
    return minCost(/*last=*/0, 1, nums, mem);
  }

  private int minCost(int last, int i, int[] nums, Integer[][] mem) {
    final int n = nums.length;
    if (i == n) // Single element left.
      return nums[last];
    if (i == n - 1) // Two elements left.
      return Math.max(nums[last], nums[i]);
    if (mem[i][last] != null)
      return mem[i][last];
    final int a = Math.max(nums[i], nums[i + 1]) + minCost(last, i + 2, nums, mem);
    final int b = Math.max(nums[last], nums[i]) + minCost(i + 1, i + 2, nums, mem);
    final int c = Math.max(nums[last], nums[i + 1]) + minCost(i, i + 2, nums, mem);
    return mem[i][last] = Math.min(a, Math.min(b, c));
  }
}
