class Solution {
  public int findMaxLength(int[] nums) {
    int ans = 0;
    int prefixSum = 0;
    Map<Integer, Integer> prefixSumToIndex = new HashMap<>();
    prefixSumToIndex.put(0, -1);

    for (int i = 0; i < nums.length; ++i) {
      prefixSum += nums[i] == 1 ? 1 : -1;
      if (prefixSumToIndex.containsKey(prefixSum))
        ans = Math.max(ans, i - prefixSumToIndex.get(prefixSum));
      else
        prefixSumToIndex.put(prefixSum, i);
    }

    return ans;
  }
}