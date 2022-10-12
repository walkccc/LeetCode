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
    final int kMod = 1_000_000_007;
    List<Pair<Integer, Integer>>[] graph = new List[n + 1];
    Queue<T> minHeap = new PriorityQueue<>((a, b) -> a.d - b.d);
    int[] dist = new int[n + 1]; // dist[i] := dist(node i, node n)
    Arrays.fill(dist, Integer.MAX_VALUE);
    int[] count = new int[n + 1]; // count[i] := # of restricted path from i -> n

    for (int i = 1; i <= n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] e : edges) {
      final int u = e[0];
      final int v = e[1];
      final int w = e[2];
      graph[u].add(new Pair<>(v, w));
      graph[v].add(new Pair<>(u, w));
    }

    minHeap.offer(new T(n, 0));
    dist[n] = 0;
    count[n] = 1;

    while (!minHeap.isEmpty()) {
      final int u = minHeap.peek().u;
      final int d = minHeap.poll().d;
      if (d > dist[u])
        continue;
      for (Pair<Integer, Integer> node : graph[u]) {
        final int v = node.getKey();
        final int w = node.getValue();
        if (dist[v] > d + w) {
          dist[v] = d + w;
          minHeap.offer(new T(v, dist[v]));
        }
        if (dist[u] > dist[v]) {
          count[u] += count[v];
          count[u] %= kMod;
        }
      }
    }

    return count[1];
  }
}
