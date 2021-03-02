class Solution {
  public void wallsAndGates(int[][] rooms) {
    for (int i = 0; i < rooms.length; ++i)
      for (int j = 0; j < rooms[0].length; ++j)
        if (rooms[i][j] == 0)
          dfs(rooms, i, j, 0);
  }

  private void dfs(int[][] rooms, int i, int j, int distance) {
    if (i < 0 || i == rooms.length || j < 0 || j == rooms[0].length)
      return;
    if (rooms[i][j] < distance)
      return;

    rooms[i][j] = distance;
    dfs(rooms, i + 1, j, distance + 1);
    dfs(rooms, i - 1, j, distance + 1);
    dfs(rooms, i, j + 1, distance + 1);
    dfs(rooms, i, j - 1, distance + 1);
  }
}
