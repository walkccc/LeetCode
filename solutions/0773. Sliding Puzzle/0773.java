class Solution {
  public int slidingPuzzle(int[][] board) {
    final int row = 2;
    final int col = 3;
    final int[][] dirs = new int[][] { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

    String start = "";
    String goal = "";
    int steps = 0;

    for (int i = 0; i < board.length; ++i)
      for (int j = 0; j < board[0].length; ++j) {
        start += (char) (board[i][j] + '0');
        goal += (char) ((i * col + j + 1) % (col * row) + '0');
      }

    if (start.equals(goal))
      return 0;

    Set<String> visited = new HashSet<>();
    visited.add(start);

    Queue<String> q = new LinkedList<>();
    q.add(start);

    while (!q.isEmpty()) {
      ++steps;
      for (int k = q.size(); k > 0; --k) {
        final String s = q.poll();
        final int p = s.indexOf("0");
        final int y = p / col;
        final int x = p % col;
        for (int i = 0; i < 4; ++i) {
          final int tx = x + dirs[i][0];
          final int ty = y + dirs[i][1];
          if (tx < 0 || ty < 0 || tx == col || ty == row)
            continue;
          final int loc = ty * col + tx;
          StringBuilder sb = new StringBuilder(s);
          sb.setCharAt(p, s.charAt(loc));
          sb.setCharAt(loc, s.charAt(p));
          final String t = sb.toString();
          if (visited.contains(t))
            continue;
          if (t.equals(goal))
            return steps;
          visited.add(t);
          q.add(t);
        }
      }
    }

    return -1;
  }
}