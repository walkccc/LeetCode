class Solution {
  public int findMaximumXOR(int[] nums) {
    final int maxNum = Arrays.stream(nums).max().getAsInt();
    if (maxNum == 0)
      return 0;
    final int maxBit = (int) (Math.log(maxNum) / Math.log(2));
    int ans = 0;
    int mask = 0;

    // If ans is 11100 when i = 2, it means that before we reach the last two
    // bits, 11100 is the maximum XOR we have, and we're going to explore if we
    // can get another two 1s and put them into the `ans`.
    for (int i = maxBit; i >= 0; --i) {
      // Mask grows like: 100...000, 110...000, 111...000, ..., 111...111.
      mask |= 1 << i;
      Set<Integer> prefixes = new HashSet<>();
      // We only care about the left parts,
      // If i = 2, nums = {1110, 1011, 0111}
      //    . prefixes = {1100, 1000, 0100}
      for (final int num : nums)
        prefixes.add(num & mask);
      // If i = 1 and before this iteration, the ans is 10100, it means that we
      // want to grow the ans to 10100 | 1 << 1 = 10110 and we're looking for
      // XOR of two prefixes = candidate.
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
