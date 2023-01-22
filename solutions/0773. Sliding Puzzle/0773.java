class Solution {
  public int slidingPuzzle(int[][] board) {
    final int m = 2;
    final int n = 3;
    final int[] dirs = {0, 1, 0, -1, 0};
    final String goal = "123450";
    int steps = 0;
    StringBuilder startSb = new StringBuilder();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        startSb.append((char) ('0' + board[i][j]));

    final String start = startSb.toString();

    if (start.equals(goal))
      return 0;

    Queue<String> q = new ArrayDeque<>(Arrays.asList(start));
    Set<String> seen = new HashSet<>(Arrays.asList(start));

    while (!q.isEmpty()) {
      ++steps;
      for (int sz = q.size(); sz > 0; --sz) {
        final String s = q.poll();
        final int zeroIndex = s.indexOf("0");
        final int i = zeroIndex / n;
        final int j = zeroIndex % n;
        for (int k = 0; k < 4; ++k) {
          final int x = i + dirs[k];
          final int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          final int swappedIndex = x * n + y;
          StringBuilder sb = new StringBuilder(s);
          sb.setCharAt(zeroIndex, s.charAt(swappedIndex));
          sb.setCharAt(swappedIndex, s.charAt(zeroIndex));
          final String t = sb.toString();
          if (t.equals(goal))
            return steps;
          if (!seen.contains(t)) {
            q.offer(t);
            seen.add(t);
          }
        }
      }
    }

    return -1;
  }
}
