class Solution {
 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    vector<string> ans;
    unordered_set<string> wordSet{begin(words), end(words)};
    unordered_map<string, bool> memo;

    for (const string& word : words)
      if (isConcat(word, wordSet, memo))
        ans.push_back(word);

    return ans;
  }

 private:
  bool isConcat(const string& s, const unordered_set<string>& wordSet,
                unordered_map<string, bool>& memo) {
    if (memo.count(s))
      return memo[s];

    for (int i = 1; i < s.length(); ++i) {
      const string prefix = s.substr(0, i);
      const string suffix = s.substr(i);
      if (wordSet.count(prefix) &&
          (wordSet.count(suffix) || isConcat(suffix, wordSet, memo)))
        return memo[s] = true;
    }

    return memo[s] = false;
  }
};
