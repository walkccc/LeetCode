class Solution {
  public int componentValue(int[] nums, int[][] edges) {
    final int n = nums.length;
    final int sum = Arrays.stream(nums).sum();
    List<Integer>[] tree = new List[n];

    for (int i = 0; i < tree.length; ++i)
      tree[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      tree[u].add(v);
      tree[v].add(u);
    }

    for (int i = n; i > 1; --i)
      // Split the tree into i parts, i.e. delete (i - 1) edges.
      if (sum % i == 0 && dfs(nums, tree, 0, sum / i, new boolean[n]) == 0)
        return i - 1;

    return 0;
  }

  private static final int kMax = 1_000_000_000;

  // Returns the sum of the subtree rooted at u substracting the sum of the deleted subtrees.
  private int dfs(int[] nums, List<Integer>[] tree, int u, int target, boolean[] seen) {
    int sum = nums[u];
    seen[u] = true;

    for (final int v : tree[u]) {
      if (seen[v])
        continue;
      sum += dfs(nums, tree, v, target, seen);
      if (sum > target)
        return kMax;
    }

    // Delete the tree that has sum == target.
    if (sum == target)
      return 0;
    return sum;
  }
}
