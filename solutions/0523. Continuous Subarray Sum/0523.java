class Solution {
  public boolean checkSubarraySum(int[] nums, int k) {
    int prefix = 0;
    Map<Integer, Integer> prefixToIndex = new HashMap<>();
    prefixToIndex.put(0, -1);

    for (int i = 0; i < nums.length; ++i) {
      prefix += nums[i];
      if (k != 0)
        prefix %= k;
      if (prefixToIndex.containsKey(prefix)) {
        if (i - prefixToIndex.get(prefix) > 1)
          return true;
      } else {
        // only add if absent, because the previous index is better
        prefixToIndex.put(prefix, i);
      }
    }

    return false;
  }
}
