class Solution {
  public long maximumSum(List<Integer> nums) {
    long ans = 0;

    for (int oddPower = 1; oddPower <= nums.size(); ++oddPower) {
      long sum = 0;
      for (int num = 1; num * num * oddPower <= nums.size(); ++num)
        sum += nums.get(oddPower * num * num - 1);
      ans = Math.max(ans, sum);
    }

    return ans;
  }
}
