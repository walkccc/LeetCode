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
    List<Integer>[] tree = new List[nodes];

    for (int i = 0; i < tree.length; ++i)
      tree[i] = new ArrayList<>();

    for (int i = 1; i < parent.length; ++i)
      tree[parent[i]].add(i);

    return dfs(tree, 0, value).count;
  }

  private T dfs(List<Integer>[] tree, int u, int[] value) {
    int sum = value[u]; // the root value
    int count = 1;      // this root

    for (final int v : tree[u]) {
      final T t = dfs(tree, v, value);
      sum += t.sum;
      count += t.count;
    }

    if (sum == 0)         // Delete this root.
      return new T(0, 0); // So, its count = 0.
    return new T(sum, count);
  }
}
