class Solution {
 public:
  long long countVowels(string word) {
    // dp[i] := sum of the # of vowels of word[:i], ..., word[i - 1:i]
    vector<long long> dp(word.length() + 1);

    for (int i = 1; i <= word.length(); ++i) {
      dp[i] = dp[i - 1];
      if (string("aeiou").find(word[i - 1]) != string::npos)
        dp[i] += i;
    }

    return accumulate(begin(dp), end(dp), 0LL);
  }
};
