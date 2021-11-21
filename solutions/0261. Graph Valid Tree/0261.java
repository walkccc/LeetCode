class Solution {
  public boolean validTree(int n, int[][] edges) {
    if (n == 0 || edges.length != n - 1)
      return false;

    List<Integer>[] graph = new List[n];
    Queue<Integer> q = new LinkedList<>(Arrays.asList(0));
    Set<Integer> seen = new HashSet<>(Arrays.asList(0));

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      graph[edge[0]].add(edge[1]);
      graph[edge[1]].add(edge[0]);
    }

    while (!q.isEmpty()) {
      final int u = q.poll();
      for (final int v : graph[u])
        if (!seen.contains(v)) {
          q.offer(v);
          seen.add(v);
        }
    }

    return seen.size() == n;
  }
}
