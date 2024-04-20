class Solution {
 public:
  int maxSubstringLength(string s) {
    int ans = -1;
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (int n = 1; n <= 26; ++n)
      ans = max(ans, maxSubstringLengthWithNUniqueLetters(s, n, count));

    return ans;
  }

 private:
  // Similar to 395. Longest Substring with At Least K Repeating Characters
  int maxSubstringLengthWithNUniqueLetters(const string& s, int n,
                                           const vector<int>& allCount) {
    int res = -1;
    // the number of unique letters
    int uniqueLetters = 0;
    // the number of letters that have all their frequency in the substring
    int lettersHavingAllFreq = 0;
    vector<int> count(26);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (++count[s[r] - 'a'] == 1)
        ++uniqueLetters;
      if (count[s[r] - 'a'] == allCount[s[r] - 'a'])
        ++lettersHavingAllFreq;
      while (uniqueLetters > n) {
        if (count[s[l] - 'a'] == allCount[s[l] - 'a'])
          --lettersHavingAllFreq;
        if (--count[s[l] - 'a'] == 0)
          --uniqueLetters;
        ++l;
      }
      // Since both the number of unique letters and the number of letters
      // having all their frequency are equal to n, this is a valid window.
      // Implcit: uniqueLetters == n
      if (lettersHavingAllFreq == n && r - l + 1 < s.length())
        res = max(res, r - l + 1);
    }

    return res;
  }
};
