class Solution {
  public Node construct(int[][] grid) {
    return helper(grid, 0, 0, grid.length);
  }

  private Node helper(int[][] grid, int i, int j, int w) {
    if (allSame(grid, i, j, w))
      return new Node(grid[i][j] == 1, /*isLeaf=*/true);
    final int half = w / 2;
    return new Node(/*val=*/true, /*isLeaf=*/false,
                    /*topLeft=*/helper(grid, i, j, half),
                    /*topRight=*/helper(grid, i, j + half, half),
                    /*bottomLeft=*/helper(grid, i + half, j, half),
                    /*bottomRight=*/helper(grid, i + half, j + half, half));
  }

  private boolean allSame(int[][] grid, int i, int j, int w) {
    for (int x = i; x < i + w; ++x)
      for (int y = j; y < j + w; ++y)
        if (grid[x][y] != grid[i][j])
          return false;
    return true;
  }
}
