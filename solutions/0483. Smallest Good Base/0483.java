class Solution {
  public String smallestGoodBase(String n) {
    long num = Long.valueOf(n);

    for (int m = (int) (Math.log(num) / Math.log(2)); m >= 2; --m) {
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