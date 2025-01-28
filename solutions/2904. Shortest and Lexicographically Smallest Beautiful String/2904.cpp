class Solution {
 public:
  // Same as 76. Minimum Window Substring
  string shortestBeautifulSubstring(string s, int k) {
    int bestLeft = -1;
    int minLength = s.length() + 1;
    int ones = 0;

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (s[r] == '1')
        ++ones;
      while (ones == k) {
        if (r - l + 1 < minLength) {
          bestLeft = l;
          minLength = r - l + 1;
        } else if (r - l + 1 == minLength &&
                   s.compare(l, minLength, s, bestLeft, minLength) < 0) {
          bestLeft = l;
        }
        if (s[l++] == '1')
          --ones;
      }
    }

    return bestLeft == -1 ? "" : s.substr(bestLeft, minLength);
  }
};
