class Solution {
  public Node construct(int[][] grid) {
    return helper(grid, 0, 0, grid.length);
  }

  private Node helper(int[][] grid, int i, int j, int w) {
    if (allSame(grid, i, j, w))
      return new Node(grid[i][j] == 1 ? true : false, true);

    Node node = new Node(true, false);
    node.topLeft = helper(grid, i, j, w / 2);
    node.topRight = helper(grid, i, j + w / 2, w / 2);
    node.bottomLeft = helper(grid, i + w / 2, j, w / 2);
    node.bottomRight = helper(grid, i + w / 2, j + w / 2, w / 2);
    return node;
  }

  private boolean allSame(int[][] grid, int i, int j, int w) {
    for (int x = i; x < i + w; ++x)
      for (int y = j; y < j + w; ++y)
        if (grid[x][y] != grid[i][j])
          return false;
    return true;
  }
}
