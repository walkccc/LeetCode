class Solution {
  public int oddCells(int m, int n, int[][] indices) {
    // rows[i] and cols[i] :=
    //   true (flipped even times) / false (flipped odd times)
    boolean[] rows = new boolean[n];
    boolean[] cols = new boolean[n];

    for (int[] index : indices) {
      rows[index[0]] = rows[index[0]] ^ true;
      cols[index[1]] = cols[index[1]] ^ true;
    }

    int oddRowsCount = 0;
    int oddColsCount = 0;

    for (boolean row : rows)
      if (row)
        ++oddRowsCount;

    for (boolean col : cols)
      if (col)
        ++oddColsCount;

    final int evenRowsCount = m - oddRowsCount;
    final int evenColsCount = n - oddColsCount;
    return oddRowsCount * evenColsCount + oddColsCount * evenRowsCount;
  }
}
