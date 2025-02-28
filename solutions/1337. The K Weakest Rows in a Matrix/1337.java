class Solution {
  public int[] kWeakestRows(int[][] mat, int k) {
    int[] ans = new int[k];
    Pair<Integer, Integer>[] rowSums = new Pair[mat.length];

    for (int i = 0; i < mat.length; ++i)
      rowSums[i] = new Pair<>(Arrays.stream(mat[i]).sum(), i);

    Arrays.sort(rowSums, Comparator.comparing(Pair<Integer, Integer>::getKey)
                             .thenComparing(Pair<Integer, Integer>::getValue));

    for (int i = 0; i < k; ++i)
      ans[i] = rowSums[i].getValue();

    return ans;
  }
}
