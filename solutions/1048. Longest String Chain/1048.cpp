class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    const unordered_set<string> wordsSet{words.begin(), words.end()};
    unordered_map<string, int> mem;
    return accumulate(words.begin(), words.end(), 0,
                      [&](int acc, const string& word) {
      return max(acc, longestStrChain(word, wordsSet, mem));
    });
  }

 private:
  // Returns the longest string chain, where s is the last word.
  int longestStrChain(const string& s, const unordered_set<string>& wordsSet,
                      unordered_map<string, int>& mem) {
    if (const auto it = mem.find(s); it != mem.cend())
      return it->second;

    int res = 1;

    for (int i = 0; i < s.length(); ++i) {
      const string pred = s.substr(0, i) + s.substr(i + 1);
      if (wordsSet.contains(pred))
        res = max(res, longestStrChain(pred, wordsSet, mem) + 1);
    }

    return mem[s] = res;
  }
};
