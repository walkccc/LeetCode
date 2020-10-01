class Solution {
  public int[][] updateMatrix(int[][] matrix) {
    final int[] dirs = new int[] { 0, 1, 0, -1, 0 };
    Queue<int[]> queue = new LinkedList<>();

    for (int i = 0; i < matrix.length; ++i)
      for (int j = 0; j < matrix[0].length; ++j)
        if (matrix[i][j] == 0)
          queue.add(new int[] { i, j });
        else
          matrix[i][j] = Integer.MAX_VALUE;

    while (!queue.isEmpty()) {
      int[] cell = queue.poll();
      for (int k = 0; k < 4; ++k) {
        int x = cell[0] + dirs[k];
        int y = cell[1] + dirs[k + 1];
        if (x < 0 || x >= matrix.length || y < 0 || y >= matrix[0].length
            || matrix[x][y] <= matrix[cell[0]][cell[1]] + 1)
          continue;
        queue.add(new int[] { x, y });
        matrix[x][y] = matrix[cell[0]][cell[1]] + 1;
      }
    }

    return matrix;
  }
}