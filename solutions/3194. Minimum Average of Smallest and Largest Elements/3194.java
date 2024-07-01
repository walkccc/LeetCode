class Solution {
  public double minimumAverage(int[] nums) {
    final int kMax = 50;
    double ans = kMax;
    int i = 0;
    int j = nums.length - 1;

    Arrays.sort(nums);

    while (i < j)
      ans = Math.min(ans, (nums[i++] + nums[j--]) / 2.0);

    return ans;
  }
}
