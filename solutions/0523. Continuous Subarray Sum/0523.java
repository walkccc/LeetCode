class Solution {
  public boolean checkSubarraySum(int[] nums, int k) {
    int prefixSum = 0;
    Map<Integer, Integer> prefixSumToIndex = new HashMap<>();
    prefixSumToIndex.put(0, -1);

    for (int i = 0; i < nums.length; ++i) {
      prefixSum += nums[i];
      if (k != 0)
        prefixSum %= k;
      if (prefixSumToIndex.containsKey(prefixSum)) {
        if (i - prefixSumToIndex.get(prefixSum) > 1)
          return true;
      } else
        prefixSumToIndex.put(prefixSum, i);
    }

    return false;
  }
}