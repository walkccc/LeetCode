class Solution {
 public:
  int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    // dp[i] := the minimum distance to assign bikes j (bitmask)
    dp.resize(1 << bikes.size());
    return assignBikes(workers, bikes, 0, 0);
  }

 private:
  vector<int> dp;

  int assignBikes(const vector<vector<int>>& workers,
                  const vector<vector<int>>& bikes, int s, int bikeUsed) {
    if (s == workers.size())
      return 0;
    if (dp[bikeUsed])
      return dp[bikeUsed];

    int ans = INT_MAX;

    for (int i = 0; i < bikes.size(); ++i) {
      if (bikeUsed >> i & 1)
        continue;
      ans = min(ans, dist(workers[s], bikes[i]) +
                         assignBikes(workers, bikes, s + 1, bikeUsed | 1 << i));
    }

    return dp[bikeUsed] = ans;
  }

  int dist(const vector<int>& p1, const vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }
};
