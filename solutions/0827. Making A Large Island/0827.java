class Solution {
  public int largestIsland(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int maxSize = 0;
    // sizes[i] := size of i-th connected component (start from 2)
    List<Integer> sizes = new ArrayList<>(Arrays.asList(0, 0));

    // For each 1 in the grid, paint all connected 1 with the next available
    // color (2, 3, and so on). Also, remember the size of the island we just
    // painted with that color.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) {
          sizes.add(paint(grid, i, j, sizes.size())); // paint 2, 3, ...
        }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0) {
          Set<Integer> neighborIds =
              new HashSet<>(Arrays.asList(getId(grid, i - 1, j), getId(grid, i + 1, j),
                                          getId(grid, i, j + 1), getId(grid, i, j - 1)));
          maxSize = Math.max(maxSize, 1 + getSize(grid, neighborIds, sizes));
        }

    return maxSize == 0 ? m * n : maxSize;
  }

  private int paint(int[][] grid, int i, int j, int id) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return 0;
    if (grid[i][j] != 1)
      return 0;

    grid[i][j] = id; // grid[i][j] is part of id-th connected component

    return 1 + paint(grid, i + 1, j, id) + paint(grid, i - 1, j, id) + paint(grid, i, j + 1, id) +
        paint(grid, i, j - 1, id);
  }

  // get the id of grid[i][j], return 0 if out of bound
  private int getId(int[][] grid, int i, int j) {
    if (i < 0 || i == grid.length || j < 0 || j == grid[0].length)
      return 0; // invalid
    return grid[i][j];
  }

  private int getSize(int[][] grid, Set<Integer> neighborIds, List<Integer> sizes) {
    int size = 0;
    for (final int neighborId : neighborIds)
      size += sizes.get(neighborId);
    return size;
  }
}
