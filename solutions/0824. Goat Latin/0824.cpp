class Solution {
 public:
  string toGoatLatin(string sentence) {
    string ans;
    istringstream iss(sentence);

    int i = 1;
    for (string word; iss >> word;) {
      if (i > 1)
        ans += ' ';
      if (isVowel(word[0]))
        ans += word;
      else
        ans += word.substr(1) + word[0];
      ans += "ma" + string(i++, 'a');
    }

    return ans;
  }

 private:
  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiouAEIOU";
    return kVowels.find(c) != string_view::npos;
  }
};
