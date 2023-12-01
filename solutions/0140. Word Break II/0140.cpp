class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet{wordDict.begin(), wordDict.end()};
    unordered_map<string, vector<string>> memo;
    return wordBreak(s, wordSet, memo);
  }

 private:
  vector<string> wordBreak(const string& s,
                           const unordered_set<string>& wordSet,
                           unordered_map<string, vector<string>>& memo) {
    if (const auto it = memo.find(s); it != memo.cend())
      return it->second;

    vector<string> ans;

    // 1 <= prefix.length() < s.length()
    for (int i = 1; i < s.length(); ++i) {
      const string& prefix = s.substr(0, i);
      const string& suffix = s.substr(i);
      if (wordSet.count(prefix))
        for (const string& word : wordBreak(suffix, wordSet, memo))
          ans.push_back(prefix + " " + word);
    }

    // `wordSet` contains the whole string s, so don't add any space.
    if (wordSet.count(s))
      ans.push_back(s);

    return memo[s] = ans;
  }
};
