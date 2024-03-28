class Solution {
  public int secondMinimum(int n, int[][] edges, int time, int change) {
    List<Integer>[] graph = new List[n + 1];
    Queue<int[]> q = new ArrayDeque<>(Arrays.asList(new int[] {1, 0})); // (index, time)
    // minTime[i][0] := the first minimum time to reach the node i
    // minTime[i][1] := the second minimum time to reach the node i
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
      final int i = q.peek()[0];
      final int prevTime = q.poll()[1];
      // Start from green.
      // If `numChangeSignal` is odd, now red.
      // If `numChangeSignal` is even, now green.
      final int numChangeSignal = prevTime / change;
      final int waitTime = (numChangeSignal & 1) == 1 ? change - (prevTime % change) : 0;
      final int newTime = prevTime + waitTime + time;
      for (final int j : graph[i])
        if (newTime < minTime[j][0]) {
          minTime[j][0] = newTime;
          q.offer(new int[] {j, newTime});
        } else if (minTime[j][0] < newTime && newTime < minTime[j][1]) {
          if (j == n)
            return newTime;
          minTime[j][1] = newTime;
          q.offer(new int[] {j, newTime});
        }
    }

    throw new IllegalArgumentException();
  }
}
