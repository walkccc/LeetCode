class Solution {
  public int minimizedMaximum(int n, int[] quantities) {
    int l = 1;
    int r = Arrays.stream(quantities).max().getAsInt();

    while (l < r) {
      final int m = (l + r) / 2;
      if (numOfStores(quantities, m) <= n)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private int numOfStores(int[] quantities, int m) {
    // Math.ceil(q / k)
    return Arrays.stream(quantities).reduce(0, (subtotal, q) -> subtotal + (q - 1) / m + 1);
  }
}
