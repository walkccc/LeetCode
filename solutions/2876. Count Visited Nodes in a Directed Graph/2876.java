class Solution {
  public int[] countVisitedNodes(List<Integer> edges) {
    final int n = edges.size();
    int[] ans = new int[n];
    int[] inDegrees = new int[n];
    boolean[] seen = new boolean[n];
    Queue<Integer> q = new ArrayDeque<>();
    Stack<Integer> stack = new Stack<>();

    for (int v : edges)
      ++inDegrees[v];

    // Perform topological sorting.
    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0)
        q.add(i);

    // Push non-cyclic nodes to stack.
    while (!q.isEmpty()) {
      int u = q.poll();
      if (--inDegrees[edges.get(u)] == 0)
        q.add(edges.get(u));
      stack.push(u);
      seen[u] = true;
    }

    // Fill the length of cyclic nodes.
    for (int i = 0; i < n; ++i)
      if (!seen[i])
        fillCycle(edges, i, seen, ans);

    // Fill the length of non-cyclic nodes.
    while (!stack.isEmpty()) {
      int u = stack.pop();
      ans[u] = ans[edges.get(u)] + 1;
    }

    return ans;
  }

  private void fillCycle(List<Integer> edges, int start, boolean[] seen, int[] ans) {
    int cycleLength = 0;
    for (int u = start; !seen[u]; u = edges.get(u)) {
      ++cycleLength;
      seen[u] = true;
    }
    ans[start] = cycleLength;
    for (int u = edges.get(start); u != start; u = edges.get(u))
      ans[u] = cycleLength;
  }
}
