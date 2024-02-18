class Solution {
  public double maxPrice(int[][] items, int capacity) {
    double ans = 0;

    // Sort items based on price/weight.
    Arrays.sort(items, new Comparator<int[]>() {
      @Override
      public int compare(int[] a, int[] b) {
        return Double.compare((double) b[0] / b[1], (double) a[0] / a[1]);
      }
    });

    for (int[] item : items) {
      final int price = item[0];
      final int weight = item[1];
      // The bag is filled.
      if (capacity <= weight)
        return ans + price * capacity / (double) weight;
      ans += price;
      capacity -= weight;
    }

    return -1;
  }
}
