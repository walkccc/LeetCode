class Solution {
  public double minimumAverage(int[] nums) {
    final int MAX = 50;
    double ans = MAX;
    int i = 0;
    int j = nums.length - 1;

    Arrays.sort(nums);

    while (i < j)
      ans = Math.min(ans, (nums[i++] + nums[j--]) / 2.0);

    return ans;
  }
}
