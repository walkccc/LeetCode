class Solution {
  public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
    int ans = 0;
    Map<Integer, Integer> mem = new HashMap<>();

    for (int i = 0; i < n; ++i)
      ans = Math.max(ans, dfs(i, headID, manager, informTime, mem));

    return ans;
  }

  int dfs(int i, int headID, int[] manager, int[] informTime, Map<Integer, Integer> mem) {
    if (mem.containsKey(i))
      return mem.get(i);
    if (i == headID)
      return 0;

    final int parent = manager[i];
    mem.put(i, informTime[parent] + dfs(parent, headID, manager, informTime, mem));
    return mem.get(i);
  }
}
