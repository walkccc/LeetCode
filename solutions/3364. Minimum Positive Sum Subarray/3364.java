class Solution {
  public int minimumSumSubarray(List<Integer> nums, int l, int r) {
    int ans = Integer.MAX_VALUE;

    for (int windowSize = l; windowSize <= r; ++windowSize) {
      int sum = 0;
      for (int i = 0; i < windowSize; ++i)
        sum += nums.get(i);
      if (sum > 0)
        ans = Math.min(ans, sum);
      for (int i = windowSize; i < nums.size(); ++i) {
        sum -= nums.get(i - windowSize);
        sum += nums.get(i);
        if (sum > 0)
          ans = Math.min(ans, sum);
      }
    }

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }
}
