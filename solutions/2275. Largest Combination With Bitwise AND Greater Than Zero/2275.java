class Solution {
  public int largestCombination(int[] candidates) {
    final int kMaxBit = 24;
    int ans = 0;

    for (int i = 0; i < kMaxBit; ++i) {
      int count = 0;
      for (final int candidate : candidates)
        if ((candidate >> i & 1) == 1)
          ++count;
      ans = Math.max(ans, count);
    }

    return ans;
  }
}
