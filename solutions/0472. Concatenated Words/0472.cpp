class Solution {
 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    vector<string> ans;
    unordered_set<string> wordsSet{begin(words), end(words)};
    unordered_map<string, bool> memo;

    function<bool(const string&)> isConcat = [&](const string& s) {
      if (memo.count(s)) return memo[s];

      for (int i = 1; i < s.length(); ++i) {
        const string prefix = s.substr(0, i);
        const string suffix = s.substr(i);
        if (wordsSet.count(prefix) &&
            (wordsSet.count(suffix) || isConcat(suffix)))
          return memo[s] = true;
      }

      return memo[s] = false;
    };

    for (const string& word : words)
      if (isConcat(word))
        ans.push_back(word);

    return ans;
  }
};