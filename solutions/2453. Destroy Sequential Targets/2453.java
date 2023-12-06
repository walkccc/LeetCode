class Solution {
  public int destroyTargets(int[] nums, int space) {
    int ans = Integer.MAX_VALUE;
    int maxCount = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int num : nums)
      maxCount = Math.max(maxCount, count.merge(num % space, 1, Integer::sum));

    for (final int num : nums)
      if (count.get(num % space) == maxCount)
        ans = Math.min(ans, num);

    return ans;
  }
}
