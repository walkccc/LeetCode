class Solution {
 public:
  string reverseVowels(string s) {
    int l = 0;
    int r = s.length() - 1;

    while (l < r) {
      while (l < r && !isVowel(s[l]))
        ++l;
      while (l < r && !isVowel(s[r]))
        --r;
      swap(s[l++], s[r--]);
    }

    return s;
  }

 private:
  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiouAEIOU";
    return kVowels.find(c) != string_view::npos;
  }
};
