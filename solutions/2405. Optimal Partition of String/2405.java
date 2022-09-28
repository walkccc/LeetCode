class Solution {
  public int partitionString(String s) {
    int ans = 1;
    int usedMask = 0;

    for (final char c : s.toCharArray()) {
      final int i = c - 'a';
      if ((usedMask >> i & 1) == 1) {
        usedMask = 1 << i;
        ++ans;
      } else {
        usedMask |= 1 << i;
      }
    }

    return ans;
  }
}
