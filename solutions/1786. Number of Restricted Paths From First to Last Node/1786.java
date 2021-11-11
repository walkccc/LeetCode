class T {
  public int u;
  public int d;
  public T(int u, int d) {
    this.u = u;
    this.d = d;
  }
}

class Solution {
  public int countRestrictedPaths(int n, int[][] edges) {
    final int kMod = (int) 1e9 + 7;

    List<int[]>[] graph = new List[n + 1];
    // {v, w}: min-heap sorted by w
    PriorityQueue<T> pq = new PriorityQueue<>((a, b) -> a.d - b.d);
    pq.offer(new T(n, 0));
    int[] dist = new int[n + 1]; // dist[i] := dist(node i, node n)
    Arrays.fill(dist, Integer.MAX_VALUE);
    int[] count = new int[n + 1]; // count[i] := # of restricted path from i -> n
    dist[n] = 0;
    count[n] = 1;

    for (int i = 1; i <= n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      graph[edge[0]].add(new int[] {edge[1], edge[2]});
      graph[edge[1]].add(new int[] {edge[0], edge[2]});
    }

    while (!pq.isEmpty()) {
      final int u = pq.peek().u;
      final int d = pq.poll().d;
      if (d > dist[u])
        continue;
      for (int[] nodes : graph[u]) {
        final int v = nodes[0];
        final int w = nodes[1];
        if (dist[v] > d + w) {
          dist[v] = d + w;
          pq.offer(new T(v, dist[v]));
        }
        if (dist[u] > dist[v])
          count[u] = (count[u] + count[v]) % kMod;
      }
    }

    return count[1];
  }
}
