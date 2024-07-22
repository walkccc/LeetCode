class Solution {
 public:
  int longestSubstring(string s, int k) {
    int ans = 0;
    for (int n = 1; n <= 26; ++n)
      ans = max(ans, longestSubstringWithNUniqueLetters(s, k, n));
    return ans;
  }

 private:
  int longestSubstringWithNUniqueLetters(const string& s, int k, int n) {
    int res = 0;
    int uniqueLetters = 0;       // the number of unique letters
    int lettersHavingKFreq = 0;  // the number of letters having frequency >= k
    vector<int> count(26);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (++count[s[r] - 'a'] == 1)
        ++uniqueLetters;
      if (count[s[r] - 'a'] == k)
        ++lettersHavingKFreq;
      while (uniqueLetters > n) {
        if (count[s[l] - 'a'] == k)
          --lettersHavingKFreq;
        if (--count[s[l] - 'a'] == 0)
          --uniqueLetters;
        ++l;
      }
      // Since both the number of unique letters and the number of letters
      // having frequency >= k are equal to n, this is a valid window.
      if (lettersHavingKFreq == n)  // Implicit: uniqueLetters == n
        res = max(res, r - l + 1);
    }

    return res;
  }
};
