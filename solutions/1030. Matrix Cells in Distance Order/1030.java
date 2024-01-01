class Solution {
  public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
    final int[] dirs = {0, 1, 0, -1, 0};
    List<int[]> ans = new ArrayList<>();
    boolean[][] seen = new boolean[rows][cols];
    Queue<Pair<Integer, Integer>> q = new LinkedList<>(Arrays.asList(new Pair<>(rCenter, cCenter)));
    seen[rCenter][cCenter] = true;

    while (!q.isEmpty()) {
      final int i = q.peek().getKey();
      final int j = q.poll().getValue();
      ans.add(new int[] {i, j});
      for (int k = 0; k < 4; ++k) {
        final int x = i + dirs[k];
        final int y = j + dirs[k + 1];
        if (x < 0 || x == rows || y < 0 || y == cols)
          continue;
        if (seen[x][y])
          continue;
        seen[x][y] = true;
        q.offer(new Pair<>(x, y));
      }
    }

    return ans.toArray(int[][] ::new);
  }
}
