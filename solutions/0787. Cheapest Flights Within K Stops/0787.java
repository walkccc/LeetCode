class T {
  public int u;
  public int dist;
  public int k;

  public T(int u, int dist, int k) {
    this.u = u;
    this.dist = dist;
    this.k = k;
  }
}

class Solution {
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
    List<int[]>[] graph = new List[n];
    // {v, w}: min-heap sorted by w
    PriorityQueue<T> pq = new PriorityQueue<>((a, b) -> a.dist - b.dist);
    pq.offer(new T(src, 0, K + 1)); // start with node src with dist == 0

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] f : flights)
      graph[f[0]].add(new int[] {f[1], f[2]});

    while (!pq.isEmpty()) {
      final int u = pq.peek().u;
      final int dist = pq.peek().dist;
      final int k = pq.poll().k;
      if (u == dst)
        return dist;
      if (k > 0)
        for (int[] nodes : graph[u]) {
          final int v = nodes[0];
          final int w = nodes[1];
          pq.offer(new T(v, dist + w, k - 1));
        }
    }

    return -1;
  }
}
