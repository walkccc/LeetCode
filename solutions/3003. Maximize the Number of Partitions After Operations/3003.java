class Solution {
  public int maxPartitionsAfterOperations(String s, int k) {
    Map<Long, Integer> mem = new HashMap<>();
    return maxPartitionsAfterOperations(s, 0, true, 0, k, mem) + 1;
  }

  // Returns the maximum number of partitions of s[i..n), where `canChange` is
  // true if we can still change a letter, and `mask` is the bitmask of the
  // letters we've seen.
  private int maxPartitionsAfterOperations(final String s, int i, boolean canChange, int mask,
                                           int k, Map<Long, Integer> mem) {
    if (i == s.length())
      return 0;

    Long key = (long) i << 27 | (canChange ? 1 : 0) << 26 | mask;
    if (mem.containsKey(key))
      return mem.get(key);

    // Initialize the result based on the current letter.
    int res = getRes(s, i, canChange, mask, 1 << (s.charAt(i) - 'a'), k, mem);

    // If allowed, explore the option to change the current letter.
    if (canChange)
      for (int j = 0; j < 26; ++j)
        res = Math.max(res, getRes(s, i, false, mask, 1 << j, k, mem));

    mem.put(key, res);
    return res;
  }

  private int getRes(final String s, int i, boolean nextCanChange, int mask, int newBit, int k,
                     Map<Long, Integer> mem) {
    final int nextMask = mask | newBit;
    if (Integer.bitCount(nextMask) > k) // fresh start
      return 1 + maxPartitionsAfterOperations(s, i + 1, nextCanChange, newBit, k, mem);
    return maxPartitionsAfterOperations(s, i + 1, nextCanChange, nextMask, k, mem);
  }
}
