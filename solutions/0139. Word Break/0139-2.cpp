class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet{begin(wordDict), end(wordDict)};
    unordered_map<string, bool> memo;

    function<bool(const string&)> wordBreak = [&](const string& s) {
      if (wordSet.count(s)) return true;
      if (memo.count(s)) return memo[s];

      for (int i = 1; i < s.length(); ++i)
        if (wordSet.count(s.substr(0, i)) && wordBreak(s.substr(i)))
          return memo[s] = true;

      return memo[s] = false;
    };

    return wordBreak(s);
  }
};