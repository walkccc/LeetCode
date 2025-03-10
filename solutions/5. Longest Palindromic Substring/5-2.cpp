class Solution {
 public:
  string longestPalindrome(string s) {
    const string t = join('@' + s + '$', /*delimiter=*/'#');
    const vector<int> p = manacher(t);
    int maxPalindromeLength = 0;
    int bestCenter = -1;

    for (int i = 0; i < p.size(); ++i)
      if (p[i] > maxPalindromeLength) {
        maxPalindromeLength = p[i];
        bestCenter = i;
      }

    const int l = (bestCenter - maxPalindromeLength) / 2;
    const int r = (bestCenter + maxPalindromeLength) / 2;
    return s.substr(l, r - l);
  }

 private:
  // Returns an array `p` s.t. `p[i]` is the length of the longest palindrome
  // centered at `t[i]`, where `t` is a string with delimiters and sentinels.
  vector<int> manacher(const string& t) {
    vector<int> p(t.length());
    int center = 0;
    for (int i = 1; i < t.length() - 1; ++i) {
      const int rightBoundary = center + p[center];
      const int mirrorIndex = center - (i - center);
      if (rightBoundary > i)
        p[i] = min(rightBoundary - i, p[mirrorIndex]);
      // Try to expand the palindrome centered at i.
      while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
        ++p[i];
      // If a palindrome centered at i expands past `rightBoundary`, adjust
      // the center based on the expanded palindrome.
      if (i + p[i] > rightBoundary)
        center = i;
    }
    return p;
  }

  string join(const string& s, char delimiter) {
    string joined;
    for (int i = 0; i < s.length() - 1; ++i) {
      joined += s[i];
      joined += delimiter;
    }
    joined += s.back();
    return joined;
  }
};
