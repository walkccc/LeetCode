class Solution {
 public:
  int minCost(vector<vector<int>>& costs) {
    for (int i = 1; i < costs.size(); ++i) {
      costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
      costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
      costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
    }

    return ranges::min(costs.back());
  }
};
