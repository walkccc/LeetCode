class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    const int n = costs.size() / 2;
    int ans = 0;

    // How much money can we save if we fly a person to A instead of B?
    // To save money, we should
    //   1) fly the person with the max saving to A
    //   2) fly the person with the min saving to B
    sort(begin(costs), end(costs), [](const auto& a, const auto& b) {
      // sort in descending order by the money saved
      // if we fly a person to A instead of B
      return a[1] - a[0] > b[1] - b[0];
    });

    for (int i = 0; i < n; ++i)
      ans += costs[i][0] + costs[i + n][1];

    return ans;
  }
};
