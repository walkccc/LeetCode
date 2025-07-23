class Solution {
 public:
  int possibleStringCount(string word, int k) {
    const vector<int> groups = getConsecutiveLetters(word);
    const int totalCombinations =
        accumulate(groups.begin(), groups.end(), 1L,
                   [](long acc, int group) { return acc * group % kMod; });
    if (k <= groups.size())
      return totalCombinations;

    // dp[j] := the number of ways to form strings of length j using
    // groups[0..i]
    vector<int> dp(k);
    dp[0] = 1;  // Base case: empty string

    for (int i = 0; i < groups.size(); ++i) {
      vector<int> newDp(k);
      int windowSum = 0;
      int group = groups[i];
      for (int j = i; j < k; ++j) {
        newDp[j] = (newDp[j] + windowSum) % kMod;
        windowSum = (windowSum + dp[j]) % kMod;
        if (j >= group)
          windowSum = (windowSum - dp[j - group] + kMod) % kMod;
      }
      dp = std::move(newDp);
    }

    const int invalidCombinations =
        accumulate(dp.begin(), dp.end(), 0,
                   [](int acc, int count) { return (acc + count) % kMod; });
    return (totalCombinations - invalidCombinations + kMod) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Returns consecutive identical letters in the input string.
  // e.g. "aabbbc" -> [2, 3, 1].
  vector<int> getConsecutiveLetters(const string& word) {
    vector<int> groups;
    int group = 1;
    for (int i = 1; i < word.length(); ++i)
      if (word[i] == word[i - 1]) {
        ++group;
      } else {
        groups.push_back(group);
        group = 1;
      }
    groups.push_back(group);
    return groups;
  }
};
