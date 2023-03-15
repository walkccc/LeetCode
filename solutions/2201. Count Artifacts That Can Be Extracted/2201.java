class Solution {
  public int digArtifacts(int n, int[][] artifacts, int[][] dig) {
    Set<Integer> digged = new HashSet<>();

    for (int[] d : dig)
      digged.add(hash(d[0], d[1]));

    return (int) Arrays.stream(artifacts).filter(a -> canExtract(a, digged)).count();
  }

  private int hash(int i, int j) {
    return i << 16 | j;
  }

  private boolean canExtract(int[] a, Set<Integer> digged) {
    for (int i = a[0]; i <= a[2]; ++i)
      for (int j = a[1]; j <= a[3]; ++j)
        if (!digged.contains(hash(i, j)))
          return false;
    return true;
  }
}
