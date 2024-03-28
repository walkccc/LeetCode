class Solution {
 public:
  bool canConvertString(string s, string t, int k) {
    if (s.length() != t.length())
      return false;

    // e.g. s = "aab", t = "bbc", so shiftCount[1] = 3
    // Case 1: a -> b, need 1 move.
    // Case 2: a -> b, need 1 + 26 moves.
    // Case 3: b -> c, need 1 + 26 * 2 moves.
    vector<int> shiftCount(26);

    for (int i = 0; i < s.length(); ++i) {
      const int shift = (t[i] - s[i] + 26) % 26;
      if (shift == 0)
        continue;
      if (shift + 26 * shiftCount[shift] > k)
        return false;
      ++shiftCount[shift];
    }

    return true;
  }
};
