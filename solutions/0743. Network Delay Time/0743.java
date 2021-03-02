class T {
  public int u;
  public int dist;

  public T(int u, int dist) {
    this.u = u;
    this.dist = dist;
  }
}

class Solution {
  public int networkDelayTime(int[][] times, int N, int K) {
    List<int[]>[] graph = new List[N + 1];
    boolean[] seen = new boolean[N + 1];
    // {v, w}: min-heap sorted by w
    PriorityQueue<T> pq = new PriorityQueue<>((a, b) -> a.dist - b.dist);
    pq.offer(new T(K, 0)); // start with node K with dist == 0

    for (int i = 1; i <= N; ++i)
      graph[i] = new ArrayList<>();

    for (int[] time : times)
      graph[time[0]].add(new int[] {time[1], time[2]});

    while (!pq.isEmpty()) {
      final int u = pq.peek().u;
      final int dist = pq.poll().dist;
      if (seen[u])
        continue;
      seen[u] = true;
      if (--N == 0)
        return dist;
      for (int[] nodes : graph[u]) {
        final int v = nodes[0];
        final int w = nodes[1];
        pq.offer(new T(v, dist + w));
      }
    }

    return -1;
  }
}
