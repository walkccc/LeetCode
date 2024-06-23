class Solution {
  public int minArea(char[][] image, int x, int y) {
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = image.length;
    final int n = image[0].length;
    int[] topLeft = {x, y};
    int[] bottomRight = {x, y};
    Queue<int[]> q = new ArrayDeque<>(Arrays.asList(new int[] {x, y}));
    image[x][y] = '2'; // Mark as visited.

    while (!q.isEmpty()) {
      final int i = q.peek()[0];
      final int j = q.poll()[1];
      for (int[] dir : dirs) {
        final int r = i + dir[0];
        final int c = j + dir[1];
        if (r < 0 || r == m || c < 0 || c == n)
          continue;
        if (image[r][c] != '1')
          continue;
        topLeft[0] = Math.min(topLeft[0], r);
        topLeft[1] = Math.min(topLeft[1], c);
        bottomRight[0] = Math.max(bottomRight[0], r);
        bottomRight[1] = Math.max(bottomRight[1], c);
        q.offer(new int[] {r, c});
        image[r][c] = '2';
      }
    }

    final int width = bottomRight[1] - topLeft[1] + 1;
    final int height = bottomRight[0] - topLeft[0] + 1;
    return width * height;
  }
}
