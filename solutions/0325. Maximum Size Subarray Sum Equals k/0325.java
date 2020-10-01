class Solution {
  public int maxSubArrayLen(int[] nums, int k) {
    int ans = 0;
    int prefixSum = 0;
    Map<Integer, Integer> prefixSumToIndex = new HashMap<>();
    prefixSumToIndex.put(0, -1);

    for (int i = 0; i < nums.length; ++i) {
      prefixSum += nums[i];
      final int target = prefixSum - k;
      if (prefixSumToIndex.containsKey(target))
        ans = Math.max(ans, i - prefixSumToIndex.get(target));
      prefixSumToIndex.putIfAbsent(prefixSum, i);
    }

    return ans;
  }
}