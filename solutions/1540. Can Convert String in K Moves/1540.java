class Solution {
  public boolean canConvertString(String s, String t, int k) {
    if (s.length() != t.length())
      return false;

    // e.g. s = "aab", t = "bbc", so shiftCount[1] = 3
    // Case 1: a -> b, need 1 move.
    // Case 2: a -> b, need 1 + 26 moves.
    // Case 3: b -> c, need 1 + 26 * 2 moves.
    int[] shiftCount = new int[26];

    for (int i = 0; i < s.length(); ++i)
      ++shiftCount[(t.charAt(i) - s.charAt(i) + 26) % 26];

    for (int shift = 1; shift < 26; ++shift)
      if (shift + 26 * (shiftCount[shift] - 1) > k)
        return false;

    return true;
  }
}
