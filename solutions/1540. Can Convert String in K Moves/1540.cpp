class Solution {
 public:
  bool canConvertString(string s, string t, int k) {
    if (s.length() != t.length())
      return false;

    // E.g. s = "aab", t = "bbc", so shiftCount[1] = 3
    // For a -> b, need 1 move
    //     a -> b, need 1 + 26 moves
    //     b -> c, need 1 + 26 * 2 moves
    vector<int> shiftCount(26);

    for (int i = 0; i < s.length(); ++i)
      ++shiftCount[(t[i] - s[i] + 26) % 26];

    for (int shift = 1; shift < 26; ++shift)
      if (shift + 26 * (shiftCount[shift] - 1) > k)
        return false;

    return true;
  }
};
