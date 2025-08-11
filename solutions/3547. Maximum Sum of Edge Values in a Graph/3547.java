class Solution {
  public long maxScore(int n, int[][] edges) {
    long ans = 0;
    List<Integer>[] graph = new List[n];
    List<Integer> cycleSizes = new ArrayList<>(); // components where all nodes have degree 2
    List<Integer> pathSizes = new ArrayList<>();  // components that are not cycleSizes
    boolean[] seen = new boolean[n];
    Arrays.setAll(graph, i -> new ArrayList<>());

    for (int[] edge : edges) {
      final int u = edge[0];
      final int v = edge[1];
      graph[u].add(v);
      graph[v].add(u);
    }

    for (int i = 0; i < n; ++i) {
      if (seen[i])
        continue;
      List<Integer> component = getComponent(graph, i, seen);
      final boolean allDegree2 = component.stream().allMatch(u -> graph[u].size() == 2);
      if (allDegree2)
        cycleSizes.add(component.size());
      else if (component.size() > 1)
        pathSizes.add(component.size());
    }

    for (final int cycleSize : cycleSizes) {
      ans += calculateScore(n - cycleSize + 1, n, true);
      n -= cycleSize;
    }

    Collections.sort(pathSizes, Collections.reverseOrder());

    for (final int pathSize : pathSizes) {
      ans += calculateScore(n - pathSize + 1, n, false);
      n -= pathSize;
    }

    return ans;
  }

  private List<Integer> getComponent(List<Integer>[] graph, int start, boolean[] seen) {
    List<Integer> component = new ArrayList<>(List.of(start));
    seen[start] = true;
    for (int i = 0; i < component.size(); ++i) {
      final int u = component.get(i);
      for (final int v : graph[u]) {
        if (seen[v])
          continue;
        component.add(v);
        seen[v] = true;
      }
    }
    return component;
  }

  private long calculateScore(int left, int right, boolean isCycle) {
    Deque<Long> window = new ArrayDeque<>();
    window.offerLast((long) right);
    window.offerLast((long) right);
    long score = 0;
    for (int value = right - 1; value >= left; --value) {
      final long windowValue = window.pollFirst();
      score += windowValue * value;
      window.offerLast((long) value);
    }
    return score + window.peekFirst() * window.peekLast() * (isCycle ? 1 : 0);
  }
}
