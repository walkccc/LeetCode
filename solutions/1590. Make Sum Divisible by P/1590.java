class Solution {
  public int minSubarray(int[] nums, int p) {
    final long sum = Arrays.stream(nums).asLongStream().sum();
    final int remainder = (int) (sum % p);
    if (remainder == 0)
      return 0;

    int ans = nums.length;
    int prefix = 0;
    Map<Integer, Integer> prefixToIndex = new HashMap<>();
    prefixToIndex.put(0, -1);

    for (int i = 0; i < nums.length; ++i) {
      prefix += nums[i];
      prefix %= p;
      final int target = (prefix - remainder + p) % p;
      if (prefixToIndex.containsKey(target))
        ans = Math.min(ans, i - prefixToIndex.get(target));
      prefixToIndex.put(prefix, i);
    }

    return ans == nums.length ? -1 : ans;
  }
}
