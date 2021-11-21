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

    List<int[]>[] graph = new List[n];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int x = edge[0];
      final int y = edge[1];
      final int time = edge[2];
      graph[x].add(new int[] {y, time});
      graph[y].add(new int[] {x, time});
    }

    int[] cost = new int[n]; // cost[i] := min cost to reach cities[i]
    int[] time = new int[n]; // time[i] := min time to reach cities[i]
    Arrays.fill(cost, Integer.MAX_VALUE);
    Arrays.fill(time, Integer.MAX_VALUE);

    cost[0] = passingFees[0];
    time[0] = 0;

    PriorityQueue<T> pq =
        new PriorityQueue<>((a, b) -> a.cost == b.cost ? a.time - b.time : a.cost - b.cost);
    pq.offer(new T(0, cost[0], time[0])); // start with node 0 with cost = time = 0

    while (!pq.isEmpty()) {
      final int x = pq.peek().node;
      final int currCost = pq.peek().cost;
      final int currTime = pq.poll().time;
      for (int[] nodes : graph[x]) {
        final int y = nodes[0];
        final int pathTime = nodes[1];
        if (currTime + pathTime <= maxTime) {
          // go from x -> y
          final int newCost = currCost + passingFees[y];
          final int newTime = currTime + pathTime;
          if (cost[y] > newCost) {
            cost[y] = newCost;
            time[y] = newTime;
            pq.offer(new T(y, newCost, newTime));
          } else if (time[y] > newTime) {
            time[y] = newTime;
            pq.offer(new T(y, newCost, newTime));
          }
        }
      }
    }

    return cost[n - 1] == Integer.MAX_VALUE ? -1 : cost[n - 1];
  }
}
