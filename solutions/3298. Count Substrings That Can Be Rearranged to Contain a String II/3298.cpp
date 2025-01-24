class Solution {
 public:
  // Same as 3297. Count Substrings That Can Be Rearranged to Contain a String I
  long long validSubstringCount(string word1, string word2) {
    long ans = 0;
    int required = word2.length();
    vector<int> count(26);

    for (const char c : word2)
      ++count[c - 'a'];

    for (int l = 0, r = 0; r < word1.length(); ++r) {
      if (--count[word1[r] - 'a'] >= 0)
        --required;
      while (required == 0) {
        // Add valid substrings containing word1[l..r] to the answer. They are
        // word1[l..r], word1[l..r + 1], ..., word1[l..n - 1].
        ans += word1.length() - r;
        if (++count[word1[l++] - 'a'] > 0)
          ++required;
      }
    }

    return ans;
  }
};
