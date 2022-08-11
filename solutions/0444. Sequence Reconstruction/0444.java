class Solution {
  public boolean sequenceReconstruction(int[] org, List<List<Integer>> seqs) {
    if (seqs.isEmpty())
      return false;

    final int n = org.length;
    List<Integer>[] graph = new List[n];
    int[] inDegree = new int[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    // build graph
    for (List<Integer> seq : seqs) {
      if (seq.size() == 1 && seq.get(0) < 1 || seq.get(0) > n) {
        return false;
      } else {
        for (int i = 0; i + 1 < seq.size(); ++i) {
          final int u = seq.get(i);
          final int v = seq.get(i + 1);
          if (u < 1 || u > n || v < 1 || v > n)
            return false;
          graph[u - 1].add(v - 1);
          ++inDegree[v - 1];
        }
      }
    }

    // topology
    Queue<Integer> q = IntStream.range(0, n)
                           .filter(i -> inDegree[i] == 0)
                           .boxed()
                           .collect(Collectors.toCollection(ArrayDeque::new));

    int i = 0; // org's index

    while (!q.isEmpty()) {
      if (q.size() > 1)
        return false;
      final int u = q.poll();
      if (u != org[i] - 1)
        return false;
      ++i;
      for (final int v : graph[u])
        if (--inDegree[v] == 0)
          q.offer(v);
    }

    return i == n;
  }
}
