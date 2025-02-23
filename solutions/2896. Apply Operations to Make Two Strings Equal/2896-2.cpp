class Solution {
 public:
  int minOperations(string s1, string s2, int x) {
    const vector<int> diffIndices = getDiffIndices(s1, s2);
    if (diffIndices.empty())
      return 0;
    // It's impossible to make two strings equal if there are an odd number of
    // differences.
    if (diffIndices.size() % 2 == 1)
      return -1;

    vector<double> dp(diffIndices.size() + 1, DBL_MAX);
    dp.back() = 0;
    dp[diffIndices.size() - 1] = x / 2.0;

    for (int i = diffIndices.size() - 2; i >= 0; --i)
      dp[i] = min(dp[i + 1] + x / 2.0,
                  dp[i + 2] + diffIndices[i + 1] - diffIndices[i]);

    return dp[0];
  }

 private:
  vector<int> getDiffIndices(const string& s1, const string& s2) {
    vector<int> diffIndices;
    for (int i = 0; i < s1.length(); ++i)
      if (s1[i] != s2[i])
        diffIndices.push_back(i);
    return diffIndices;
  }
};
