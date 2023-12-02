class Solution {
 public:
  string reformat(string s) {
    const int countAlpha =
        ranges::count_if(s, [](char c) { return isalpha(c); });
    const int countDigit = s.size() - countAlpha;
    if (abs(countAlpha - countDigit) >= 2)
      return "";

    // Initialize the starting index. e.g. "a0a0a" or "0a0a0".
    const int alphaStartingIndex = countAlpha >= countDigit ? 0 : 1;

    // Place all alphas in the indices 0, 2, 4, 6, ... or 1, 3, 5, 7, ....
    for (int i = 0, j = alphaStartingIndex; i < s.length(); ++i) {
      if (i < j && i % 2 == alphaStartingIndex)
        continue;  // The `s[i]` has been set.
      if (!isalpha(s[i]))
        continue;
      swap(s[i], s[j]);
      j += 2;
      --i;
    }

    return s;
  }
};
