class Solution {
  public int minimizeArrayValue(int[] nums) {
    long ans = 0;
    long prefix = 0;

    for (int i = 0; i < nums.length; ++i) {
      prefix += nums[i];
      final long prefixAvg = (long) Math.ceil(prefix / (double) (i + 1));
      ans = Math.max(ans, prefixAvg);
    }

    return (int) ans;
  }
}
