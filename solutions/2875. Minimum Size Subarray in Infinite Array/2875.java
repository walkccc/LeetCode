class Solution {
  public int minSizeSubarray(int[] nums, int target) {
    final long sum = Arrays.stream(nums).asLongStream().sum();
    final int n = nums.length;
    final int remainingTarget = (int) (target % sum);
    final int repeatLength = (int) (target / sum) * n;
    if (remainingTarget == 0)
      return repeatLength;

    int suffixPlusPrefixLength = n;
    long prefix = 0;
    HashMap<Long, Integer> prefixToIndex = new HashMap<>();
    prefixToIndex.put(0L, -1);

    for (int i = 0; i < 2 * n; ++i) {
      prefix += nums[i % n];
      if (prefixToIndex.containsKey(prefix - remainingTarget))
        suffixPlusPrefixLength =
            Math.min(suffixPlusPrefixLength, i - prefixToIndex.get(prefix - remainingTarget));
      prefixToIndex.put(prefix, i);
    }

    return suffixPlusPrefixLength == n ? -1 : repeatLength + suffixPlusPrefixLength;
  }
}
