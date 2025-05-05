class Solution {
  public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
    int[] ans = new int[queries.length];
    Map<Integer, Integer> nodeToFarthestNode = new HashMap<>();

    for (int i = 0; i < n - 1; ++i)
      nodeToFarthestNode.put(i, i + 1);

    for (int i = 0; i < queries.length; ++i) {
      final int u = queries[i][0];
      final int v = queries[i][1];
      // If `u` exists in the map and `v` is farther than the current farthest
      // node for `u`, we need to update the map and remove intermediate nodes.
      if (nodeToFarthestNode.containsKey(u) && nodeToFarthestNode.get(u) < v) {
        int node = nodeToFarthestNode.get(u);
        while (node < v)
          node = nodeToFarthestNode.remove(node);
        nodeToFarthestNode.put(u, v);
      }
      ans[i] = nodeToFarthestNode.size();
    }

    return ans;
  }
}
