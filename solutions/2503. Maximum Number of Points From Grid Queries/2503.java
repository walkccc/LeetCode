class Solution {
  public int[] maxPoints(int[][] grid, int[] queries) {
    record T(int i, int j, int val) {}
    final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = grid.length;
    final int n = grid[0].length;
    int[] ans = new int[queries.length];
    Queue<T> minHeap = new PriorityQueue<>(Comparator.comparingInt(T::val));
    boolean[][] seen = new boolean[m][n];

    minHeap.offer(new T(0, 0, grid[0][0]));
    seen[0][0] = true;
    int accumulate = 0;

    for (IndexedQuery indexedQuery : getIndexedQueries(queries)) {
      final int queryIndex = indexedQuery.queryIndex;
      final int query = indexedQuery.query;
      while (!minHeap.isEmpty()) {
        final int i = minHeap.peek().i;
        final int j = minHeap.peek().j;
        final int val = minHeap.poll().val;
        if (val >= query) {
          // The smallest neighbor is still larger than `query`, so no need to
          // keep exploring. Re-push (i, j, grid[i][j]) back to the `minHeap`.
          minHeap.offer(new T(i, j, val));
          break;
        }
        ++accumulate;
        for (int[] dir : DIRS) {
          final int x = i + dir[0];
          final int y = j + dir[1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (seen[x][y])
            continue;
          minHeap.offer(new T(x, y, grid[x][y]));
          seen[x][y] = true;
        }
      }
      ans[queryIndex] = accumulate;
    }

    return ans;
  }

  private record IndexedQuery(int queryIndex, int query) {}

  private IndexedQuery[] getIndexedQueries(int[] queries) {
    IndexedQuery[] indexedQueries = new IndexedQuery[queries.length];
    for (int i = 0; i < queries.length; ++i)
      indexedQueries[i] = new IndexedQuery(i, queries[i]);
    Arrays.sort(indexedQueries, Comparator.comparingInt(IndexedQuery::query));
    return indexedQueries;
  }
}
