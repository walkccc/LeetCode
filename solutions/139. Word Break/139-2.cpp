class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    return wordBreak(s, 0, {wordDict.begin(), wordDict.end()},
                     vector<int>(s.length(), -1));
  }

 private:
  // Returns true if s[i..n) can be segmented.
  bool wordBreak(const string& s, int i, const unordered_set<string>&& wordSet,
                 vector<int>&& mem) {
    if (i == s.length())
      return true;
    if (mem[i] != -1)
      return mem[i];

    for (int j = i + 1; j <= s.length(); ++j)
      if (wordSet.contains(s.substr(i, j - i)) &&
          wordBreak(s, j, std::move(wordSet), std::move(mem)))
        return mem[i] = 1;

    return mem[i] = 0;
  }
};
