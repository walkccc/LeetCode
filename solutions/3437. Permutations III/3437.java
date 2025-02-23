class Solution {
  public int[][] permute(int n) {
    List<List<Integer>> ans = new ArrayList<>();
    dfs(n, new boolean[n + 1], new ArrayList<>(), ans);
    return ans.stream()
        .map(A -> A.stream().mapToInt(Integer::intValue).toArray())
        .toArray(int[][] ::new);
  }

  private void dfs(int n, boolean[] used, List<Integer> path, List<List<Integer>> ans) {
    if (path.size() == n) {
      ans.add(new ArrayList<>(path));
      return;
    }

    for (int num = 1; num <= n; ++num) {
      if (used[num])
        continue;
      if (!path.isEmpty() && path.get(path.size() - 1) % 2 == num % 2)
        continue;
      used[num] = true;
      path.add(num);
      dfs(n, used, path, ans);
      path.remove(path.size() - 1);
      used[num] = false;
    }
  }
}
