class Solution {
 public:
  int minimumLengthEncoding(vector<string>& words) {
    unordered_set<string_view> wordsSet(begin(words), end(words));

    for (const auto& word : words) {
      const string_view sv(word);
      for (int i = 1; i < word.length(); ++i)
        wordsSet.erase(sv.substr(i));
    }

    return accumulate(
        begin(wordsSet), end(wordsSet), 0,
        [](int accu, const auto& sv) { return accu + sv.length() + 1; });
  }
};
