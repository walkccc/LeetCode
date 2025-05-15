class Solution {
  public long maximumSum(List<Integer> nums) {
    long ans = 0;
    HashMap<Integer, Long> oddPowerToSum = new HashMap<>();

    for (int i = 0; i < nums.size(); ++i) {
      final int oddPower = divideSquares(i + 1);
      ans = Math.max(ans, oddPowerToSum.merge(oddPower, (long) nums.get(i), Long::sum));
    }

    return ans;
  }

  private int divideSquares(int val) {
    for (int num = 2; num * num <= val; ++num)
      while (val % (num * num) == 0)
        val /= num * num;
    return val;
  }
}
