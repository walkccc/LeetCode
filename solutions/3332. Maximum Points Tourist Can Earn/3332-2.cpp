class Solution {
 public:
  int maxScore(int n, int k, vector<vector<int>>& stayScore,
               vector<vector<int>>& travelScore) {
    // dp[j] := the maximum score after days so far being at city j
    vector<int> dp(n);

    for (int i = 0; i < k; ++i) {
      vector<int> newDp(n);
      for (int dest = 0; dest < n; ++dest) {
        // 1. Stay at the current city.
        newDp[dest] = dp[dest] + stayScore[i][dest];
        // 2. Travel from any other city.
        for (int curr = 0; curr < n; ++curr)
          if (curr != dest)
            newDp[dest] = max(newDp[dest], dp[curr] + travelScore[curr][dest]);
      }
      dp = std::move(newDp);
    }

    return ranges::max(dp);
  }
};
