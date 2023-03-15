class T {
  public int node;
  public int cost;
  public int time;
  public T(int node, int cost, int time) {
    this.node = node;
    this.cost = cost;
    this.time = time;
  }
}

class Solution {
  public int minCost(int maxTime, int[][] edges, int[] passingFees) {
    final int n = passingFees.length;
    List<Pair<Integer, Integer>>[] graph = new List[n];
    Queue<T> minHeap =
        new PriorityQueue<>((a, b) -> a.cost == b.cost ? a.time - b.time : a.cost - b.cost);
    int[] cost = new int[n]; // cost[i] := min cost to reach cities[i]
    int[] time = new int[n]; // time[i] := min time to reach cities[i]
    Arrays.fill(cost, Integer.MAX_VALUE);
    Arrays.fill(time, Integer.MAX_VALUE);

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      final int t = edge[2];
      graph[u].add(new Pair<>(v, t));
      graph[v].add(new Pair<>(u, t));
    }

    // Start with node 0 with cost = time = 0
    minHeap.offer(new T(0, passingFees[0], 0));
    cost[0] = passingFees[0];
    time[0] = 0;

    while (!minHeap.isEmpty()) {
      final int x = minHeap.peek().node;
      final int currCost = minHeap.peek().cost;
      final int currTime = minHeap.poll().time;
      for (Pair<Integer, Integer> pair : graph[x]) {
        final int y = pair.getKey();
        final int pathTime = pair.getValue();
        if (currTime + pathTime <= maxTime) {
          // Go from x -> y
          final int newCost = currCost + passingFees[y];
          final int newTime = currTime + pathTime;
          if (cost[y] > newCost) {
            cost[y] = newCost;
            time[y] = newTime;
            minHeap.offer(new T(y, newCost, newTime));
          } else if (time[y] > newTime) {
            time[y] = newTime;
            minHeap.offer(new T(y, newCost, newTime));
          }
        }
      }
    }

    return cost[n - 1] == Integer.MAX_VALUE ? -1 : cost[n - 1];
  }
}
