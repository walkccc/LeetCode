class Solution {
  public int networkDelayTime(int[][] times, int n, int k) {
    List<Pair<Integer, Integer>>[] graph = new List[n];
    Queue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]); // (d, u)
    boolean[] seen = new boolean[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] t : times) {
      final int u = t[0] - 1;
      final int v = t[1] - 1;
      final int w = t[2];
      graph[u].add(new Pair<>(v, w));
    }

    minHeap.offer(new int[] {0, k - 1});

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek()[0];
      final int u = minHeap.poll()[1];
      if (seen[u])
        continue;
      seen[u] = true;
      if (--n == 0)
        return d;
      for (Pair<Integer, Integer> node : graph[u]) {
        final int v = node.getKey();
        final int w = node.getValue();
        minHeap.offer(new int[] {d + w, v});
      }
    }

    return -1;
  }
}
