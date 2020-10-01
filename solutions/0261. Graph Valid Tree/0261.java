class Solution {
  public boolean validTree(int n, int[][] edges) {
    if (n == 0 || edges.length != n - 1)
      return false;

    List<Integer>[] graph = new List[n];
    Queue<Integer> q = new LinkedList<>();
    Set<Integer> seen = new HashSet<>();

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (final int[] edge : edges) {
      graph[edge[0]].add(edge[1]);
      graph[edge[1]].add(edge[0]);
    }

    q.offer(0);
    seen.add(0);

    while (!q.isEmpty()) {
      final int node = q.poll();
      for (final int neighbor : graph[node])
        if (!seen.contains(neighbor)) {
          q.offer(neighbor);
          seen.add(neighbor);
        }
    }

    return seen.size() == n;
  }
}