class Solution {
 public:
  string removeVowels(string s) {
    s.erase(remove_if(s.begin(), s.end(), [&](char c) { return isVowel(c); }),
            s.end());
    return s;
  }

  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiou";
    return kVowels.find(c) != string_view::npos;
  }
};
