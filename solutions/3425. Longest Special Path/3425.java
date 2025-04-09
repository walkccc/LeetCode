class Solution {
  public int[] longestSpecialPath(int[][] edges, int[] nums) {
    List<Pair<Integer, Integer>>[] graph = new List[nums.length];

    for (int i = 0; i < nums.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int w = edge[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    int[] ans = new int[2];
    ans[0] = 0; // maxLength
    ans[1] = 1; // minNodes
    dfs(graph, 0, -1, /*leftBoundary=*/0, /*prefix=*/new ArrayList<>(List.of(0)),
        /*lastSeenDepth=*/new HashMap<>(), nums, ans);
    return ans;
  }

  private void dfs(List<Pair<Integer, Integer>>[] graph, int u, int prev, int leftBoundary,
                   List<Integer> prefix, Map<Integer, Integer> lastSeenDepth, int[] nums,
                   int[] ans) {
    final int prevDepth = lastSeenDepth.getOrDefault(nums[u], 0);
    lastSeenDepth.put(nums[u], prefix.size());
    leftBoundary = Math.max(leftBoundary, prevDepth);

    final int length = prefix.get(prefix.size() - 1) - prefix.get(leftBoundary);
    final int nodes = prefix.size() - leftBoundary;
    if (length > ans[0] || (length == ans[0] && nodes < ans[1])) {
      ans[0] = length;
      ans[1] = nodes;
    }

    for (Pair<Integer, Integer> pair : graph[u]) {
      final int v = pair.getKey();
      final int w = pair.getValue();
      if (v == prev)
        continue;
      prefix.add(prefix.get(prefix.size() - 1) + w);
      dfs(graph, v, u, leftBoundary, prefix, lastSeenDepth, nums, ans);
      prefix.remove(prefix.size() - 1);
    }

    lastSeenDepth.put(nums[u], prevDepth);
  }
}
