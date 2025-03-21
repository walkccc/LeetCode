class Solution {
  public List<String> findItinerary(List<List<String>> tickets) {
    LinkedList<String> ans = new LinkedList<>();
    Map<String, Queue<String>> graph = new HashMap<>();

    for (final List<String> ticket : tickets) {
      graph.putIfAbsent(ticket.get(0), new PriorityQueue<>());
      graph.get(ticket.get(0)).offer(ticket.get(1));
    }

    dfs(graph, "JFK", ans);
    return ans;
  }

  private void dfs(Map<String, Queue<String>> graph, final String u, LinkedList<String> ans) {
    final Queue<String> arrivals = graph.get(u);
    while (arrivals != null && !arrivals.isEmpty())
      dfs(graph, arrivals.poll(), ans);
    ans.addFirst(u);
  }
}
