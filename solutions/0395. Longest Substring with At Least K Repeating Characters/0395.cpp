class Solution {
 public:
  int longestSubstring(string s, int k) {
    int ans = 0;
    for (int n = 1; n <= 26; ++n)
      ans = max(ans, longestSubstringWithNUniqueCharacters(s, k, n));
    return ans;
  }

 private:
  int longestSubstringWithNUniqueCharacters(const string& s, int k, int n) {
    int ans = 0;
    int uniqueChars = 0;  // the number of unique characters in the window
    int noLessThanK = 0;  // the number of characters >= k in the window
    vector<int> count(128);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (count[s[r]] == 0)
        ++uniqueChars;
      if (++count[s[r]] == k)
        ++noLessThanK;
      while (uniqueChars > n) {
        if (count[s[l]] == k)
          --noLessThanK;
        if (--count[s[l]] == 0)
          --uniqueChars;
        ++l;
      }
      if (noLessThanK == n)  // The number of unique characters also == n.
        ans = max(ans, r - l + 1);
    }

    return ans;
  }
};
