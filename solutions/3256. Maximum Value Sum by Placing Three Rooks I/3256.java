class Solution {
  public long maximumValueSum(int[][] board) {
    final int m = board.length;
    final int n = board[0].length;
    long ans = Long.MIN_VALUE;
    List<int[]>[] rows = new ArrayList[m];
    List<int[]>[] cols = new ArrayList[n];
    Set<int[]> rowSet = new HashSet<>();
    Set<int[]> colSet = new HashSet<>();
    Set<int[]> boardSet = new HashSet<>();

    for (int i = 0; i < m; ++i)
      rows[i] = new ArrayList<>();

    for (int j = 0; j < n; ++j)
      cols[j] = new ArrayList<>();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int[] cell = new int[] {board[i][j], i, j};
        rows[i].add(cell);
        cols[j].add(cell);
      }

    Comparator<int[]> comparator = (a, b) -> Integer.compare(b[0], a[0]);

    for (List<int[]> row : rows) {
      row.sort(comparator);
      rowSet.addAll(row.subList(0, Math.min(3, row.size())));
    }

    for (List<int[]> col : cols) {
      col.sort(comparator);
      colSet.addAll(col.subList(0, Math.min(3, col.size())));
    }

    boardSet.addAll(rowSet);
    boardSet.retainAll(colSet);

    // At least 9 positions are required on the board to place 3 rooks such that
    // none can attack another.
    List<int[]> topNine = new ArrayList<>(boardSet);
    topNine.sort(comparator);
    topNine = topNine.subList(0, Math.min(9, topNine.size()));

    for (int i = 0; i < topNine.size(); ++i)
      for (int j = i + 1; j < topNine.size(); ++j)
        for (int k = j + 1; k < topNine.size(); ++k) {
          int[] t1 = topNine.get(i);
          int[] t2 = topNine.get(j);
          int[] t3 = topNine.get(k);
          if (t1[1] == t2[1] || t1[1] == t3[1] || t2[1] == t3[1] || //
              t1[2] == t2[2] || t1[2] == t3[2] || t2[2] == t3[2])
            continue;
          ans = Math.max(ans, (long) t1[0] + t2[0] + t3[0]);
        }

    return ans;
  }
}
