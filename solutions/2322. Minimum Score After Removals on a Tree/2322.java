class Solution {
  public int minimumScore(int[] nums, int[][] edges) {
    final int n = nums.length;
    final int xors = getXors(nums);
    int[] subXors = nums.clone();
    List<Integer>[] graph = new List[n];
    Set<Integer>[] children = new Set[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int i = 0; i < n; ++i)
      children[i] = new HashSet<>(Arrays.asList(i));

    for (int[] e : edges) {
      final int u = e[0];
      final int v = e[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    dfs(graph, 0, -1, subXors, children);

    int ans = Integer.MAX_VALUE;

    for (int i = 0; i < edges.length; ++i) {
      int a = edges[i][0];
      int b = edges[i][1];
      if (children[a].contains(b)) {
        final int temp = a;
        a = b;
        b = a;
      }
      for (int j = 0; j < i; ++j) {
        int c = edges[j][0];
        int d = edges[j][1];
        if (children[c].contains(d)) {
          final int temp = c;
          c = d;
          d = temp;
        }
        int[] cands;
        if (a != c && children[a].contains(c))
          cands = new int[] {subXors[c], subXors[a] ^ subXors[c], xors ^ subXors[a]};
        else if (a != c && children[c].contains(a))
          cands = new int[] {subXors[a], subXors[c] ^ subXors[a], xors ^ subXors[c]};
        else
          cands = new int[] {subXors[a], subXors[c], xors ^ subXors[a] ^ subXors[c]};
        ans = Math.min(ans, Arrays.stream(cands).max().getAsInt() -
                                Arrays.stream(cands).min().getAsInt());
      }
    }

    return ans;
  }

  private Pair<Integer, Set<Integer>> dfs(List<Integer>[] graph, int u, int parent, int[] subXors,
                                          Set<Integer>[] children) {
    for (final int v : graph[u]) {
      if (v == parent)
        continue;
      final Pair<Integer, Set<Integer>> pair = dfs(graph, v, u, subXors, children);
      final int vXor = pair.getKey();
      final Set<Integer> vChildren = pair.getValue();
      subXors[u] ^= vXor;
      for (final int child : vChildren)
        children[u].add(child);
    }
    return new Pair<>(subXors[u], children[u]);
  }

  private int getXors(int[] nums) {
    int xors = 0;
    for (final int num : nums)
      xors ^= num;
    return xors;
  }
}
