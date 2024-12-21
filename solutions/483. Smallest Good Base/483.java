class Solution {
  public String smallestGoodBase(String n) {
    final long num = Long.parseLong(n);
    final int log2 = (int) (Math.log(num) / Math.log(2));

    for (int m = log2; m >= 2; --m) {
      int k = (int) Math.floor(Math.pow(num, 1.0 / m));
      long sum = 1;
      long prod = 1;
      for (int i = 0; i < m; ++i) {
        prod *= k;
        sum += prod;
      }
      if (sum == num)
        return String.valueOf(k);
    }

    return String.valueOf(num - 1);
  }
}
