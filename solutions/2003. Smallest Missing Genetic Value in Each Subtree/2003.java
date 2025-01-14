class Solution {
  public int[] smallestMissingValueSubtree(int[] parents, int[] nums) {
    final int n = parents.length;
    int[] ans = new int[n];
    Arrays.fill(ans, 1);
    List<Integer>[] tree = new List[n];
    Set<Integer> seen = new HashSet<>();
    int minMiss = 1;

    for (int i = 0; i < n; ++i)
      tree[i] = new ArrayList<>();

    for (int i = 1; i < n; ++i)
      tree[parents[i]].add(i);

    final int nodeThatsOne = getNode(nums);
    if (nodeThatsOne == -1)
      return ans;

    int u = nodeThatsOne;
    int prev = -1; // the u that just handled

    // Upward from `nodeThatsOne` to the root `u`.
    while (u != -1) {
      for (final int v : tree[u])
        if (v != prev)
          dfs(v, tree, seen, nums);
      seen.add(nums[u]);
      while (seen.contains(minMiss))
        ++minMiss;
      ans[u] = minMiss;
      prev = u;
      u = parents[u];
    }

    return ans;
  }

  private void dfs(int u, List<Integer>[] tree, Set<Integer> seen, int[] nums) {
    seen.add(nums[u]);
    for (final int v : tree[u])
      dfs(v, tree, seen, nums);
  }

  private int getNode(int[] nums) {
    for (int i = 0; i < nums.length; ++i)
      if (nums[i] == 1)
        return i;
    return -1;
  }
}
