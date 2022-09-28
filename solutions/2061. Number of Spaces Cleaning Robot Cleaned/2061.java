class Solution {
  public int numberOfCleanRooms(int[][] room) {
    final int m = room.length;
    final int n = room[0].length;
    final int[] dirs = {0, 1, 0, -1, 0};
    int ans = 1;
    int i = 0;
    int j = 0;
    int state = 0;                // 0 := right, 1 := down, 2 := left, 3 := up
    int[][] seen = new int[m][n]; // seen[i][j] := bitmask
    seen[i][j] |= 1 << state;
    room[i][j] = 2; // 2 := cleaned

    while (true) {
      final int x = i + dirs[state];
      final int y = j + dirs[state + 1];
      if (x < 0 || x == m || y < 0 || y == n || room[x][y] == 1) {
        // turns 90 degrees clockwise
        state = (state + 1) % 4;
      } else {
        // walk to (x, y)
        if (room[x][y] == 0) {
          ++ans;
          room[x][y] = 2;
        }
        i = x;
        j = y;
      }
      if (((seen[i][j] >> state) & 1) == 1)
        return ans;
      seen[i][j] |= (1 << state);
    }
  }
}
