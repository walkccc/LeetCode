class Solution {
  public int secondMinimum(int n, int[][] edges, int time, int change) {
    List<Integer>[] graph = new List[n + 1];
    Queue<int[]> q = new ArrayDeque<>(Arrays.asList(new int[] {1, 0})); // (index, time)
    // minTime[i][0] := 1st min time to reach node i
    // minTime[i][1] := 2nd min time to reach node i
    int[][] minTime = new int[n + 1][2];
    Arrays.stream(minTime).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    minTime[1][0] = 0;

    for (int i = 1; i <= n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] e : edges) {
      final int u = e[0];
      final int v = e[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    while (!q.isEmpty()) {
      final int i = q.peek()[0];
      final int prevTime = q.poll()[1];
      // start from green
      // if numChangeSignal is odd -> now red
      // if numChangeSignal is even -> now green
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
