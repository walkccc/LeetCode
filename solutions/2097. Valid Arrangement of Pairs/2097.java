class Solution {
  public int[][] validArrangement(int[][] pairs) {
    List<int[]> ans = new ArrayList<>();
    Map<Integer, Deque<Integer>> graph = new HashMap<>();
    Map<Integer, Integer> outDegree = new HashMap<>();
    Map<Integer, Integer> inDegrees = new HashMap<>();

    for (int[] pair : pairs) {
      final int start = pair[0];
      final int end = pair[1];
      graph.putIfAbsent(start, new ArrayDeque<>());
      graph.get(start).push(end);
      outDegree.merge(start, 1, Integer::sum);
      inDegrees.merge(end, 1, Integer::sum);
    }

    final int startNode = getStartNode(graph, outDegree, inDegrees, pairs);
    euler(graph, startNode, ans);
    Collections.reverse(ans);
    return ans.stream().toArray(int[][] ::new);
  }

  private int getStartNode(Map<Integer, Deque<Integer>> graph, Map<Integer, Integer> outDegree,
                           Map<Integer, Integer> inDegrees, int[][] pairs) {
    for (final int u : graph.keySet())
      if (outDegree.getOrDefault(u, 0) - inDegrees.getOrDefault(u, 0) == 1)
        return u;
    return pairs[0][0]; // Arbitrarily choose a node.
  }

  private void euler(Map<Integer, Deque<Integer>> graph, int u, List<int[]> ans) {
    Deque<Integer> stack = graph.get(u);
    while (stack != null && !stack.isEmpty()) {
      final int v = stack.pop();
      euler(graph, v, ans);
      ans.add(new int[] {u, v});
    }
  }
}
