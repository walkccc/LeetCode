class Solution {
 public:
  vector<int> vowelStrings(vector<string>& words,
                           vector<vector<int>>& queries) {
    vector<int> ans;
    // prefix[i] := # of first i words that start and end with a vowel
    vector<int> prefix(words.size() + 1);

    for (int i = 0; i < words.size(); ++i)
      prefix[i + 1] += prefix[i] + startsAndEndsWithVowel(words[i]);

    for (const vector<int>& query : queries) {
      const int l = query[0];
      const int r = query[1];
      ans.push_back(prefix[r + 1] - prefix[l]);
    }

    return ans;
  }

 private:
  bool startsAndEndsWithVowel(const string& word) {
    return isVowel(word.front()) && isVowel(word.back());
  }

  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiou";
    return kVowels.find(c) != string_view::npos;
  }
};
