class Solution {
  public long maxSubarraySum(int[] nums) {
    long ans = Arrays.stream(nums).max().getAsInt();
    long prefix = 0;
    long minPrefix = 0;
    // the minimum prefix sum that can have a negative number removed
    long modifiedMinPrefix = 0;
    Map<Integer, Integer> count = new HashMap<>();
    // minPrefixPlusRemoval[num] := the minimum prefix sum plus removed `num`
    Map<Integer, Long> minPrefixPlusRemoval = new HashMap<>();

    for (int num : nums) {
      prefix += num;
      ans = Math.max(ans, prefix - modifiedMinPrefix);
      if (num < 0) {
        count.merge(num, 1, Integer::sum);
        minPrefixPlusRemoval.put(
            num, Math.min(minPrefixPlusRemoval.getOrDefault(num, 0L), minPrefix) + num);
        modifiedMinPrefix = Math.min(modifiedMinPrefix,
                                     Math.min(count.get(num) * num, minPrefixPlusRemoval.get(num)));
      }
      minPrefix = Math.min(minPrefix, prefix);
      modifiedMinPrefix = Math.min(modifiedMinPrefix, minPrefix);
    }

    return ans;
  }
}
