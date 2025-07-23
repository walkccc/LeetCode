class Matrix3D {
  public Matrix3D(int n) {
    isSet = new boolean[n][n][n];
    count = new int[n];
    for (int x = 0; x < n; ++x)
      pairs.add(new Pair<>(0, x));
  }

  public void setCell(int x, int y, int z) {
    if (isSet[x][y][z])
      return;
    isSet[x][y][z] = true;
    pairs.remove(new Pair<>(count[x], x));
    pairs.add(new Pair<>(++count[x], x));
  }

  public void unsetCell(int x, int y, int z) {
    if (!isSet[x][y][z])
      return;
    isSet[x][y][z] = false;
    pairs.remove(new Pair<>(count[x], x));
    pairs.add(new Pair<>(--count[x], x));
  }

  public int largestMatrix() {
    return pairs.first().getValue();
  }

  private boolean[][][] isSet;
  private int[] count; // count[x] := the number of cells set in the x-th layer
  private TreeSet<Pair<Integer, Integer>> pairs = new TreeSet<>( // (count[x], x)
      Comparator.comparing(Pair<Integer, Integer>::getKey, Comparator.reverseOrder())
          .thenComparing(Pair<Integer, Integer>::getValue, Comparator.reverseOrder()));
}
