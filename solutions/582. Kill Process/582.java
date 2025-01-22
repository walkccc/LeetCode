class Solution {
  public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
    List<Integer> ans = new ArrayList<>();
    Map<Integer, List<Integer>> tree = new HashMap<>();

    for (int i = 0; i < pid.size(); ++i) {
      if (ppid.get(i) == 0)
        continue;
      tree.putIfAbsent(ppid.get(i), new ArrayList<>());
      tree.get(ppid.get(i)).add(pid.get(i));
    }

    dfs(tree, kill, ans);
    return ans;
  }

  private void dfs(Map<Integer, List<Integer>> tree, int u, List<Integer> ans) {
    ans.add(u);
    for (final int v : tree.getOrDefault(u, new ArrayList<>()))
      dfs(tree, v, ans);
  }
}
