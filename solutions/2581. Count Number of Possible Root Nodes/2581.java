class Solution {
  public int rootCount(int[][] edges, int[][] guesses, int k) {
    final int n = edges.length + 1;
    List<Integer>[] graph = new List[n];
    Set<Integer>[] guessGraph = new Set[n];
    int[] parent = new int[n];

    for (int i = 0; i < n; ++i) {
      graph[i] = new ArrayList<>();
      guessGraph[i] = new HashSet<>();
    }

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    for (int[] guess : guesses) {
      final int u = guess[0];
      final int v = guess[1];
      guessGraph[u].add(v);
    }

    // Precalculate `parent`.
    dfs(graph, 0, /*prev=*/-1, parent);

    // Calculate `correctGuess` for tree rooted at 0.
    int correctGuess = 0;
    for (int i = 1; i < n; ++i)
      if (guessGraph[parent[i]].contains(i))
        ++correctGuess;

    reroot(graph, 0, /*prev=*/-1, correctGuess, guessGraph, k);
    return ans;
  }

  private int ans = 0;

  private void dfs(List<Integer>[] graph, int u, int prev, int[] parent) {
    parent[u] = prev;
    for (final int v : graph[u])
      if (v != prev)
        dfs(graph, v, u, parent);
  }

  private void reroot(List<Integer>[] graph, int u, int prev, int correctGuess,
                      Set<Integer>[] guessGraph, int k) {
    if (u != 0) {
      // The tree is rooted at u, so a guess edge (u, prev) will match the new
      // `parent` relationship.
      if (guessGraph[u].contains(prev))
        ++correctGuess;
      // A guess edge (prev, u) matching the old `parent` relationship will no
      // longer be true.
      if (guessGraph[prev].contains(u))
        --correctGuess;
    }
    if (correctGuess >= k)
      ++ans;
    for (final int v : graph[u])
      if (v != prev)
        reroot(graph, v, u, correctGuess, guessGraph, k);
  }
}
