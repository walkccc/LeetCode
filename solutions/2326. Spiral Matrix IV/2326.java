class Solution {
  public int[][] spiralMatrix(int m, int n, ListNode head) {
    final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int[][] ans = new int[m][n];
    Arrays.stream(ans).forEach(A -> Arrays.fill(A, -1));
    int x = 0; // the current x position
    int y = 0; // the current y position
    int d = 0;

    for (ListNode curr = head; curr != null; curr = curr.next) {
      ans[x][y] = curr.val;
      if (x + DIRS[d][0] < 0 || x + DIRS[d][0] == m || y + DIRS[d][1] < 0 || //
          y + DIRS[d][1] == n || ans[x + DIRS[d][0]][y + DIRS[d][1]] != -1)
        d = (d + 1) % 4;
      x += DIRS[d][0];
      y += DIRS[d][1];
    }

    return ans;
  }
}
