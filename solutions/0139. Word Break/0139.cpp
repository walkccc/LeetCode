class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet{begin(wordDict), end(wordDict)};
    unordered_map<string, bool> memo;
    return wordBreak(s, wordSet, memo);
  }

 private:
  bool wordBreak(const string& s, const unordered_set<string>& wordSet,
                 unordered_map<string, bool>& memo) {
    if (wordSet.count(s))
      return true;
    if (memo.count(s))
      return memo[s];

    // 1 <= prefix.length() < s.length()
    for (int i = 1; i < s.length(); ++i) {
      const string& prefix = s.substr(0, i);
      const string& suffix = s.substr(i);
      if (wordSet.count(prefix) && wordBreak(suffix, wordSet, memo))
        return memo[s] = true;
    }

    return memo[s] = false;
  }
};
