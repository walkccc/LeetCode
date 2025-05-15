class Solution {
 public:
  vector<int> assignBikes(vector<vector<int>>& workers,
                          vector<vector<int>>& bikes) {
    const int n = workers.size();
    const int m = bikes.size();
    vector<int> ans(n, -1);
    vector<bool> usedBikes(m);
    // buckets[k] := (i, j), where k = dist(workers[i], bikes[j])
    vector<vector<pair<int, int>>> buckets(2001);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        buckets[dist(workers[i], bikes[j])].emplace_back(i, j);

    for (int k = 0; k < 2001; ++k)
      for (const auto& [i, j] : buckets[k])
        if (ans[i] == -1 && !usedBikes[j]) {
          ans[i] = j;
          usedBikes[j] = true;
        }

    return ans;
  }

 private:
  int dist(const vector<int>& p1, const vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
  }
};
