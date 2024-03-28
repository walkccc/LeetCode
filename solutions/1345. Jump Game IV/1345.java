class Solution {
  public int minJumps(int[] arr) {
    final int n = arr.length;
    // {a: indices}
    Map<Integer, List<Integer>> graph = new HashMap<>();
    Queue<Integer> q = new ArrayDeque<>(Arrays.asList(0));
    boolean[] seen = new boolean[n];
    seen[0] = true;

    for (int i = 0; i < n; ++i) {
      graph.putIfAbsent(arr[i], new ArrayList<>());
      graph.get(arr[i]).add(i);
    }

    for (int step = 0; !q.isEmpty(); ++step) {
      for (int sz = q.size(); sz > 0; --sz) {
        final int i = q.poll();
        if (i == n - 1)
          return step;
        seen[i] = true;
        final int u = arr[i];
        if (i + 1 < n)
          graph.get(u).add(i + 1);
        if (i - 1 >= 0)
          graph.get(u).add(i - 1);
        for (final int v : graph.get(u)) {
          if (seen[v])
            continue;
          q.offer(v);
        }
        graph.get(u).clear();
      }
    }

    throw new IllegalArgumentException();
  }
}
