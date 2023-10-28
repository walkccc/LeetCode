class Solution {
  public int minimumAverageDifference(int[] nums) {
    final int n = nums.length;
    int ans = 0;
    int minDiff = Integer.MAX_VALUE;
    long prefix = 0;
    long suffix = Arrays.stream(nums).asLongStream().sum();

    for (int i = 0; i < nums.length; ++i) {
      prefix += nums[i];
      suffix -= nums[i];
      final int prefixAvg = (int) (prefix / (i + 1));
      final int suffixAvg = (i == n - 1) ? 0 : (int) (suffix / (n - i - 1));
      final int diff = Math.abs(prefixAvg - suffixAvg);
      if (diff < minDiff) {
        ans = i;
        minDiff = diff;
      }
    }

    return ans;
  }
}
