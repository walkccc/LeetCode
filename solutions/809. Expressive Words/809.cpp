class Solution {
 public:
  int expressiveWords(string s, vector<string>& words) {
    int ans = 0;

    for (const string& word : words)
      if (isStretchy(s, word))
        ++ans;

    return ans;
  }

 private:
  bool isStretchy(const string& s, const string& word) {
    const int n = s.length();
    const int m = word.length();

    int j = 0;
    for (int i = 0; i < n; ++i)
      if (j < m && s[i] == word[j])
        ++j;
      else if (i > 1 && s[i] == s[i - 1] && s[i - 1] == s[i - 2])
        continue;
      else if (0 < i && i + 1 < n && s[i - 1] == s[i] && s[i] == s[i + 1])
        continue;
      else
        return false;

    return j == m;
  }
};
