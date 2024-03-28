class Solution {
  public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
    long ans = 0;
    int prefix = 0; // (number of nums[i] % modulo == k so far) % modulo
    Map<Integer, Integer> prefixCount = new HashMap<>();
    prefixCount.put(0, 1);

    for (final int num : nums) {
      if (num % modulo == k)
        prefix = (prefix + 1) % modulo;
      ans += prefixCount.getOrDefault((prefix - k + modulo) % modulo, 0);
      prefixCount.merge(prefix, 1, Integer::sum);
    }

    return ans;
  }
}
