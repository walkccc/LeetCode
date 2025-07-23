class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    const int n = costs.size() / 2;
    int ans = 0;

    // How much money can we save if we fly a person to A instead of B?
    // To save money, we should
    //   1. Fly the person with the maximum saving to A.
    //   2. Fly the person with the minimum saving to B.

    // Sort `costs` in ascending order by the money saved if we fly a person to
    // B instead of A.
    ranges::sort(costs, ranges::less{},
                 [](const vector<int>& cost) { return cost[0] - cost[1]; });

    for (int i = 0; i < n; ++i)
      ans += costs[i][0] + costs[i + n][1];

    return ans;
  }
};
