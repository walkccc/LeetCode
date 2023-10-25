class Solution {
 public:
  int leastOpsExpressTarget(int x, int target) {
    return dfs(x, target, {});
  }

 private:
  int dfs(int x, int target, unordered_map<int, int>&& memo) {
    if (const auto it = memo.find(target); it != memo.cend())
      return it->second;
    if (x > target)
      return min(2 * target - 1, 2 * (x - target));
    if (x == target)
      return 0;

    long prod = x;
    int n = 0;
    while (prod < target) {
      prod *= x;
      ++n;
    }
    if (prod == target)
      return memo[target] = n;

    int ans = dfs(x, target - prod / x, move(memo)) + n;
    if (prod < 2 * target)
      ans = min(ans, dfs(x, prod - target, move(memo)) + n + 1);
    return memo[target] = ans;
  }
};
