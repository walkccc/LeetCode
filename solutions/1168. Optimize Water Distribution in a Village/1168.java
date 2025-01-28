class Solution {
  public int minCostToSupplyWater(int n, int[] wells, int[][] pipes) {
    int ans = 0;
    List<Pair<Integer, Integer>>[] graph = new List[n + 1];
    Queue<Pair<Integer, Integer>> minHeap =
        new PriorityQueue<>(Comparator.comparing(Pair::getKey)); // (d, u)

    for (int i = 0; i <= n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] pipe : pipes) {
      final int u = pipe[0];
      final int v = pipe[1];
      final int w = pipe[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    // Connect virtual 0 with nodes 1 to n.
    for (int i = 0; i < n; ++i) {
      graph[0].add(new Pair<>(i + 1, wells[i]));
      minHeap.offer(new Pair<>(wells[i], i + 1));
    }

    Set<Integer> mst = new HashSet<>(Arrays.asList(0));

    while (mst.size() < n + 1) {
      final int d = minHeap.peek().getKey();
      final int u = minHeap.poll().getValue();
      if (mst.contains(u))
        continue;
      // Add the new vertex.
      mst.add(u);
      ans += d;
      // Expand if possible.
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        if (!mst.contains(v))
          minHeap.offer(new Pair<>(w, v));
      }
    }

    return ans;
  }
}
