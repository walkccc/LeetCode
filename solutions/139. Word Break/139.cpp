class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    return wordBreak(s, {wordDict.begin(), wordDict.end()}, {});
  }

 private:
  bool wordBreak(const string& s, const unordered_set<string>&& wordSet,
                 unordered_map<string, bool>&& mem) {
    if (wordSet.contains(s))
      return true;
    if (const auto it = mem.find(s); it != mem.cend())
      return it->second;

    // 1 <= prefix.length() < s.length()
    for (int i = 1; i < s.length(); ++i) {
      const string& prefix = s.substr(0, i);
      const string& suffix = s.substr(i);
      if (wordSet.contains(prefix) &&
          wordBreak(suffix, std::move(wordSet), std::move(mem)))
        return mem[s] = true;
    }

    return mem[s] = false;
  }
};
