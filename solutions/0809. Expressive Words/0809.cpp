class Solution {
 public:
  int expressiveWords(string S, vector<string>& words) {
    int ans = 0;

    for (const string& word : words)
      if (isStretchy(S, word))
        ++ans;

    return ans;
  }

 private:
  bool isStretchy(const string& S, const string& word) {
    const int n = S.length();
    const int m = word.length();

    int j = 0;
    for (int i = 0; i < n; ++i)
      if (j < m && S[i] == word[j])
        ++j;
      else if (i > 1 && S[i] == S[i - 1] && S[i - 1] == S[i - 2])
        continue;
      else if (0 < i && i + 1 < n && S[i - 1] == S[i] && S[i] == S[i + 1])
        continue;
      else
        return false;

    return j == m;
  }
};
