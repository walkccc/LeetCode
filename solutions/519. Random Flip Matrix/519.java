class Solution {
  public Solution(int n_rows, int n_cols) {
    this.rows = n_rows;
    this.cols = n_cols;
    this.total = n_rows * n_cols;
  }

  public int[] flip() {
    // All the candidates are used out.
    if (used.size() == total)
      return new int[] {};
    int index = new Random().nextInt(total);
    while (used.contains(index))
      index = ++index % total;
    used.add(index);
    return new int[] {index / cols, index % cols};
  }

  public void reset() {
    used.clear();
  }

  private Set<Integer> used = new HashSet<>();
  private int rows;
  private int cols;
  private int total;
}
