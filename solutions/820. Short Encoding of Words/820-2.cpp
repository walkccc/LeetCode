class Solution {
 public:
  int minimumLengthEncoding(vector<string>& words) {
    unordered_set<string_view> wordsSet(words.begin(), words.end());

    for (const string& word : words) {
      const string_view sv(word);
      for (int i = 1; i < word.length(); ++i)
        wordsSet.erase(sv.substr(i));
    }

    return accumulate(wordsSet.begin(), wordsSet.end(), 0,
                      [](int subtotal, const auto& sv) {
      return subtotal + sv.length() + 1;
    });
  }
};
