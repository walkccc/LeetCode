class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    const int n = cost.size();

    for (int i = 2; i < n; ++i)
      cost[i] += min(cost[i - 1], cost[i - 2]);

    return min(cost[n - 1], cost[n - 2]);
  }
};