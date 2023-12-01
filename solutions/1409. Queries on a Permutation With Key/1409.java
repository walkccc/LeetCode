class FenwickTree {
  public FenwickTree(int n) {
    sums = new int[n + 1];
  }

  public void update(int i, int delta) {
    while (i < sums.length) {
      sums[i] += delta;
      i += lowbit(i);
    }
  }

  public int get(int i) {
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= lowbit(i);
    }
    return sum;
  }

  private int[] sums;

  private static int lowbit(int i) {
    return i & -i;
  }
}

class Solution {
  public int[] processQueries(int[] queries, int m) {
    int[] ans = new int[queries.length];
    // Map [-m, m] to [0, 2 * m].
    FenwickTree tree = new FenwickTree(2 * m + 1);
    Map<Integer, Integer> numToIndex = new HashMap<>();

    for (int num = 1; num <= m; ++num) {
      numToIndex.put(num, num + m);
      tree.update(num + m, 1);
    }

    int nextEmptyIndex = m; // Map 0 to m.

    for (int i = 0; i < queries.length; ++i) {
      final int query = queries[i];
      final int index = numToIndex.get(query);
      ans[i] = tree.get(index - 1);
      // Move the `query` from the `index` to the `nextEmptyIndex`.
      tree.update(index, -1);
      tree.update(nextEmptyIndex, 1);
      numToIndex.put(query, nextEmptyIndex--);
    }

    return ans;
  }
}
