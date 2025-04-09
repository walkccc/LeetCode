class Solution {
  public int maxStarSum(int[] vals, int[][] edges, int k) {
    final int n = vals.length;
    int ans = Integer.MIN_VALUE;
    List<Pair<Integer, Integer>>[] graph = new List[n];

    for (int i = 0; i < n; ++i)
      graph[i] = new ArrayList<>();

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(new Pair<>(v, vals[v]));
      graph[v].add(new Pair<>(u, vals[u]));
    }

    for (int i = 0; i < n; ++i) {
      Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
      for (Pair<Integer, Integer> pair : graph[i]) {
        final int val = pair.getValue();
        if (val > 0)
          maxHeap.offer(val);
      }
      int starSum = vals[i];
      for (int j = 0; j < k && !maxHeap.isEmpty(); ++j)
        starSum += maxHeap.poll();
      ans = Math.max(ans, starSum);
    }

    return ans;
  }
}
