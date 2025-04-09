class Solution {
  public int maxScore(int[] nums) {
    final int n = nums.length;
    final int sum = Arrays.stream(nums).sum();
    if (n % 2 == 1)
      return sum - Arrays.stream(nums).min().getAsInt();
    int minAdjacentSum = Integer.MAX_VALUE;
    for (int i = 1; i < n; ++i)
      minAdjacentSum = Math.min(minAdjacentSum, nums[i - 1] + nums[i]);
    return sum - minAdjacentSum;
  }
}
