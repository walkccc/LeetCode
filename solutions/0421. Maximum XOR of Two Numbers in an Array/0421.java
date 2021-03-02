class Solution {
  public int findMaximumXOR(int[] nums) {
    int ans = 0;
    int mask = 0;

    for (int i = 31; i >= 0; --i) {
      mask |= 1 << i;
      Set<Integer> prefixes = new HashSet<>();
      for (final int num : nums)
        prefixes.add(num & mask);
      final int candidate = ans | 1 << i;
      for (final int prefix : prefixes)
        if (prefixes.contains(prefix ^ candidate)) {
          ans = candidate;
          break;
        }
    }

    return ans;
  }
}
