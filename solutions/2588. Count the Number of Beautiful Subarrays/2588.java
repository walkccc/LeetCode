class Solution {
  public long beautifulSubarrays(int[] nums) {
    // A subarray is beautiful if xor(subarray) = 0.
    long ans = 0;
    int prefix = 0;
    Map<Integer, Integer> prefixCount = new HashMap<>();
    prefixCount.put(0, 1);

    for (final int num : nums) {
      prefix ^= num;
      ans += prefixCount.getOrDefault(prefix, 0);
      prefixCount.merge(prefix, 1, Integer::sum);
    }

    return ans;
  }
}
