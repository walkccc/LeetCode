class Solution {
 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    vector<string> ans;
    unordered_set<string> wordSet{words.begin(), words.end()};
    unordered_map<string, bool> mem;

    for (const string& word : words)
      if (isConcat(word, wordSet, mem))
        ans.push_back(word);

    return ans;
  }

 private:
  bool isConcat(const string& s, const unordered_set<string>& wordSet,
                unordered_map<string, bool>& mem) {
    if (const auto it = mem.find(s); it != mem.cend())
      return it->second;

    for (int i = 1; i < s.length(); ++i) {
      const string prefix = s.substr(0, i);
      const string suffix = s.substr(i);
      if (wordSet.contains(prefix) &&
          (wordSet.contains(suffix) || isConcat(suffix, wordSet, mem)))
        return mem[s] = true;
    }

    return mem[s] = false;
  }
};
