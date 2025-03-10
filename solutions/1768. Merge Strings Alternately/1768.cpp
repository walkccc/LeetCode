class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    const int n = min(word1.length(), word2.length());
    string prefix;

    for (int i = 0; i < n; ++i) {
      prefix += word1[i];
      prefix += word2[i];
    }

    return prefix + word1.substr(n) + word2.substr(n);
  }
};
