enum State { kInit, kVisiting, kVisited }

class Solution {
  public int maximumInvitations(int[] favorite) {
    final int n = favorite.length;
    int sumComponentsLength = 0; // the component: a -> b -> c <-> x <- y
    List<Integer>[] graph = new List[n];
    int[] inDegrees = new int[n];
    int[] maxChainLength = new int[n];
    Arrays.fill(maxChainLength, 1);

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    // Build the graph.
    for (int i = 0; i < n; ++i) {
      graph[i].add(favorite[i]);
      ++inDegrees[favorite[i]];
    }

    // Perform topological sorting.
    Queue<Integer> q = IntStream.range(0, n)
                           .filter(i -> inDegrees[i] == 0)
                           .boxed()
                           .collect(Collectors.toCollection(ArrayDeque::new));

    while (!q.isEmpty()) {
      final int u = q.poll();
      for (final int v : graph[u]) {
        if (--inDegrees[v] == 0)
          q.offer(v);
        maxChainLength[v] = Math.max(maxChainLength[v], 1 + maxChainLength[u]);
      }
    }

    for (int i = 0; i < n; ++i)
      if (favorite[favorite[i]] == i)
        // i <-> favorite[i] (the cycle's length = 2)
        sumComponentsLength += maxChainLength[i] + maxChainLength[favorite[i]];

    int[] parent = new int[n];
    Arrays.fill(parent, -1);
    boolean[] seen = new boolean[n];
    State[] states = new State[n];

    for (int i = 0; i < n; ++i)
      if (!seen[i])
        findCycle(graph, i, parent, seen, states);

    return Math.max(sumComponentsLength / 2, maxCycleLength);
  }

  private int maxCycleLength = 0; // the cycle : a -> b -> c -> a

  private void findCycle(List<Integer>[] graph, int u, int[] parent, boolean[] seen,
                         State[] states) {
    seen[u] = true;
    states[u] = State.kVisiting;

    for (final int v : graph[u]) {
      if (!seen[v]) {
        parent[v] = u;
        findCycle(graph, v, parent, seen, states);
      } else if (states[v] == State.kVisiting) {
        // Find the cycle's length.
        int curr = u;
        int cycleLength = 1;
        while (curr != v) {
          curr = parent[curr];
          ++cycleLength;
        }
        maxCycleLength = Math.max(maxCycleLength, cycleLength);
      }
    }

    states[u] = State.kVisited;
  }
}
