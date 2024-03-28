class Solution {
 public:
  long long countVowels(string word) {
    // dp[i] := the sum of the number of vowels of word[0..i), ...,
    // word[i - 1..i)
    vector<long long> dp(word.length() + 1);

    for (int i = 1; i <= word.length(); ++i) {
      dp[i] = dp[i - 1];
      if (isVowel(word[i - 1]))
        dp[i] += i;
    }

    return accumulate(dp.begin(), dp.end(), 0LL);
  }

  bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiou";
    return kVowels.find(c) != string_view::npos;
  }
};
