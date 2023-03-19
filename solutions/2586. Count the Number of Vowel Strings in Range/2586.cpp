class Solution {
 public:
  int vowelStrings(vector<string>& words, int left, int right) {
    return count_if(begin(words) + left, begin(words) + right + 1,
                    [=](const string& word) {
      return isVowel(word.front()) && isVowel(word.back());
    });
  }

 private:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
