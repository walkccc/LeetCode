class Solution {
  public double maxProbability(int n, int[][] edges, double[] succProb, int start, int end) {
    // {a: [(b, probability_ab)]}
    List<Pair<Integer, Double>>[] graph = new List[n];
    // (the probability to reach u, u)
    Queue<Pair<Double, Integer>> maxHeap =
        new PriorityQueue<>((a, b) -> Double.compare(b.getKey(), a.getKey()));

    maxHeap.offer(new Pair<>(1.0, start));
    boolean[] seen = new boolean[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int i = 0; i < edges.length; ++i) {
      final int u = edges[i][0];
      final int v = edges[i][1];
      final double prob = succProb[i];
      graph[u].add(new Pair<>(v, prob));
      graph[v].add(new Pair<>(u, prob));
    }

    while (!maxHeap.isEmpty()) {
      final double prob = maxHeap.peek().getKey();
      final int u = maxHeap.poll().getValue();
      if (u == end)
        return prob;
      if (seen[u])
        continue;
      seen[u] = true;
      for (Pair<Integer, Double> node : graph[u]) {
        final int nextNode = node.getKey();
        final double edgeProb = node.getValue();
        if (seen[nextNode])
          continue;
        maxHeap.add(new Pair<>(prob * edgeProb, nextNode));
      }
    }

    return 0;
  }
}
