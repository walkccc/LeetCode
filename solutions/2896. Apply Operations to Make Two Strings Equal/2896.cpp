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
    dp.resize(diffIndices.size(), -1.0);
    return minOperations(diffIndices, 0, x);
  }

 private:
  vector<double> dp;

  double minOperations(const vector<int>& diffIndices, int i, double x) {
    if (i == diffIndices.size())
      return 0;
    if (i == diffIndices.size() - 1)
      return x / 2;
    if (dp[i] != -1.0)
      return dp[i];
    return dp[i] = min(minOperations(diffIndices, i + 1, x) + x / 2,
                       minOperations(diffIndices, i + 2, x) +
                           diffIndices[i + 1] - diffIndices[i]);
  }

  vector<int> getDiffIndices(const string& s1, const string& s2) {
    vector<int> diffIndices;
    for (int i = 0; i < s1.length(); ++i)
      if (s1[i] != s2[i])
        diffIndices.push_back(i);
    return diffIndices;
  }
};
