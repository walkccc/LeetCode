class Solution {
  public int numBusesToDestination(int[][] routes, int S, int T) {
    if (S == T)
      return 0;

    Set<Integer> usedBuses = new HashSet<>();
    Map<Integer, List<Integer>> graph = new HashMap<>(); // {route: [buses]}

    for (int i = 0; i < routes.length; ++i)
      for (final int route : routes[i]) {
        graph.putIfAbsent(route, new ArrayList<>());
        graph.get(route).add(i);
      }

    int ans = 0;
    Queue<Integer> q = new LinkedList<>(Arrays.asList(S));

    while (!q.isEmpty()) {
      ++ans;
      for (int size = q.size(); size > 0; --size) {
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
