class SubrectangleQueries {
  public SubrectangleQueries(int[][] rectangle) {
    this.rectangle = rectangle;
  }

  public void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
    updates.add(new int[] {row1, col1, row2, col2, newValue});
  }

  public int getValue(int row, int col) {
    for (int i = updates.size() - 1; i >= 0; --i) {
      int[] update = updates.get(i);
      final int r1 = update[0];
      final int c1 = update[1];
      final int r2 = update[2];
      final int c2 = update[3];
      final int v = update[4];
      if (r1 <= row && row <= r2 && c1 <= col && col <= c2)
        return v;
    }
    return rectangle[row][col];
  }

  private int[][] rectangle;
  private List<int[]> updates = new ArrayList<>(); // [r1, c1, r2, c2, v]
}
