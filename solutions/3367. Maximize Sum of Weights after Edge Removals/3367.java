class Solution {
  public long maximizeSumOfWeights(int[][] edges, int k) {
    final int n = edges.length + 1;
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int w = edge[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    return dfs(graph, 0, -1, k).getValue();
  }

  // Returns
  // (the weight sum of the subtree rooted at u with at most k - 1 children,
  //  the weight sum of the subtree rooted at u with at most k children).
  private Pair<Long, Long> dfs(List<Pair<Integer, Integer>>[] graph, int u, int prev, int k) {
    long weightSum = 0;
    Queue<Long> diffs = new PriorityQueue<>(Collections.reverseOrder());

    for (Pair<Integer, Integer> pair : graph[u]) {
      final int v = pair.getKey();
      final int w = pair.getValue();
      if (v == prev)
        continue;
      Pair<Long, Long> subResult = dfs(graph, v, u, k);
      final long subK1 = subResult.getKey();
      final long subK = subResult.getValue();
      weightSum += subK;
      // If picking (u, v) makes the sum larger, we should pick it.
      diffs.offer(Math.max(0L, subK1 - subK + w));
    }

    long topK1 = 0;
    long topK = 0;

    for (int i = 0; i < k && !diffs.isEmpty(); ++i) {
      if (i < k - 1)
        topK1 += diffs.peek();
      topK += diffs.poll();
    }

    return new Pair<>(weightSum + topK1, weightSum + topK);
  }
}
