class Solution {
  public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
    int ans = 0;
    Map<Integer, Integer> memo = new HashMap<>();

    for (int i = 0; i < n; ++i)
      ans = Math.max(ans, dfs(i, headID, manager, informTime, memo));

    return ans;
  }

  int dfs(int i, int headID, int[] manager, int[] informTime, Map<Integer, Integer> memo) {
    if (memo.containsKey(i))
      return memo.get(i);
    if (i == headID)
      return 0;

    final int parent = manager[i];
    memo.put(i, informTime[parent] + dfs(parent, headID, manager, informTime, memo));
    return memo.get(i);
  }
}
