class Solution {
  public int numBusesToDestination(int[][] routes, int S, int T) {
    if (S == T)
      return 0;

    Map<Integer, List<Integer>> graph = new HashMap<>(); // {route: [buses]}
    Set<Integer> usedBuses = new HashSet<>();

    for (int i = 0; i < routes.length; ++i)
      for (final int route : routes[i]) {
        graph.putIfAbsent(route, new ArrayList<>());
        graph.get(route).add(i);
      }

    int ans = 0;
    Queue<Integer> q = new ArrayDeque<>(Arrays.asList(S));

    while (!q.isEmpty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        for (final int bus : graph.get(q.poll()))
          if (usedBuses.add(bus))
            for (final int nextRoute : routes[bus])
              if (nextRoute == T)
                return ans;
              else
                q.offer(nextRoute);
      }
    }

    return -1;
  }
}
