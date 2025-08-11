enum State { INIT, VISITING, VISITED }

class Solution {
  public List<List<Integer>> supersequences(String[] words) {
    List<List<Integer>> ans = new ArrayList<>();
    List<int[]> edges = getEdges(words);
    List<Integer> nodes = getNodes(edges);
    int[] letterToIndex = getLetterToIndex(nodes);
    List<Integer>[] graph = new List[nodes.size()];

    for (int i = 0; i < nodes.size(); i++)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[letterToIndex[u]].add(letterToIndex[v]);
    }

    for (List<Integer> doubledSubset : getMinimumSubsets(graph)) {
      int[] freq = new int[26];
      for (final int letter : nodes)
        freq[letter] = 1;
      for (final int index : doubledSubset)
        freq[nodes.get(index)] = 2;
      ans.add(Arrays.stream(freq).boxed().collect(Collectors.toList()));
    }

    return ans;
  }

  // Returns a list of the minimum subsets of nodes that do not create a cycle
  // when skipped.
  private List<List<Integer>> getMinimumSubsets(List<Integer>[] graph) {
    final int n = graph.length;
    List<List<Integer>> res = new ArrayList<>();

    for (int subsetSize = 0; subsetSize <= n; ++subsetSize) {
      boolean[] combination = new boolean[n];
      Arrays.fill(combination, n - subsetSize, n, true);
      do {
        List<Integer> doubledSubset = new ArrayList<>();
        for (int i = 0; i < n; i++)
          if (combination[i])
            doubledSubset.add(i);
        if (!hasCycleSkipping(graph, new HashSet<>(doubledSubset)))
          res.add(doubledSubset);
      } while (nextPermutation(combination));
      if (!res.isEmpty())
        return res;
    }
    return res;
  }

  // Returns true if there is a cycle in the `graph` when skipping any edges
  // whose both endpoints are in `doubledSubset`.
  private boolean hasCycleSkipping(List<Integer>[] graph, Set<Integer> doubledSubset) {
    State[] states = new State[graph.length];
    for (int i = 0; i < graph.length; ++i)
      if (hasCycle(graph, i, states, doubledSubset))
        return true;
    return false;
  }

  private boolean hasCycle(List<Integer>[] graph, int u, State[] states,
                           Set<Integer> doubledSubset) {
    if (states[u] == State.VISITING)
      return true;
    if (states[u] == State.VISITED)
      return false;
    states[u] = State.VISITING;
    if (!doubledSubset.contains(u))
      for (final int v : graph[u])
        if (!doubledSubset.contains(v) && hasCycle(graph, v, states, doubledSubset))
          return true;
    states[u] = State.VISITED;
    return false;
  }

  private List<int[]> getEdges(String[] words) {
    List<int[]> edges = new ArrayList<>();
    for (final String word : words)
      edges.add(new int[] {word.charAt(0) - 'a', word.charAt(1) - 'a'});
    return edges;
  }

  private List<Integer> getNodes(List<int[]> edges) {
    TreeSet<Integer> nodes = new TreeSet<>();
    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      nodes.add(u);
      nodes.add(v);
    }
    return new ArrayList<>(nodes);
  }

  private int[] getLetterToIndex(List<Integer> nodes) {
    int[] letterToIndex = new int[26];
    for (int i = 0; i < nodes.size(); ++i)
      letterToIndex[nodes.get(i)] = i;
    return letterToIndex;
  }

  private boolean nextPermutation(boolean[] arr) {
    final int n = arr.length;

    // From back to front, find the first false followed by true
    int i;
    for (i = n - 2; i >= 0; --i)
      if (!arr[i] && arr[i + 1])
        break;

    // If no such pair found, we've reached the last permutation
    if (i < 0)
      return false;

    // From back to front, find the first true to swap with arr[i].
    for (int j = n - 1; j > i; --j)
      if (arr[j] && !arr[i]) {
        swap(arr, i, j);
        break;
      }

    // Reverse arr[i + 1..n - 1].
    reverse(arr, i + 1, n - 1);
    return true;
  }

  private void reverse(boolean[] arr, int l, int r) {
    while (l < r)
      swap(arr, l++, r--);
  }

  private void swap(boolean[] arr, int i, int j) {
    boolean temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}
