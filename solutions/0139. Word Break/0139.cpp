class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    return wordBreak(s, {wordDict.begin(), wordDict.end()}, {});
  }

 private:
  bool wordBreak(const string& s, const unordered_set<string>&& wordSet,
                 unordered_map<string, bool>&& memo) {
    if (wordSet.count(s))
      return true;
    if (const auto it = memo.find(s); it != memo.cend())
      return it->second;

    // 1 <= prefix.length() < s.length()
    for (int i = 1; i < s.length(); ++i) {
      const string& prefix = s.substr(0, i);
      const string& suffix = s.substr(i);
      if (wordSet.count(prefix) && wordBreak(suffix, move(wordSet), move(memo)))
        return memo[s] = true;
    }

    return memo[s] = false;
  }
};
