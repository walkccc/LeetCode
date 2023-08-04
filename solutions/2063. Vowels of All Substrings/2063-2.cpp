class Solution {
 public:
  long long countVowels(string word) {
    long long ans = 0;

    for (int i = 0; i < word.length(); ++i)
      if (isVowel(word[i]))
        ans += (i + 1) * (word.length() - i);

    return ans;
  }

 private:
  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiou";
    return kVowels.find(c) != string_view::npos;
  }
};
