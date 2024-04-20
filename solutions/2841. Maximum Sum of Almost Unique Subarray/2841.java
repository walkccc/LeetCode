public class Solution {
  public long maxSum(List<Integer> nums, int m, int k) {
    long ans = 0;
    long sum = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (int i = 0; i < nums.size(); ++i) {
      sum += nums.get(i);
      count.merge(nums.get(i), 1, Integer::sum);
      if (i >= k) {
        final int numToRemove = nums.get(i - k);
        sum -= numToRemove;
        count.merge(numToRemove, -1, Integer::sum);
        if (count.get(numToRemove) == 0)
          count.remove(numToRemove);
      }
      if (count.size() >= m)
        ans = Math.max(ans, sum);
    }

    return ans;
  }
}
