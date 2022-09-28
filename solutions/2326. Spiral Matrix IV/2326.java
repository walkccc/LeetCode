class Solution {
  public int[][] spiralMatrix(int m, int n, ListNode head) {
    final int[] dirs = {0, 1, 0, -1, 0};
    int[][] ans = new int[m][n];
    Arrays.stream(ans).forEach(A -> Arrays.fill(A, -1));
    int x = 0; // current x position
    int y = 0; // current y position
    int d = 0;

    for (ListNode curr = head; curr != null; curr = curr.next) {
      ans[x][y] = curr.val;
      if (x + dirs[d] < 0 || x + dirs[d] == m || y + dirs[d + 1] < 0 || y + dirs[d + 1] == n ||
          ans[x + dirs[d]][y + dirs[d + 1]] != -1)
        d = (d + 1) % 4;
      x += dirs[d];
      y += dirs[d + 1];
    }

    return ans;
  }
}
