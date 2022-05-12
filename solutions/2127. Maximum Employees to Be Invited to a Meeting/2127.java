enum State { INIT, VISITING, VISITED }

class Solution {
  public int maximumInvitations(int[] favorite) {
    final int n = favorite.length;
    int sumComponentsLength = 0; // component: a -> b -> c <-> x <- y
    List<Integer>[] graph = new List[n];
    int[] inDegree = new int[n];
    int[] maxChainLength = new int[n];
    Arrays.fill(maxChainLength, 1);

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    // build graph
    for (int i = 0; i < n; ++i) {
      graph[i].add(favorite[i]);
      ++inDegree[favorite[i]];
    }

    // topology
    Queue<Integer> q = IntStream.range(0, n)
                           .filter(i -> inDegree[i] == 0)
                           .boxed()
                           .collect(Collectors.toCollection(ArrayDeque::new));

    while (!q.isEmpty()) {
      final int u = q.poll();
      for (final int v : graph[u]) {
        if (--inDegree[v] == 0)
          q.offer(v);
        maxChainLength[v] = Math.max(maxChainLength[v], 1 + maxChainLength[u]);
      }
    }

    for (int i = 0; i < n; ++i)
      if (favorite[favorite[i]] == i)
        // i <-> favorite[i] (cycle's length = 2)
        sumComponentsLength += maxChainLength[i] + maxChainLength[favorite[i]];

    int[] parent = new int[n];
    Arrays.fill(parent, -1);
    boolean[] seen = new boolean[n];
    State[] state = new State[n];

    for (int i = 0; i < n; ++i)
      if (!seen[i])
        findCycle(graph, i, parent, seen, state);

    return Math.max(sumComponentsLength / 2, maxCycleLength);
  }

  private int maxCycleLength = 0; // cycle : a -> b -> c -> a

  private void findCycle(List<Integer>[] graph, int u, int[] parent, boolean[] seen,
                         State[] state) {
    seen[u] = true;
    state[u] = State.VISITING;

    for (final int v : graph[u]) {
      if (!seen[v]) {
        parent[v] = u;
        findCycle(graph, v, parent, seen, state);
      } else if (state[v] == State.VISITING) {
        // find the cycle's length
        int curr = u;
        int cycleLength = 1;
        while (curr != v) {
          curr = parent[curr];
          ++cycleLength;
        }
        maxCycleLength = Math.max(maxCycleLength, cycleLength);
      }
    }

    state[u] = State.VISITED;
  }
}
