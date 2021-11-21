class Solution {
  public int minimizedMaximum(int n, int[] quantities) {
    int l = 1;
    int r = Arrays.stream(quantities).max().getAsInt();

    while (l < r) {
      final int m = l + (r - l) / 2;
      if (numOfStores(quantities, m) <= n)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private int numOfStores(int[] quantities, int k) {
    int nStores = 0;
    for (final int q : quantities)
      nStores += (q - 1) / k + 1; // Math.ceil(q / k)
    return nStores;
  }
}
