class Solution {
  public int[] kWeakestRows(int[][] mat, int k) {
    int[] ans = new int[k];
    Pair<Integer, Integer>[] rowSums = new Pair[mat.length];

    for (int i = 0; i < mat.length; ++i)
      rowSums[i] = new Pair<>(Arrays.stream(mat[i]).sum(), i);

    Arrays.sort(rowSums,
                (a, b)
                    -> a.getKey().equals(b.getKey()) ? a.getValue().compareTo(b.getValue())
                                                     : a.getKey().compareTo(b.getKey()));

    for (int i = 0; i < k; ++i)
      ans[i] = rowSums[i].getValue();

    return ans;
  }
}
