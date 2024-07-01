class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    const int n = arr.size();
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(n, 2));
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < n; ++i)
      numToIndex[arr[i]] = i;

    for (int j = 0; j < n; ++j)
      for (int k = j + 1; k < n; ++k) {
        const int ai = arr[k] - arr[j];
        if (ai < arr[j] && numToIndex.count(ai)) {
          const int i = numToIndex[ai];
          dp[j][k] = dp[i][j] + 1;
          ans = max(ans, dp[j][k]);
        }
      }

    return ans;
  }
};
