class Solution {
  public int componentValue(int[] nums, int[][] edges) {
    final int n = nums.length;
    final int sum = Arrays.stream(nums).sum();
    List<Integer>[] graph = new List[n];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    for (int i = n; i > 1; --i)
      // split the tree into i parts, i.e., delete (i - 1) edges
      if (sum % i == 0 && dfs(nums, graph, 0, sum / i, new boolean[n]) == 0)
        return i - 1;

    return 0;
  }

  private static final int kMax = 1_000_000_000;

  // Returns the sum of the subtree rooted at u minus the sum of the deleted subtrees.
  private int dfs(int[] nums, List<Integer>[] graph, int u, int target, boolean[] seen) {
    int sum = nums[u];
    seen[u] = true;

    for (final int v : graph[u]) {
      if (seen[v])
        continue;
      sum += dfs(nums, graph, v, target, seen);
      if (sum > target)
        return kMax;
    }

    // Delete the tree that has sum == target
    if (sum == target)
      return 0;
    return sum;
  }
}
