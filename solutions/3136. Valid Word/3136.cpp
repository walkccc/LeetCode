class Solution {
 public:
  bool isValid(string word) {
    return word.length() >= 3 &&
           ranges::all_of(word, [](char c) { return isalnum(c); }) &&
           ranges::any_of(word, isVowel) && ranges::any_of(word, isConsonant);
  }

 private:
  static bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiouAEIOU";
    return kVowels.find(c) != string_view::npos;
  }

  static bool isConsonant(char c) {
    return isalpha(c) && !isVowel(c);
  }
};
