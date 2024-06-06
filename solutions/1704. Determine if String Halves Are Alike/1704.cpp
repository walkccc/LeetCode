class Solution {
 public:
  bool halvesAreAlike(string s) {
    const string a = s.substr(0, s.length() / 2);
    const string b = s.substr(s.length() / 2);
    const int aVowelsCount =
        ranges::count_if(a, [=](char c) { return isVowel(c); });
    const int bVowelsCount =
        ranges::count_if(b, [=](char c) { return isVowel(c); });
    return aVowelsCount == bVowelsCount;
  }

 private:
  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiouAEIOU";
    return kVowels.find(c) != string_view::npos;
  }
};
