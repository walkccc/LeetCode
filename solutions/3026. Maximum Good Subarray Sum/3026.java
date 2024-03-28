class Solution {
  public long maximumSubarraySum(int[] nums, int k) {
    long ans = Long.MIN_VALUE;
    long prefix = 0;
    Map<Integer, Long> numToMinPrefix = new HashMap<>();

    for (final int num : nums) {
      if (!numToMinPrefix.containsKey(num) || numToMinPrefix.get(num) > prefix)
        numToMinPrefix.put(num, prefix);
      prefix += num;
      if (numToMinPrefix.containsKey(num + k))
        ans = Math.max(ans, prefix - numToMinPrefix.get(num + k));
      if (numToMinPrefix.containsKey(num - k))
        ans = Math.max(ans, prefix - numToMinPrefix.get(num - k));
    }

    return ans == Long.MIN_VALUE ? 0 : ans;
  }
}
