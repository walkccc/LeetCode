class Solution {
  public int secondMinimum(int n, int[][] edges, int time, int change) {
    List<Integer>[] graph = new List[n + 1];
    // (index, time)
    Queue<Pair<Integer, Integer>> q = new ArrayDeque<>(List.of(new Pair<>(1, 0)));
    // minTime[u][0] := the first minimum time to reach the node u
    // minTime[u][1] := the second minimum time to reach the node u
    int[][] minTime = new int[n + 1][2];
    Arrays.stream(minTime).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    minTime[1][0] = 0;

    for (int i = 1; i <= n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    while (!q.isEmpty()) {
      final int u = q.peek().getKey();
      final int prevTime = q.poll().getValue();
      // Start from green.
      // If `numChangeSignal` is odd, now red.
      // If `numChangeSignal` is even, now green.
      final int numChangeSignal = prevTime / change;
      final int waitTime = numChangeSignal % 2 == 0 ? 0 : change - prevTime % change;
      final int newTime = prevTime + waitTime + time;
      for (final int v : graph[u])
        if (newTime < minTime[v][0]) {
          minTime[v][0] = newTime;
          q.offer(new Pair<>(v, newTime));
        } else if (minTime[v][0] < newTime && newTime < minTime[v][1]) {
          if (v == n)
            return newTime;
          minTime[v][1] = newTime;
          q.offer(new Pair<>(v, newTime));
        }
    }

    throw new IllegalArgumentException();
  }
}
