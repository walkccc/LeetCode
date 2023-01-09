class Solution {
 public:
  int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts,
                  int target) {
    int ans = INT_MAX;

    for (const int baseCost : baseCosts)
      dfs(toppingCosts, 0, target, baseCost, ans);

    return ans;
  }

 private:
  void dfs(const vector<int>& toppingCosts, int i, int target, int currCost,
           int& ans) {
    if (abs(currCost - target) < abs(ans - target))
      ans = currCost;
    if (i == toppingCosts.size() || currCost >= target)
      return;

    for (int k = 0; k < 3; ++k)
      dfs(toppingCosts, i + 1, target, currCost + k * toppingCosts[i], ans);
  }
};
