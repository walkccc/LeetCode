class Solution {
  public int leastOpsExpressTarget(int x, int target) {
    return dfs(x, target);
  }

  private Map<Integer, Integer> memo = new HashMap<>();

  private int dfs(int x, int target) {
    if (memo.containsKey(target))
      return memo.get(target);
    if (x > target)
      return Math.min(2 * target - 1, 2 * (x - target));
    if (x == target)
      return 0;

    long prod = x;
    int n = 0;
    while (prod < target) {
      prod *= x;
      ++n;
    }
    if (prod == target) {
      memo.put(target, n);
      return memo.get(target);
    }

    int ans = dfs(x, target - (int) (prod / (long) x)) + n;
    if (prod < 2 * target)
      ans = Math.min(ans, dfs(x, (int) (prod - (long) target)) + n + 1);
    memo.put(target, ans);
    return ans;
  }
}
