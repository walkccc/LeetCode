class Solution {
  public int[] findPeakGrid(int[][] mat) {
    int l = 0;
    int r = mat.length - 1;

    while (l < r) {
      final int m = (l + r) / 2;
      if (Arrays.stream(mat[m]).max().getAsInt() >= Arrays.stream(mat[m + 1]).max().getAsInt())
        r = m;
      else
        l = m + 1;
    }

    return new int[] {l, getMaxIndex(mat[l])};
  }

  private int getMaxIndex(int[] A) {
    int[] res = {0, A[0]};
    for (int i = 1; i < A.length; ++i)
      if (A[i] > res[1])
        res = new int[] {i, A[i]};
    return res[0];
  }
}
