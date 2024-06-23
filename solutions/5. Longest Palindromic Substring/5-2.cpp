class Solution {
 public:
  string longestPalindrome(string s) {
    // '@' and '$' signs serve as sentinels appended to each end to avoid bounds
    // checking.
    const string& t = join('@' + s + '$', '#');
    const int n = t.length();
    // t[i - maxExtends[i]..i) ==
    // t[i + 1..i + maxExtends[i]]
    vector<int> maxExtends(n);
    int center = 0;

    for (int i = 1; i < n - 1; ++i) {
      const int rightBoundary = center + maxExtends[center];
      const int mirrorIndex = center - (i - center);
      maxExtends[i] =
          rightBoundary > i && min(rightBoundary - i, maxExtends[mirrorIndex]);

      // Attempt to expand the palindrome centered at i.
      while (t[i + 1 + maxExtends[i]] == t[i - 1 - maxExtends[i]])
        ++maxExtends[i];

      // If a palindrome centered at i expand past `rightBoundary`, adjust
      // center based on expanded palindrome.
      if (i + maxExtends[i] > rightBoundary)
        center = i;
    }

    // Find `maxExtend` and `bestCenter`.
    int maxExtend = 0;
    int bestCenter = -1;

    for (int i = 0; i < n; ++i)
      if (maxExtends[i] > maxExtend) {
        maxExtend = maxExtends[i];
        bestCenter = i;
      }

    const int l = (bestCenter - maxExtend) / 2;
    const int r = (bestCenter + maxExtend) / 2;
    return s.substr(l, r - l);
  }

 private:
  string join(const string& s, char c) {
    string joined;
    for (int i = 0; i < s.length(); ++i) {
      joined += s[i];
      if (i != s.length() - 1)
        joined += c;
    }
    return joined;
  }
};
