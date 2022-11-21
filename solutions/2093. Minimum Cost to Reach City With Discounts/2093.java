class T {
  public int u;
  public int d;
  public int leftDiscounts;
  public T(int u, int d, int leftDiscounts) {
    this.u = u;
    this.d = d;
    this.leftDiscounts = leftDiscounts;
  }
}

class Solution {
  public int minimumCost(int n, int[][] highways, int discounts) {
    List<Pair<Integer, Integer>>[] graph = new List[n];
    Queue<T> minHeap = new PriorityQueue<>((a, b) -> a.d - b.d);
    Map<Integer, Integer> minDiscounts = new HashMap<>();

    for (int i = 0; i < graph.length; i++)
      graph[i] = new ArrayList<>();

    for (int[] h : highways) {
      final int city1 = h[0];
      final int city2 = h[1];
      final int toll = h[2];
      graph[city1].add(new Pair<>(city2, toll));
      graph[city2].add(new Pair<>(city1, toll));
    }

    minHeap.offer(new T(0, 0, discounts));

    while (!minHeap.isEmpty()) {
      final int u = minHeap.peek().u;
      final int d = minHeap.peek().d;
      final int leftDiscounts = minHeap.poll().leftDiscounts;
      if (u == n - 1)
        return d;
      if (minDiscounts.getOrDefault(u, -1) >= leftDiscounts)
        continue;
      minDiscounts.put(u, leftDiscounts);
      for (Pair<Integer, Integer> pair : graph[u]) {
        final int v = pair.getKey();
        final int w = pair.getValue();
        minHeap.offer(new T(v, d + w, leftDiscounts));
        if (leftDiscounts > 0)
          minHeap.offer(new T(v, d + w / 2, leftDiscounts - 1));
      }
    }
    return -1;
  }
}
