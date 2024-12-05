class Solution {
  public int maxSubArrayLen(int[] nums, int k) {
    int ans = 0;
    int prefix = 0;
    Map<Integer, Integer> prefixToIndex = new HashMap<>();
    prefixToIndex.put(0, -1);

    for (int i = 0; i < nums.length; ++i) {
      prefix += nums[i];
      final int target = prefix - k;
      if (prefixToIndex.containsKey(target))
        ans = Math.max(ans, i - prefixToIndex.get(target));
      prefixToIndex.putIfAbsent(prefix, i);
    }

    return ans;
  }
}
