class Solution {
 public:
  int vowelStrings(vector<string>& words, int left, int right) {
    return count_if(words.begin() + left, words.begin() + right + 1,
                    [=](const string& word) {
      return isVowel(word.front()) && isVowel(word.back());
    });
  }

 private:
  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiou";
    return kVowels.find(c) != string_view::npos;
  }
};
