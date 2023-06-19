class Solution {
  public boolean canConvertString(String s, String t, int k) {
    if (s.length() != t.length())
      return false;

    // E.g. s = "aab", t = "bbc", so shiftCount[1] = 3
    // For a -> b, need 1 move
    //     a -> b, need 1 + 26 moves
    //     b -> c, need 1 + 26 * 2 moves
    int[] shiftCount = new int[26];

    for (int i = 0; i < s.length(); ++i) {
      final int shift = (t.charAt(i) - s.charAt(i) + 26) % 26;
      if (shift == 0)
        continue;
      if (shift + 26 * shiftCount[shift] > k)
        return false;
      ++shiftCount[shift];
    }

    return true;
  }
}
