class T {
  public int i;
  public int j;
  public int val; // grid[i][j]
  public T(int i, int j, int val) {
    this.i = i;
    this.j = j;
    this.val = val;
  }
}

class Solution {
  public int[] maxPoints(int[][] grid, int[] queries) {
    final int m = grid.length;
    final int n = grid[0].length;
    final int[] dirs = {0, 1, 0, -1, 0};
    int[] ans = new int[queries.length];
    Pair<Integer, Integer>[] queryAndIndexes = new Pair[queries.length];
    Queue<T> minHeap = new PriorityQueue<>((a, b) -> a.val - b.val);
    boolean[][] seen = new boolean[m][n];

    for (int i = 0; i < queries.length; ++i)
      queryAndIndexes[i] = new Pair<>(queries[i], i);

    Arrays.sort(queryAndIndexes, (a, b) -> a.getKey() - b.getKey());

    minHeap.offer(new T(0, 0, grid[0][0]));
    seen[0][0] = true;
    int accumulate = 0;

    for (Pair<Integer, Integer> pair : queryAndIndexes) {
      final int query = pair.getKey();
      final int index = pair.getValue();
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
        for (int k = 0; k < 4; ++k) {
          final int x = i + dirs[k];
          final int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (seen[x][y])
            continue;
          minHeap.offer(new T(x, y, grid[x][y]));
          seen[x][y] = true;
        }
      }
      ans[index] = accumulate;
    }

    return ans;
  }
}
