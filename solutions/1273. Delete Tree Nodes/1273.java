class T {
  public int sum;
  public int count;
  public T(int sum, int count) {
    this.sum = sum;
    this.count = count;
  }
}

class Solution {
  public int deleteTreeNodes(int nodes, int[] parent, int[] value) {
    List<Integer>[] graph = new List[nodes];

    for (int i = 0; i < graph.length; ++i)
      graph[i] = new ArrayList<>();

    for (int i = 1; i < parent.length; ++i)
      graph[parent[i]].add(i);

    return dfs(graph, 0, value).count;
  }

  private T dfs(List<Integer>[] graph, int u, int[] value) {
    int sum = value[u]; // Root value
    int count = 1;      // This root

    for (final int v : graph[u]) {
      final T t = dfs(graph, v, value);
      sum += t.sum;
      count += t.count;
    }

    if (sum == 0)         // Delete this u
      return new T(0, 0); // So its count = 0
    return new T(sum, count);
  }
}
