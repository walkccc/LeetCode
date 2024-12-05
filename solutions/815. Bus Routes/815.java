class Solution {
  public int numBusesToDestination(int[][] routes, int source, int target) {
    if (source == target)
      return 0;

    Map<Integer, List<Integer>> graph = new HashMap<>(); // {route: [buses]}
    Set<Integer> usedBuses = new HashSet<>();

    for (int i = 0; i < routes.length; ++i)
      for (final int route : routes[i]) {
        graph.putIfAbsent(route, new ArrayList<>());
        graph.get(route).add(i);
      }

    Queue<Integer> q = new ArrayDeque<>(List.of(source));

    for (int step = 1; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        for (final int bus : graph.getOrDefault(q.poll(), new ArrayList<>()))
          if (usedBuses.add(bus))
            for (final int nextRoute : routes[bus]) {
              if (nextRoute == target)
                return step;
              q.offer(nextRoute);
            }
      }

    return -1;
  }
}
