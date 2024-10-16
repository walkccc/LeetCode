class Solution {
 public:
  int winningPlayerCount(int n, vector<vector<int>>& pick) {
    constexpr int kMaxColor = 10;
    int ans = 0;
    vector<vector<int>> counts(n, vector<int>(kMaxColor + 1));

    for (const vector<int>& p : pick) {
      const int player = p[0];
      const int color = p[1];
      ++counts[player][color];
    }

    for (int i = 0; i < n; ++i) {
      int maxCount = 0;
      for (const int freq : counts[i])
        maxCount = max(maxCount, freq);
      if (maxCount > i)
        ++ans;
    }

    return ans;
  }
};
