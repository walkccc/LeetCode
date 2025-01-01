class Solution {
 public:
  string makeAntiPalindrome(string s) {
    const int n = s.length();
    int i = n / 2;
    ranges::sort(s);
    if (s[i] != s[n - i - 1])
      return s;

    int j = getFirstDiffIndexInSecondHalf(s);
    while (s[i] == s[n - i - 1]) {
      if (j == n)
        return "-1";
      swap(s[i++], s[j++]);
    }

    return s;
  }

 private:
  // Returns the first index in s[n / 2..n) that is different from the first
  // letter of the second half, s[n / 2].
  int getFirstDiffIndexInSecondHalf(const string& s) {
    const int n = s.size();
    const char firstLetter = s[n / 2];
    int firstDiffIndex = n / 2;
    while (firstDiffIndex < n && s[firstDiffIndex] == firstLetter)
      ++firstDiffIndex;
    return firstDiffIndex;
  }
};
