class Solution {
  public List<List<Integer>> getFactors(int n) {
    List<List<Integer>> ans = new ArrayList<>();
    dfs(n, 2, new ArrayList<>(), ans); // The minimum factor is 2.
    return ans;
  }

  private void dfs(int n, int s, List<Integer> path, List<List<Integer>> ans) {
    if (n == 1) {
      if (path.size() > 1)
        ans.add(new ArrayList<>(path));
      return;
    }

    for (int i = s; i <= n; ++i)
      if (n % i == 0) {
        path.add(i);
        dfs(n / i, i, path, ans);
        path.remove(path.size() - 1);
      }
  }
}
