class Solution {
  public int minCostToSupplyWater(int n, int[] wells, int[][] pipes) {
    int ans = 0;
    List<Pair<Integer, Integer>>[] graph = new List[n + 1];
    Queue<Pair<Integer, Integer>> minHeap =
        new PriorityQueue<>(Comparator.comparing(Pair::getKey)); // (d, u)

    for (int i = 0; i <= n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] p : pipes) {
      final int u = p[0];
      final int v = p[1];
      final int w = p[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    // connect virtual 0 with node 1 to n
    for (int i = 0; i < n; ++i) {
      graph[0].add(new Pair<>(i + 1, wells[i]));
      minHeap.offer(new Pair<>(wells[i], i + 1));
    }

    Set<Integer> mst = new HashSet<>(Arrays.asList(0));

    while (mst.size() < n + 1) {
      Pair<Integer, Integer> pair = minHeap.poll();
      final int d = pair.getKey();
      final int u = pair.getValue();
      if (mst.contains(u))
        continue;
      // adding the new vertex
      mst.add(u);
      ans += d;
      // expand if possible
      for (Pair<Integer, Integer> node : graph[u]) {
        final int v = node.getKey();
        final int w = node.getValue();
        if (!mst.contains(v))
          minHeap.offer(new Pair<>(w, v));
      }
    }

    return ans;
  }
}
