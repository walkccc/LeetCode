class Solution {
 public:
  string oddString(vector<string>& words) {
    const vector<pair<string, string>> wordAndDiffStrs =
        getWordAndDiffStrs(words);
    unordered_map<string, int> diffStrCount;

    for (const auto& [_, diffStr] : wordAndDiffStrs)
      ++diffStrCount[diffStr];

    for (const auto& [word, diffStr] : wordAndDiffStrs)
      if (diffStrCount[diffStr] == 1)
        return word;

    throw;
  }

 private:
  // Returns the pairs of the word and its corresponding difference string.
  // e.g. [("adc", "3#-1#"), ("wzy", "3#-1#"), ("abc", "1#1#")]
  vector<pair<string, string>> getWordAndDiffStrs(const vector<string>& words) {
    vector<pair<string, string>> wordAndDiffStrs;
    for (const string& word : words)
      wordAndDiffStrs.emplace_back(word, getDiffStr(word));
    return wordAndDiffStrs;
  }

  // Returns the difference string of `s`.
  // e.g. getDiffStr("adc") -> "3#-1#"
  string getDiffStr(const string& s) {
    string diffStr;
    for (int i = 1; i < s.length(); ++i)
      diffStr += to_string(s[i] - s[i - 1]) + "#";
    return diffStr;
  }
};
