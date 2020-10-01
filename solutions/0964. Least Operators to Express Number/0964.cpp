class Solution {
 public:
  int leastOpsExpressTarget(int x, int target) { return dfs(x, target); }

 private:
  unordered_map<int, int> memo;

  int dfs(int x, int target) {
    if (memo.count(target)) return memo[target];
    if (x > target) return min(2 * target - 1, 2 * (x - target));
    if (x == target) return 0;

    long prod = x;
    int n = 0;

    while (prod < target) {
      prod *= x;
      ++n;
    }

    if (prod == target) return memo[target] = n;

    memo[target] = INT_MAX;
    if (prod < 2 * target) memo[target] = dfs(x, prod - target) + n + 1;
    memo[target] = min(memo[target], dfs(x, target - prod / x) + n);

    return memo[target];
  }
};